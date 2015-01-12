import java.io.*;

public class Main {

    public static void main(String[] args) {
	    if(args.length != 1) {
            System.out.println("Missing input file name");
            System.exit(1);
        }
        
        BufferedReader reader = null;
        Integer        total = 0;
        
        try {
            reader = new BufferedReader(new FileReader(args[0]));
            String text = null;
            while((text = reader.readLine()) != null) {
                if(!text.equals("")) {
                    System.out.println(Integer.parseInt(text, 16));
                }
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally  {
            try {
                if(reader != null) reader.close();
            } catch (IOException e) {
            }
        }
    }
}
