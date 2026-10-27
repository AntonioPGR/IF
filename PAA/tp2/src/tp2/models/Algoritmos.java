package tp2.models;

import tp2.enums.TipoDeRepresentacao;
import tp2.interfaces.IGrafo;
import tp2.interfaces.IAlgoritmos;
import tp2.managers.TerminalManager;

import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;

public class Algoritmos implements IAlgoritmos {

	@Override
	public IGrafo carregarGrafo(String path, TipoDeRepresentacao t) throws Exception {
		Grafo grafo = new Grafo(t);
		ArrayList<String> linhas = new ArrayList<>(Files.readAllLines(Path.of(path)));
		if (linhas.isEmpty()) throw new IllegalArgumentException("O arquivo de entrada está vazio.");
		for (int i = 1; i < linhas.size(); i++) {
			String linha = linhas.get(i).trim();
			if (linha.isEmpty()) continue;
			String[] partes = linha.split("\\s+");
			int origemId = Integer.parseInt(partes[0]);
			grafo.adicionarVerticeSeNaoExiste(new Vertice(origemId));
			for (int j = 1; j < partes.length; j++) {
				String[] aresta = partes[j].replace(";", "").split("-", 2);
				int destinoId = Integer.parseInt(aresta[0]);
				double peso = Double.parseDouble(aresta[1]);
				grafo.adicionarVerticeSeNaoExiste(new Vertice(destinoId));
				grafo.adicionarAresta(grafo.getVertice(origemId), grafo.getVertice(destinoId), peso);
			}
		}
		return grafo;
	}

	@Override
	public Collection<Aresta> buscaEmProfundidade(IGrafo g) {
		g.resetarVertices();
		Vertice start = TerminalManager.lerVertice(g, "Digite o vértice inicial: ");
		List<Aresta> arestasArvore = new ArrayList<>();
		int[] tempo = new int[]{0};

		try {
			dfsVisitar(g, start, tempo, arestasArvore);
			for (Vertice v : g.vertices()) {
				if (!v.isVisitado()) {
					dfsVisitar(g, v, tempo, arestasArvore);
				}
			}
		} catch (Exception e) {
			TerminalManager.printLn("Erro na busca em profundidade: " + e.getMessage());
		}

		TerminalManager.printLn("Busca em Profundidade (DFS):");
		for (Vertice v : g.vertices()) {
			TerminalManager.printLn("Vértice " + v.id() + " - Tempo de Descoberta: " + v.getTempoDescoberta() + ", Tempo de Finalização: " + v.getTempoFinalizacao());
		}
		return arestasArvore;
	}

	private void dfsVisitar(IGrafo g, Vertice u, int[] tempo, List<Aresta> arestasArvore) throws Exception {
		u.setVisitado(true);
		u.setTempoDescoberta(++tempo[0]);
		for (Vertice v : g.adjacentesDe(u)) {
			if (!v.isVisitado()) {
				ArrayList<Aresta> arestas = g.arestasEntre(u, v);
				if (!arestas.isEmpty()) {
					arestasArvore.add(arestas.get(0));
				}
				dfsVisitar(g, v, tempo, arestasArvore);
			}
		}
		u.setTempoFinalizacao(++tempo[0]);
	}

	@Override
	public Collection<Aresta> buscaEmLargura(IGrafo g) {
		g.resetarVertices();
		Vertice start = TerminalManager.lerVertice(g, "Digite o vértice inicial: ");
		Queue<Vertice> queue = new LinkedList<>();
		List<Aresta> arestasArvore = new ArrayList<>();
		int tempo = 0;

		start.setVisitado(true);
		start.setTempoDescoberta(++tempo);
		queue.add(start);

		while (!queue.isEmpty()) {
			Vertice atual = queue.poll();
			try {
				for (Vertice v : g.adjacentesDe(atual)) {
					if (!v.isVisitado()) {
						v.setVisitado(true);
						v.setTempoDescoberta(++tempo);
						ArrayList<Aresta> arestas = g.arestasEntre(atual, v);
						if (!arestas.isEmpty()) {
							arestasArvore.add(arestas.get(0));
						}
						queue.add(v);
					}
				}
			} catch (Exception e) {
				TerminalManager.printLn("Erro na busca em largura: " + e.getMessage());
			}
			atual.setTempoFinalizacao(++tempo);
		}

		TerminalManager.printLn("Busca em Largura (BFS):");
		for (Vertice v : g.vertices()) {
			TerminalManager.printLn("Vértice " + v.id() + " - Tempo de Descoberta: " + v.getTempoDescoberta() + ", Tempo de Finalização: " + v.getTempoFinalizacao());
		}
		return arestasArvore;
	}

	@Override
	public boolean existeCiclo(IGrafo g) {
		Map<Integer, Integer> estado = new HashMap<>(); // 0: branco (não visitado), 1: cinza (em visitação), 2: preto (visitado)
		for (Vertice v : g.vertices()) {
			estado.put(v.id(), 0);
		}
		boolean temCiclo = false;
		try {
			for (Vertice v : g.vertices()) {
				if (estado.get(v.id()) == 0) {
					if (dfsCiclo(g, v, estado)) {
						temCiclo = true;
						break;
					}
				}
			}
		} catch (Exception e) {
			TerminalManager.printLn("Erro ao verificar ciclos: " + e.getMessage());
		}
		TerminalManager.printLn("Existe ciclo: " + temCiclo);
		return temCiclo;
	}

	private boolean dfsCiclo(IGrafo g, Vertice u, Map<Integer, Integer> estado) throws Exception {
		estado.put(u.id(), 1);
		for (Vertice v : g.adjacentesDe(u)) {
			int estadoV = estado.getOrDefault(v.id(), 0);
			if (estadoV == 1) {
				return true;
			}
			if (estadoV == 0) {
				if (dfsCiclo(g, v, estado)) {
					return true;
				}
			}
		}
		estado.put(u.id(), 2);
		return false;
	}

	@Override
	public IGrafo componentesFortementeConexos(IGrafo g) {
		Map<Integer, Integer> indices = new HashMap<>();
		Map<Integer, Integer> lowlinks = new HashMap<>();
		Map<Integer, Boolean> onStack = new HashMap<>();
		Stack<Vertice> stack = new Stack<>();
		List<List<Vertice>> sccs = new ArrayList<>();
		int[] indexCounter = new int[]{0};

		for (Vertice v : g.vertices()) {
			indices.put(v.id(), -1);
			lowlinks.put(v.id(), -1);
			onStack.put(v.id(), false);
		}

		try {
			for (Vertice v : g.vertices()) {
				if (indices.get(v.id()) == -1) {
					tarjanStrongConnect(g, v, indices, lowlinks, onStack, stack, sccs, indexCounter);
				}
			}
		} catch (Exception e) {
			TerminalManager.printLn("Erro no algoritmo de Tarjan: " + e.getMessage());
		}

		TerminalManager.printLn("Componentes Fortemente Conexos (Tarjan):");
		for (int i = 0; i < sccs.size(); i++) {
			StringBuilder sb = new StringBuilder();
			sb.append("Componente ").append(i).append(": [");
			List<Vertice> scc = sccs.get(i);
			for (int j = 0; j < scc.size(); j++) {
				sb.append(scc.get(j).id());
				if (j < scc.size() - 1) sb.append(", ");
			}
			sb.append("]");
			TerminalManager.printLn(sb.toString());
		}

		Grafo grafoReduzido = new Grafo();
		Map<Integer, Integer> verticeParaComponente = new HashMap<>();
		for (int i = 0; i < sccs.size(); i++) {
			grafoReduzido.adicionarVerticeSeNaoExiste(new Vertice(i));
			for (Vertice v : sccs.get(i)) {
				verticeParaComponente.put(v.id(), i);
			}
		}

		try {
			for (Vertice u : g.vertices()) {
				int compU = verticeParaComponente.get(u.id());
				for (Vertice v : g.adjacentesDe(u)) {
					int compV = verticeParaComponente.get(v.id());
					if (compU != compV) {
						Vertice cu = grafoReduzido.getVertice(compU);
						Vertice cv = grafoReduzido.getVertice(compV);
						if (!grafoReduzido.existeAresta(cu, cv)) {
							grafoReduzido.adicionarAresta(cu, cv, 1.0);
						}
					}
				}
			}
		} catch (Exception e) {
			TerminalManager.printLn("Erro ao construir grafo reduzido: " + e.getMessage());
		}

		TerminalManager.printLn("Estrutura do Grafo Reduzido:");
		TerminalManager.printLn("Número de componentes (vértices): " + grafoReduzido.numeroDeVertices());
		TerminalManager.printLn("Número de conexões entre componentes (arestas): " + grafoReduzido.numeroDeArestas());
		for (Vertice comp : grafoReduzido.vertices()) {
			try {
				ArrayList<Vertice> adjs = grafoReduzido.adjacentesDe(comp);
				StringBuilder sb = new StringBuilder();
				sb.append("Componente ").append(comp.id()).append(" -> ");
				for (int j = 0; j < adjs.size(); j++) {
					sb.append("Componente ").append(adjs.get(j).id());
					if (j < adjs.size() - 1) sb.append(", ");
				}
				TerminalManager.printLn(sb.toString());
			} catch (Exception ignored) {}
		}

		return grafoReduzido;
	}

	private void tarjanStrongConnect(IGrafo g, Vertice u, Map<Integer, Integer> indices,
									 Map<Integer, Integer> lowlinks, Map<Integer, Boolean> onStack,
									 Stack<Vertice> stack, List<List<Vertice>> sccs, int[] indexCounter) throws Exception {
		indices.put(u.id(), indexCounter[0]);
		lowlinks.put(u.id(), indexCounter[0]);
		indexCounter[0]++;
		stack.push(u);
		onStack.put(u.id(), true);

		for (Vertice v : g.adjacentesDe(u)) {
			if (indices.get(v.id()) == -1) {
				tarjanStrongConnect(g, v, indices, lowlinks, onStack, stack, sccs, indexCounter);
				lowlinks.put(u.id(), Math.min(lowlinks.get(u.id()), lowlinks.get(v.id())));
			} else if (onStack.get(v.id())) {
				lowlinks.put(u.id(), Math.min(lowlinks.get(u.id()), indices.get(v.id())));
			}
		}

		if (lowlinks.get(u.id()).equals(indices.get(u.id()))) {
			List<Vertice> scc = new ArrayList<>();
			Vertice w;
			do {
				w = stack.pop();
				onStack.put(w.id(), false);
				scc.add(w);
			} while (w.id() != u.id());
			sccs.add(scc);
		}
	}

	@Override
	public Collection<Aresta> arvoreGeradoraMinima(IGrafo g) {
		List<Aresta> todasArestas = new ArrayList<>();
		try {
			for (Vertice u : g.vertices()) {
				for (Vertice v : g.adjacentesDe(u)) {
					todasArestas.addAll(g.arestasEntre(u, v));
				}
			}
		} catch (Exception e) {
			TerminalManager.printLn("Erro ao coletar arestas: " + e.getMessage());
		}

		todasArestas.sort(Comparator.comparingDouble(Aresta::peso));

		Map<Integer, Integer> parent = new HashMap<>();
		for (Vertice v : g.vertices()) {
			parent.put(v.id(), v.id());
		}

		List<Aresta> mst = new ArrayList<>();
		for (Aresta a : todasArestas) {
			int rootU = find(parent, a.origem().id());
			int rootV = find(parent, a.destino().id());
			if (rootU != rootV) {
				parent.put(rootU, rootV);
				mst.add(a);
			}
		}

		double custo = 0;
		try {
			custo = custoDaArvoreGeradora(g, mst);
		} catch (Exception e) {
			custo = mst.stream().mapToDouble(Aresta::peso).sum();
		}

		TerminalManager.printLn("Árvore Geradora Mínima (Kruskal):");
		TerminalManager.printLn("Arestas da AGM:");
		for (Aresta a : mst) {
			TerminalManager.printLn("\t" + a.origem().id() + " -> " + a.destino().id() + " (peso: " + a.peso() + ")");
		}
		TerminalManager.printLn("Custo da Árvore Geradora Mínima: " + custo);
		return mst;
	}

	private int find(Map<Integer, Integer> parent, int i) {
		if (parent.get(i) == i) return i;
		int root = find(parent, parent.get(i));
		parent.put(i, root);
		return root;
	}

	@Override
	public double custoDaArvoreGeradora(IGrafo g, Collection<Aresta> arestas) throws Exception {
		double total = 0;
		if (arestas != null) {
			for (Aresta a : arestas) {
				total += a.peso();
			}
		}
		return total;
	}

	@Override
	public ArrayList<Aresta> caminhoMinimo(IGrafo g) {
		Vertice origem = TerminalManager.lerVertice(g, "Digite o vértice de origem: ");
		Vertice destino = TerminalManager.lerVertice(g, "Digite o vértice de destino: ");
		return caminhoMinimo(g, origem, destino);
	}

	@Override
	public ArrayList<Aresta> caminhoMinimo(IGrafo g, Vertice origem, Vertice destino) {
		Map<Integer, Double> dist = new HashMap<>();
		Map<Integer, Aresta> arestaPai = new HashMap<>();
		for (Vertice v : g.vertices()) {
			dist.put(v.id(), Double.POSITIVE_INFINITY);
		}
		dist.put(origem.id(), 0.0);

		PriorityQueue<Vertice> pq = new PriorityQueue<>(Comparator.comparingDouble(v -> dist.get(v.id())));
		pq.add(origem);

		try {
			while (!pq.isEmpty()) {
				Vertice u = pq.poll();
				if (u.id() == destino.id()) break;

				double dU = dist.get(u.id());
				if (dU == Double.POSITIVE_INFINITY) break;

				for (Vertice v : g.adjacentesDe(u)) {
					for (Aresta a : g.arestasEntre(u, v)) {
						double novaDist = dU + a.peso();
						if (novaDist < dist.get(v.id())) {
							dist.put(v.id(), novaDist);
							arestaPai.put(v.id(), a);
							pq.remove(v);
							pq.add(v);
						}
					}
				}
			}
		} catch (Exception e) {
			TerminalManager.printLn("Erro ao executar Dijkstra: " + e.getMessage());
		}

		ArrayList<Aresta> caminho = new ArrayList<>();
		Vertice curr = destino;
		while (arestaPai.containsKey(curr.id())) {
			Aresta a = arestaPai.get(curr.id());
			caminho.add(0, a);
			curr = a.origem();
		}

		boolean existeCaminho = (origem.id() == destino.id()) || (!caminho.isEmpty() && curr.id() == origem.id());

		TerminalManager.printLn("Caminho Mínimo (Dijkstra) de " + origem.id() + " para " + destino.id() + ":");
		if (existeCaminho) {
			double custo = 0;
			try {
				custo = custoDoCaminhoMinimo(g, caminho, origem, destino);
			} catch (Exception e) {
				custo = caminho.stream().mapToDouble(Aresta::peso).sum();
			}

			if (caminho.isEmpty()) {
				TerminalManager.printLn("Origem e destino são iguais (" + origem.id() + "). Custo: 0.0");
			} else {
				StringBuilder sb = new StringBuilder();
				sb.append("Caminho: ").append(origem.id());
				for (Aresta a : caminho) {
					sb.append(" -> ").append(a.destino().id());
				}
				TerminalManager.printLn(sb.toString());
				TerminalManager.printLn("Arestas:");
				for (Aresta a : caminho) {
					TerminalManager.printLn("\t" + a.origem().id() + " -> " + a.destino().id() + " (peso: " + a.peso() + ")");
				}
				TerminalManager.printLn("Custo total: " + custo);
			}
		} else {
			TerminalManager.printLn("Não foi encontrado caminho entre o vértice " + origem.id() + " e o vértice " + destino.id() + ".");
		}

		return caminho;
	}

	@Override
	public double custoDoCaminhoMinimo(IGrafo g, ArrayList<Aresta> arestas, Vertice origem, Vertice destino) throws Exception {
		double total = 0;
		if (arestas != null) {
			for (Aresta a : arestas) {
				total += a.peso();
			}
		}
		return total;
	}

	@Override
	public double fluxoMaximo(IGrafo g) {
		Vertice origem = TerminalManager.lerVertice(g, "Digite o vértice de origem (fonte): ");
		Vertice destino = TerminalManager.lerVertice(g, "Digite o vértice de destino (sumidouro): ");

		Map<Integer, Map<Integer, Double>> capacidade = new HashMap<>();
		for (Vertice u : g.vertices()) {
			capacidade.put(u.id(), new HashMap<>());
		}

		try {
			for (Vertice u : g.vertices()) {
				for (Vertice v : g.adjacentesDe(u)) {
					for (Aresta a : g.arestasEntre(u, v)) {
						int uid = u.id();
						int vid = v.id();
						capacidade.get(uid).put(vid, capacidade.get(uid).getOrDefault(vid, 0.0) + a.peso());
						if (!capacidade.get(vid).containsKey(uid)) {
							capacidade.get(vid).put(uid, 0.0);
						}
					}
				}
			}
		} catch (Exception e) {
			TerminalManager.printLn("Erro ao inicializar capacidades da rede de fluxo: " + e.getMessage());
		}

		double fluxoMaximo = 0;
		int s = origem.id();
		int t = destino.id();

		while (true) {
			Map<Integer, Integer> pai = new HashMap<>();
			Queue<Integer> fila = new LinkedList<>();
			fila.add(s);
			pai.put(s, s);

			while (!fila.isEmpty() && !pai.containsKey(t)) {
				int u = fila.poll();
				Map<Integer, Double> vizinhos = capacidade.getOrDefault(u, Collections.emptyMap());
				for (Map.Entry<Integer, Double> entry : vizinhos.entrySet()) {
					int v = entry.getKey();
					double capResidual = entry.getValue();
					if (capResidual > 1e-9 && !pai.containsKey(v)) {
						pai.put(v, u);
						fila.add(v);
					}
				}
			}

			if (!pai.containsKey(t)) {
				break;
			}

			double gargalo = Double.POSITIVE_INFINITY;
			int curr = t;
			while (curr != s) {
				int prev = pai.get(curr);
				gargalo = Math.min(gargalo, capacidade.get(prev).get(curr));
				curr = prev;
			}

			curr = t;
			while (curr != s) {
				int prev = pai.get(curr);
				capacidade.get(prev).put(curr, capacidade.get(prev).get(curr) - gargalo);
				capacidade.get(curr).put(prev, capacidade.get(curr).get(prev) + gargalo);
				curr = prev;
			}

			fluxoMaximo += gargalo;
		}

		TerminalManager.printLn("Fluxo Máximo (Ford-Fulkerson) de " + origem.id() + " para " + destino.id() + ": " + fluxoMaximo);
		return fluxoMaximo;
	}

	// ???????????????????????????????????????????????????????????????????????????????????????????????????????????????????
	@Override
	public Collection<Aresta> arestasDeArvore(IGrafo g) {
		return List.of();
	}

	@Override
	public Collection<Aresta> arestasDeRetorno(IGrafo g) {
		return List.of();
	}

	@Override
	public Collection<Aresta> arestasDeAvanco(IGrafo g) {
		return List.of();
	}

	@Override
	public Collection<Aresta> arestasDeCruzamento(IGrafo g) {
		return List.of();
	}

}
