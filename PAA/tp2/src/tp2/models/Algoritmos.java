package tp2.models;

import tp2.enums.TipoDeRepresentacao;
import tp2.interfaces.IGrafo;
import tp2.interfaces.IAlgoritmos;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class Algoritmos implements IAlgoritmos{
	@Override
	public IGrafo carregarGrafo(String path, TipoDeRepresentacao t) throws Exception{
		return null;
	}

	@Override
	public Collection<Aresta> buscaEmProfundidade(IGrafo g){
		return List.of();
	}

	@Override
	public Collection<Aresta> arestasDeArvore(IGrafo g){
		return List.of();
	}

	@Override
	public Collection<Aresta> arestasDeRetorno(IGrafo g){
		return List.of();
	}

	@Override
	public Collection<Aresta> arestasDeAvanco(IGrafo g){
		return List.of();
	}

	@Override
	public Collection<Aresta> arestasDeCruzamento(IGrafo g){
		return List.of();
	}

	@Override
	public Collection<Aresta> buscaEmLargura(IGrafo g){
		return List.of();
	}

	@Override
	public boolean existeCiclo(IGrafo g){
		return false;
	}

	@Override
	public IGrafo componentesFortementeConexos(IGrafo g){
		return null;
	}

	@Override
	public Collection<Aresta> arvoreGeradoraMinima(IGrafo g){
		return List.of();
	}

	@Override
	public double custoDaArvoreGeradora(IGrafo g, Collection<Aresta> arestas) throws Exception{
		return 0;
	}

	@Override
	public ArrayList<Aresta> caminhoMinimo(IGrafo g, Vertice origem, Vertice destino){
		return null;
	}

	@Override
	public double custoDoCaminhoMinimo(IGrafo g, ArrayList<Aresta> arestas, Vertice origem, Vertice destino) throws Exception{
		return 0;
	}

	@Override
	public double fluxoMaximo(IGrafo g){
		return 0;
	}
}
