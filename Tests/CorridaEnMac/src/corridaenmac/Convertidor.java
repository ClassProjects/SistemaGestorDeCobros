/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package corridaenmac;

import java.io.File;
import java.util.Formatter;
import java.util.Scanner;

/**
 *
 * @author jorgea
 */
public class Convertidor {
    
    static Formatter F;
    static String archivoOrigen = "RATES.prn"; //Archivo de donde salen los registros
    static String archivoDestino = "RATES.txt"; //Archivo a salvar con registros modificados
    static int size = 20; //Tamaño del registro. Funciona para completar de espacios si es necesario
    
    public static void main(String[] args) {
                
        String reg; //Registro que se analizara para su conversion a linea continua
        
        try {            
            Scanner in = new Scanner(new File(archivoOrigen));
            F = new Formatter(archivoDestino); 
            while (in.hasNext()){
                reg = in.nextLine();
                System.out.println("***" + reg);
                while (reg.length() != size) {
                    reg+=" ";
                }
                System.out.print(reg);
                F.format(reg);
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }finally {
            F.close();
            
        }
        
        
        
    }
    
}
