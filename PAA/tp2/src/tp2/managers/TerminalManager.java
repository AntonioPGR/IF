package tp2.managers;

import tp2.interfaces.IGrafo;
import tp2.models.Grafo;
import tp2.models.Vertice;

import java.util.Scanner;

public class TerminalManager{

	public static final Scanner scanner = new Scanner(System.in);

	public static Vertice lerVertice(IGrafo grafo, String mensagem) {
		while (true) {
			int id = lerInteiro(mensagem, Integer.MIN_VALUE, Integer.MAX_VALUE);
			try {
				return grafo.getVertice(id);
			} catch (Exception e) {
				StringBuilder vertices_disponiveis = new StringBuilder();
				for(Vertice vertice : grafo.vertices()) vertices_disponiveis.append(vertice.id()).append(" ");
				printLn(e.getMessage() + " Vértices disponíveis: " + vertices_disponiveis);
			}
		}
	}

	public static void printLn(){
		System.out.println();
	}

	public static void printLn(String str){
		System.out.println(str);
	}

	public static void print(String str){
		System.out.print(str);
	}

	public static int lerInteiro(String mensagem, int minimo, int maximo) {
		while (true) {
			print(mensagem);
			if (!scanner.hasNextLine()) System.exit(0);
			String entrada = scanner.nextLine().trim();
			try {
				int valor = Integer.parseInt(entrada);
				if (valor >= minimo && valor <= maximo) return valor;
			} catch (NumberFormatException ignored) {
				printLn("Entrada inválida.");
			}
		}
	}

}
