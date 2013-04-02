/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package corridaenmac;

import java.util.Formatter;
import java.util.Random;

/**
 *
 * @author jorgea
 */
public class CorridaEnMac {

    /**
     * @param args the command line arguments
     * 
     * 
     */
    
    static Formatter Y;
    static String Time;

    
    public static void main(String[] args) {
        Random R = new Random();

        int Hour, Minute, MinutesCall, Sec;
        int Day, Month;

        try {

            Y = new Formatter("Intial_End_Calls.csv");

            for (int i = 0; i < 250000; i++) {
                Time = "";
                Hour = R.nextInt(25);
                if (Integer.toString(Hour).length() == 1) {
                    Time += "0" + Integer.toString(Hour);
                } else {
                    Time += Integer.toString(Hour);
                }
                Minute = R.nextInt(60);
                if (Integer.toString(Minute).length() == 1) {
                    Time += "0" + Integer.toString(Minute);
                } else {
                    Time += Integer.toString(Minute);
                }
                Sec = R.nextInt(60);
                if (Integer.toString(Sec).length() == 1) {
                    Time += "0" + Integer.toString(Sec);
                } else {
                    Time += Integer.toString(Sec);
                }
                Day = 1 + R.nextInt(31);
                if (Day >= 0 && Day <= 9) {
                    Time += "0" + Integer.toString(Day);
                } else {
                    Time += Integer.toString(Day);
                }
                Month = 1 + R.nextInt(12);
                if (Month >= 0 && Month <= 9) {
                    Time += "0" + Integer.toString(Month);
                } else {
                    Time += Integer.toString(Month);
                }
                Time += "2012";

                MinutesCall = 1 + R.nextInt(5400);

                int M = Math.round(MinutesCall / 60);

                Minute += M;

                if (Minute >= 60) {
                    Hour++;
                    Minute = 0;
                }

                if (Hour >= 24) {
                    Hour = 0;
                }

                if (Integer.toString(Hour).length() == 1) {
                    Time += "0" + Integer.toString(Hour);
                } else {
                    Time += Integer.toString(Hour);
                }

                if (Integer.toString(Minute).length() == 1) {
                    Time += "0" + Integer.toString(Minute);
                } else {
                    Time += Integer.toString(Minute);
                }

                if (Integer.toString(Sec).length() == 1) {
                    Time += "0" + Integer.toString(Sec);
                } else {
                    Time += Integer.toString(Sec);
                }

                for (int j = 6; j <= 13; j++) {
                    Time += Time.charAt(j);
                }

                System.out.println(Time + "   Iteracion: " + i);
                Y.format(Time + "\n");
            }

        } catch (Exception Ex) {
            Ex.printStackTrace();
        }finally {
           
        }
        
        Y.close(); 
    }
}
