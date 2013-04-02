/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package phones;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Formatter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author parallels
 */
public class Phones {

    /**
     * @param args the command line arguments
     */
    
    static Formatter F;
    
    public static void main(String[] args) {
        
        int num = 22000000;
        int numIni = 0;
        int numFin = 7143;
        int numIniID = 1;
        int numFinID = 10056;
        int contador = 0;
        String code = "NO";
        ArrayList<String> ids = new ArrayList<String>();
        try {
            //Cargado de IDs al ArrayList
            Scanner in = new Scanner(new File("ids.csv"));
            for (int i = numIniID; i <= numFinID; i++) {
                ids.add(in.nextLine());
            }
        } catch (FileNotFoundException ex) {
            ex.printStackTrace();
        }
        try {
            F = new Formatter("PHONES" + code + ".csv");
            for (int i = numIni; i < numFin; i++) {
                F.format(num+ code + ids.get(contador) + "\n");
                num++;
                contador++;
            }
            
        } catch (FileNotFoundException ex) {
            ex.printStackTrace();
        } finally {
            F.close();
        }
        
        
        
    }
}
