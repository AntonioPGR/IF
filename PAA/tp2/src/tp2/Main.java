package tp2;

import tp2.managers.FileManager;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        FileManager fileManager = new FileManager();
        ArrayList<String> lines = fileManager.stringReader("src/tp2/files/input.txt");

        int n = Integer.parseInt(lines.get(0));

        // nó -> [<nó, peso>]
        ArrayList<ArrayList<Pair<Integer, Integer>>> adj = new ArrayList<ArrayList<Pair<Integer, Integer>>>();
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<Pair<Integer, Integer>>());
        }

        for (int i = 1; i <= n && i < lines.size(); i++) {
            String line = lines.get(i);
            String[] parts = line.split(" ");
            int from = Integer.parseInt(parts[0]);

            for (int j = 1; j < parts.length; j++) {
                String[] part = parts[j].replace(";", "").split("-");
                int to = Integer.parseInt(part[0]);
                int weight = Integer.parseInt(part[1]);
                adj.get(from).add(new Pair<Integer, Integer>(to, weight));
            }
        }

    }
}
