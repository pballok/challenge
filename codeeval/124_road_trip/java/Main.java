import java.io.*;
import java.util.*;

// CodeEval challenge 124: Road Trip

// Compute distances between cities

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new FileReader(args[0]));
        
        for(String text = reader.readLine(); text != null; text = reader.readLine()) {
            ArrayList<Integer> distances = new ArrayList<Integer>(2000);
            String[] cities = text.split("; |;|,");
            int route_size = cities.length;
            for(int i = 1; i < route_size; i += 2)
                distances.add(Integer.parseInt(cities[i]));

            Collections.sort(distances);
            
            Integer total = 0;
            boolean first = true;
            for(Integer d : distances) {
                if(!first)
                    System.out.print(",");
                else
                    first = false;
                System.out.print(d - total);
                total = d;
            }
            System.out.println("");
        }

        reader.close();
    }
}

