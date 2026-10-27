package tp2.interfaces;

import tp2.models.Aresta;
import tp2.enums.TipoDeRepresentacao;
import tp2.models.Vertice;

import java.util.ArrayList;
import java.util.Collection;

/**
 *
 * @author humberto e douglas
 */
public interface IAlgoritmos{

    /**
     * Carrega grafo do arquivo texto. O formato será definido do site da disciplina
     * @param path Caminho para o arquivo de texto que contém o grafo.
     * @param t Tipo de representação do grafo
     * @return um objeto grafo com as informações representadas no arquivo.
     * @throws java.lang.Exception Caminho inválido ou árquivo fora do padrão.
     */
    public IGrafo carregarGrafo(String path, TipoDeRepresentacao t) throws Exception;

    /**
     * Realiza a busca em profundidade no grafo
     * @param g Grafo
     * @return as arestas da floresta resultante
     */
    public Collection<Aresta> buscaEmProfundidade (IGrafo g);
    
    /**
     * Arestas de arvore.
     * @param g O grafo
     * @return As arestas de arvore do grafo g.
     */
    public Collection<Aresta> arestasDeArvore(IGrafo g);
    
    /**
     * Arestas de retorno.
     * @param g O grafo
     * @return As arestas de retorno do grafo g.
     */
    public Collection<Aresta> arestasDeRetorno(IGrafo g);
    
    /**
     * Arestas de avanço.
     * @param g O grafo
     * @return As arestas de avanço do grafo g.
     */
    public Collection<Aresta> arestasDeAvanco(IGrafo g);
    
    /**
     * Arestas de cruzamento.
     * @param g O grafo
     * @return As arestas de cruzamento do grafo g.
     */
    public Collection<Aresta> arestasDeCruzamento(IGrafo g);
    
    /**
     * Realiza busca em largura no grafo 
     * @param g Grafo
     * @return as arestas da árvore resultante
     */
    public Collection<Aresta> buscaEmLargura (IGrafo g);
    
    /**
     * Verifica se existe ciclo no grafo.
     * @param g Grafo.
     * @return True, se existe ciclo, False, em caso contrário.
     */
    public boolean existeCiclo(IGrafo g);
    
     /**
     * Identifica os componentes fortemente conexos de um grafo e retorna o grafo reduzido
     * @param g Grafo original
     * @return Grafo reduzido
     */
    public IGrafo componentesFortementeConexos (IGrafo g);
    
    /**
     * Retorna a árvore geradora mínima.
     * @param g O grafo.
     * @return Retorna a árvore geradora mínima.
     */
    public Collection<Aresta> arvoreGeradoraMinima(IGrafo g);
    
    /**
     * Calcula o custo de uma árvore geradora.
     * @param arestas As arestas que compoem a árvore geradora.
     * @param g O grafo.
     * @return O custo da árvore geradora.
     * @throws java.lang.Exception Se a árvore apresentada não é geradora do grafo.
     */
    public double custoDaArvoreGeradora(IGrafo g, Collection<Aresta> arestas) throws Exception;
    
    /**
     * Retorna (em ordem) as arestas que compoem o caminho mais curto 
     * entre um par de vértices. Esta função considera o peso das arestas
     * para composição do caminho mais curto.
     * @param g O grafo
     * @param origem Vértice de origem
     * @param destino Vértice de destino
     * @return As arestas (em ordem) do caminho mais curto.
     */
    public ArrayList<Aresta> caminhoMinimo(IGrafo g, Vertice origem, Vertice destino );
    
    public ArrayList<Aresta> caminhoMinimo(IGrafo g);
    
    /**
     * Dado um caminho, esta função calcula o custo do caminho.
     * @param arestas Arestas que compõem o caminho
     * @param g Grafo
     * @param origem Vértice de origem
     * @param destino Vértice de destino
     * @return o custo da caminho.
     * @throws java.lang.Exception Se a sequencia apresentada não é um caminho
     * entre origem e destino.
     */
    public double custoDoCaminhoMinimo (IGrafo g, ArrayList<Aresta> arestas, Vertice origem, Vertice destino ) throws Exception;
    
    /**
     * Calcula o fluxo máximo em um grafo ponderado orientado
     * @param g Grafo
     * @return o valor do fluxo máximo no grafo
     */
    public double fluxoMaximo (IGrafo g);
    
}

