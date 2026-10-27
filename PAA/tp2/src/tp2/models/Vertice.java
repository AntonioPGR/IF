package tp2.models;

import java.util.Objects;

public class Vertice {
    private final int vertice;
    private boolean visitado;
    private int tempoDescoberta;
    private int tempoFinalizacao;
    
    public Vertice( int v ){
        this.vertice = v;
        this.visitado = false;
        this.tempoDescoberta = 0;
        this.tempoFinalizacao = 0;
    }

    public int id() {
        return vertice;
    }

    public boolean isVisitado() {
        return visitado;
    }

    public void setVisitado(boolean visitado) {
        this.visitado = visitado;
    }

    public int getTempoDescoberta() {
        return tempoDescoberta;
    }

    public void setTempoDescoberta(int tempoDescoberta) {
        this.tempoDescoberta = tempoDescoberta;
    }

    public int getTempoFinalizacao() {
        return tempoFinalizacao;
    }

    public void setTempoFinalizacao(int tempoFinalizacao) {
        this.tempoFinalizacao = tempoFinalizacao;
    }

    public void limpar() {
        this.visitado = false;
        this.tempoDescoberta = 0;
        this.tempoFinalizacao = 0;
    }

    public void clean() {
        limpar();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Vertice vertice1 = (Vertice) o;
        return vertice == vertice1.vertice;
    }

    @Override
    public int hashCode() {
        return Objects.hash(vertice);
    }

    @Override
    public String toString() {
        return String.valueOf(vertice);
    }
}

