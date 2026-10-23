package tp2.models;

import tp2.Pair;
import tp2.interfaces.IGrafo;

import java.util.ArrayList;

public class Grafo implements IGrafo{

	ArrayList<Vertice> vertices;
	ArrayList<Aresta> arestas;
	ArrayList<ArrayList<Pair<Integer, Integer>>> adj;

	// VERTICES ==========================================================================================================
	public void adicionarVertice(Vertice vertice){
		vertices.add(vertice);
		adj.add(new ArrayList<>());
	}

	// VERTICES ==========================================================================================================
	@Override
	public void adicionarAresta(Vertice origem, Vertice destino) throws Exception{
		if(!verticeExiste(origem) || !verticeExiste(destino)) throw new Exception("O vertice deve ser adicionado antes de ser criado uma aresta própria.");
	}

	@Override
	public void adicionarAresta(Vertice origem, Vertice destino, double peso) throws Exception{

	}

	@Override
	public boolean existeAresta(Vertice origem, Vertice destino){
		return false;
	}

	@Override
	public int grauDoVertice(Vertice vertice) throws Exception{
		return 0;
	}

	@Override
	public int numeroDeVertices(){
		return 0;
	}

	@Override
	public int numeroDeArestas(){
		return 0;
	}

	@Override
	public ArrayList<Vertice> adjacentesDe(Vertice vertice) throws Exception{
		return null;
	}

	@Override
	public void setarPeso(Vertice origem, Vertice destino, double peso) throws Exception{

	}

	@Override
	public ArrayList<Aresta> arestasEntre(Vertice origem, Vertice destino) throws Exception{
		return null;
	}

	@Override
	public ArrayList<Vertice> vertices(){
		return null;
	}
}
