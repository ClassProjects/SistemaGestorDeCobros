package tests;

import java.io.File;
import java.io.*;
import java.util.*;

/**
 *
 * @author Guillermo E. Mazzoni
 */
public class NewClass {

    static Formatter H;

    public static void main(String[] args) {


        String Names = "";
        Random R = new Random();;
        String Email[] = {"gmail.com", "yahoo.com", "msn.com", "live.com", "unitec.edu", "aol.com", "laureate.net"};
        String P[] = {"_", "."};
        System.out.println("Antes de Try");
        int cont = 0;
        try {
            H = new Formatter("nombresFinales.csv");
            Scanner entrada = new Scanner(new File("nombres.csv"));
            //System.out.println("Crea Scanner");
            while (entrada.hasNext()) {
                //System.out.println("Entra a while");
                cont++;
                System.out.println(cont);
                Names = entrada.next();
                int Date = R.nextInt(99) + 1;

                try {

                    H.format(Names + P[R.nextInt(2)] + Integer.toString(Date) + "@" + Email[R.nextInt(7)] + "\n");
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        } catch (Exception ex) {
            ex.printStackTrace();

        } finally {
            H.close();
        }
    }
}