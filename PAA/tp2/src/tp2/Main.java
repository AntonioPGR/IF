package tp2;

import tp2.enums.TipoDeRepresentacao;
import tp2.managers.TerminalManager;
import tp2.models.Algoritmos;
import tp2.models.Aresta;
import tp2.models.Grafo;
import tp2.models.Vertice;

import java.util.ArrayList;
import java.nio.file.Files;
import java.nio.file.Path;

public class Main {

    static final String CAMINHO_ENTRADA = "src/tp2/files/input.txt";

    static final Algoritmos algoritmos = new Algoritmos();

    static void main(String[] args) throws Exception {
        TipoDeRepresentacao tipo = escolherRepresentacao();
        Grafo grafo = carregarGrafo(CAMINHO_ENTRADA, tipo);
        menuDeAlgoritmos(grafo, tipo);
        TerminalManager.printLn("Encerrando.");
    }

    static TipoDeRepresentacao escolherRepresentacao() {
        TipoDeRepresentacao[] tipos = TipoDeRepresentacao.values();
        TerminalManager.printLn("=== TP2 - Algoritmos em Grafos ===");
        TerminalManager.printLn();
        TerminalManager.printLn("Escolha a representação do grafo:");
        for (int i = 0; i < tipos.length; i++) TerminalManager.printLn("\t" + (i + 1) + " - " + tipos[i]);
        TerminalManager.printLn("\t0 - Sair");
        int opcao = TerminalManager.lerInteiro("Opção: ", 0, tipos.length);
        return opcao == 0 ? null : tipos[opcao - 1];
    }


    static Grafo carregarGrafo(String caminho, TipoDeRepresentacao tipo) throws Exception {
        Grafo grafo = new Grafo(tipo);
        ArrayList<String> linhas = new ArrayList<>(Files.readAllLines(Path.of(caminho)));
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


    static void menuDeAlgoritmos(Grafo grafo, TipoDeRepresentacao tipo) {
        while (true) {
            TerminalManager.printLn("=== TP2 - Algoritmos em Grafos ===\nGrafo: " + CAMINHO_ENTRADA + " | " + tipo + " | " + grafo.numeroDeVertices() + " vértices, " + grafo.numeroDeArestas() + " arestas\n\nEscolha o algoritmo:\n\t1 - Busca em profundidade\n\t2 - Arestas de árvore\n\t3 - Arestas de retorno\n\t4 - Arestas de avanço\n\t5 - Arestas de cruzamento\n\t6 - Busca em largura\n\t7 - Existe ciclo\n\t8 - Componentes fortemente conexos\n\t9 - Árvore geradora mínima (e custo)\n\t10 - Caminho mínimo (e custo)\n\t11 - Fluxo máximo\n\t0 - Sair");
            int opcao = TerminalManager.lerInteiro("Opção: ", 0, 11);
            if (opcao == 0) return;
            try {
                TerminalManager.printLn();
                switch (opcao) {
                    case 1: algoritmos.buscaEmProfundidade(grafo);
                        break;
                    case 2: algoritmos.arestasDeArvore(grafo);
                        break;
                    case 3: algoritmos.arestasDeRetorno(grafo);
                        break;
                    case 4: algoritmos.arestasDeAvanco(grafo);
                        break;
                    case 5: algoritmos.arestasDeCruzamento(grafo);
                        break;
                    case 6: algoritmos.buscaEmLargura(grafo);
                        break;
                    case 7: algoritmos.existeCiclo(grafo);
                        break;
                    case 8: algoritmos.componentesFortementeConexos(grafo);
                        break;
                    case 9: algoritmos.arvoreGeradoraMinima(grafo);
                        break;
                    case 10: algoritmos.caminhoMinimo(grafo);
                        break;
                    case 11: algoritmos.fluxoMaximo(grafo);
                        break;
                    default: throw new IllegalArgumentException("Opção inválida.");
                }
            } catch (Exception e) {
                TerminalManager.printLn("Erro ao executar o algoritmo: " + e.getMessage());
            }
        }
    }

}
