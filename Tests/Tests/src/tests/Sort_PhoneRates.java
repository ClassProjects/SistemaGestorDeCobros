package tests;

/**
 *
 * @author Guillermo E. Mazzoni & Jorge Caballero
 */
import java.util.*;
import java.io.*;

public class Sort_PhoneRates {

    public static void main(String[] args) {

        try {
            Scanner entrada = new Scanner("Intial_End_Calls.txt");
            while (entrada.hasNextLine()) {
                System.out.println(entrada.nextLine());
            }
            entrada.close();
        } catch (Exception Ex) {
        }
    }
}
