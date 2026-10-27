package tp2.models;

public class Aresta {

    private final Vertice origem;
    private final Vertice destino;
    private final double peso;
    
    public Aresta( Vertice origem, Vertice destino ){
        this.origem = origem;
        this.destino = destino;
        this.peso = 1;
    }
    
    public Aresta( Vertice origem, Vertice destino, double peso ){
        this.origem = origem;
        this.destino = destino;
        this.peso = peso;
    }

    public Vertice origem() {
        return origem;
    }

    public Vertice destino() {
        return destino;
    }

    public double peso() {
        return peso;
    }

}

