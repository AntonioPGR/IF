package tp2.models;

import tp2.enums.TipoDeRepresentacao;
import tp2.interfaces.IGrafo;

import java.util.ArrayList;

public class Grafo implements IGrafo {
    private final TipoDeRepresentacao tipoDeRepresentacao;
    private final ArrayList<Vertice> vertices = new ArrayList<>();
    private final ArrayList<ArrayList<Aresta>> listaDeAdjacencia;
    private final ArrayList<ArrayList<ArrayList<Aresta>>> matrizDeAdjacencia;
    private final ArrayList<ArrayList<Integer>> matrizDeIncidencia;
    private final ArrayList<Aresta> arestasDeIncidencia;

    public Grafo() {
        this(TipoDeRepresentacao.LISTA_DE_ADJACENCIA);
    }

    public Grafo(TipoDeRepresentacao tipoDeRepresentacao) {
        if (tipoDeRepresentacao == null) {
            throw new IllegalArgumentException("O tipo de representação não pode ser nulo.");
        }

        this.tipoDeRepresentacao = tipoDeRepresentacao;
        listaDeAdjacencia = tipoDeRepresentacao == TipoDeRepresentacao.LISTA_DE_ADJACENCIA
                ? new ArrayList<>() : null;
        matrizDeAdjacencia = tipoDeRepresentacao == TipoDeRepresentacao.MATRIZ_DE_ADJACENCIA
                ? new ArrayList<>() : null;
        matrizDeIncidencia = tipoDeRepresentacao == TipoDeRepresentacao.MATRIZ_DE_INCIDENCIA
                ? new ArrayList<>() : null;
        arestasDeIncidencia = tipoDeRepresentacao == TipoDeRepresentacao.MATRIZ_DE_INCIDENCIA
                ? new ArrayList<>() : null;
    }

    public void adicionarVertice(Vertice vertice) throws Exception {
        if (vertice == null) {
            throw new IllegalArgumentException("O vértice não pode ser nulo.");
        }
        if (verticeIdExiste(vertice.id())) {
            throw new Exception("Vertice já existe.");
        }

        vertices.add(vertice);
        if (listaDeAdjacencia != null) {
            listaDeAdjacencia.add(new ArrayList<>());
        } else if (matrizDeAdjacencia != null) {
            for (ArrayList<ArrayList<Aresta>> linha : matrizDeAdjacencia) {
                linha.add(new ArrayList<>());
            }
            ArrayList<ArrayList<Aresta>> novaLinha = new ArrayList<>();
            for (int i = 0; i < vertices.size(); i++) {
                novaLinha.add(new ArrayList<>());
            }
            matrizDeAdjacencia.add(novaLinha);
        } else {
            ArrayList<Integer> novaLinha = new ArrayList<>();
            for (int i = 0; i < arestasDeIncidencia.size(); i++) {
                novaLinha.add(0);
            }
            matrizDeIncidencia.add(novaLinha);
        }
    }

    public void adicionarVerticeSeNaoExiste(Vertice vertice) {
        if (vertice == null) {
            throw new IllegalArgumentException("O vértice não pode ser nulo.");
        }
        if (verticeIdExiste(vertice.id())) {
            return;
        }
        try {
            adicionarVertice(vertice);
        } catch (Exception exception) {
            throw new IllegalStateException("Não foi possível adicionar o vértice.", exception);
        }
    }

    public boolean verticeIdExiste(int id) {
        return indiceDoVertice(id) >= 0;
    }

    public boolean verticeExiste(Vertice vertice) {
        return vertice != null && verticeIdExiste(vertice.id());
    }

    @Override
    public int numeroDeVertices() {
        return vertices.size();
    }

    @Override
    public int grauDoVertice(Vertice vertice) {
        int indice = validarVertice(vertice);
        int grau = 0;
        for (Aresta aresta : todasAsArestas()) {
            if (indiceDoVertice(aresta.origem().id()) == indice
                    || indiceDoVertice(aresta.destino().id()) == indice) {
                grau++;
            }
        }
        return grau;
    }

    @Override
    public ArrayList<Vertice> adjacentesDe(Vertice vertice) {
        int origem = validarVertice(vertice);
        ArrayList<Vertice> adjacentes = new ArrayList<>();
        for (Aresta aresta : arestasDaOrigem(origem)) {
            adjacentes.add(vertices.get(indiceDoVertice(aresta.destino().id())));
        }
        return adjacentes;
    }

    @Override
    public ArrayList<Vertice> vertices() {
        return new ArrayList<>(vertices);
    }

    public Vertice getVertice(int id) throws Exception {
        int indice = indiceDoVertice(id);
        if (indice < 0) {
            throw new Exception("O vértice " + id + " não existe.");
        }
        return vertices.get(indice);
    }

    @Override
    public void adicionarAresta(Vertice origem, Vertice destino) throws Exception {
        adicionarAresta(origem, destino, 1);
    }

    @Override
    public void adicionarAresta(Vertice origem, Vertice destino, double peso) throws Exception {
        int indiceOrigem = validarVertice(origem);
        int indiceDestino = validarVertice(destino);
        Aresta aresta = new Aresta(vertices.get(indiceOrigem), vertices.get(indiceDestino), peso);

        if (listaDeAdjacencia != null) {
            listaDeAdjacencia.get(indiceOrigem).add(aresta);
        } else if (matrizDeAdjacencia != null) {
            matrizDeAdjacencia.get(indiceOrigem).get(indiceDestino).add(aresta);
        } else {
            for (int i = 0; i < vertices.size(); i++) {
                int valor = i == indiceOrigem && i == indiceDestino
                        ? 2 : i == indiceOrigem ? -1 : i == indiceDestino ? 1 : 0;
                matrizDeIncidencia.get(i).add(valor);
            }
            arestasDeIncidencia.add(aresta);
        }
    }

    @Override
    public boolean existeAresta(Vertice origem, Vertice destino) {
        if (!verticeExiste(origem) || !verticeExiste(destino)) {
            return false;
        }
        return !arestasEntre(origem, destino).isEmpty();
    }

    @Override
    public int numeroDeArestas() {
        if (listaDeAdjacencia != null) {
            int numero = 0;
            for (ArrayList<Aresta> arestas : listaDeAdjacencia) {
                numero += arestas.size();
            }
            return numero;
        }
        if (matrizDeAdjacencia != null) {
            int numero = 0;
            for (ArrayList<ArrayList<Aresta>> linha : matrizDeAdjacencia) {
                for (ArrayList<Aresta> celula : linha) {
                    numero += celula.size();
                }
            }
            return numero;
        }
        return arestasDeIncidencia.size();
    }

    @Override
    public ArrayList<Aresta> arestasEntre(Vertice origem, Vertice destino) {
        ArrayList<Aresta> resultado = new ArrayList<>();
        if (!verticeExiste(origem) || !verticeExiste(destino)) {
            return resultado;
        }

        int indiceOrigem = indiceDoVertice(origem.id());
        int indiceDestino = indiceDoVertice(destino.id());
        if (listaDeAdjacencia != null) {
            for (Aresta aresta : listaDeAdjacencia.get(indiceOrigem)) {
                if (indiceDoVertice(aresta.destino().id()) == indiceDestino) {
                    resultado.add(aresta);
                }
            }
        } else if (matrizDeAdjacencia != null) {
            resultado.addAll(matrizDeAdjacencia.get(indiceOrigem).get(indiceDestino));
        } else {
            for (int coluna = 0; coluna < arestasDeIncidencia.size(); coluna++) {
                if (matrizDeIncidencia.get(indiceOrigem).get(coluna) == -1
                        && matrizDeIncidencia.get(indiceDestino).get(coluna) == 1
                        || indiceOrigem == indiceDestino
                        && matrizDeIncidencia.get(indiceOrigem).get(coluna) == 2) {
                    resultado.add(arestasDeIncidencia.get(coluna));
                }
            }
        }
        return resultado;
    }

    private int validarVertice(Vertice vertice) {
        if (vertice == null) {
            throw new IllegalArgumentException("O vértice não pode ser nulo.");
        }
        int indice = indiceDoVertice(vertice.id());
        if (indice < 0) {
            throw new IllegalArgumentException("O vértice " + vertice.id() + " não existe no grafo.");
        }
        return indice;
    }

    private int indiceDoVertice(int id) {
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices.get(i).id() == id) {
                return i;
            }
        }
        return -1;
    }

    private ArrayList<Aresta> arestasDaOrigem(int indiceOrigem) {
        if (listaDeAdjacencia != null) {
            return listaDeAdjacencia.get(indiceOrigem);
        }
        if (matrizDeAdjacencia != null) {
            ArrayList<Aresta> resultado = new ArrayList<>();
            for (ArrayList<Aresta> celula : matrizDeAdjacencia.get(indiceOrigem)) {
                resultado.addAll(celula);
            }
            return resultado;
        }

        ArrayList<Aresta> resultado = new ArrayList<>();
        for (int coluna = 0; coluna < arestasDeIncidencia.size(); coluna++) {
            if (matrizDeIncidencia.get(indiceOrigem).get(coluna) == -1
                    || matrizDeIncidencia.get(indiceOrigem).get(coluna) == 2) {
                resultado.add(arestasDeIncidencia.get(coluna));
            }
        }
        return resultado;
    }

    @Override
    public void resetarVertices() {
        for (Vertice v : vertices) {
            v.limpar();
        }
    }

    private ArrayList<Aresta> todasAsArestas() {
        ArrayList<Aresta> resultado = new ArrayList<>();
        if (listaDeAdjacencia != null) {
            for (ArrayList<Aresta> arestas : listaDeAdjacencia) {
                resultado.addAll(arestas);
            }
        } else if (matrizDeAdjacencia != null) {
            for (ArrayList<ArrayList<Aresta>> linha : matrizDeAdjacencia) {
                for (ArrayList<Aresta> celula : linha) {
                    resultado.addAll(celula);
                }
            }
        } else {
            resultado.addAll(arestasDeIncidencia);
        }
        return resultado;
    }
}
