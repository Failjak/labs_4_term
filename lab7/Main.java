// import java.io.*;


public class Main{
    public static void main(String[] args) {
        
        String[] strs = new String[] {"hello", "world"};

        System.out.println("\n" + CustomString.concat(strs));
        System.out.println("\n" + CustomString.concat_ws(strs, ":"));

    }
}