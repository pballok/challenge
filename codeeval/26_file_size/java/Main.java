import java.io.*;

// CodeEval challenge 26: File Size

// Print the size of a file in bytes.

public class Main {

    public static void main(String[] args) throws Exception {
	    if(args.length != 1) {
            System.out.println("Missing input file name");
            System.exit(1);
        }
        
        File f = new File(args[0]);
        System.out.println(f.length());
    }
}

