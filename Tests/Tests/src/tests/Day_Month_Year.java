package tests;

/**
 *
 * @author Guillermo E. Mazzoni & Jorge Caballero
 */
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;
import javax.swing.*;
import javax.swing.Timer;

public class Day_Month_Year extends JFrame {

    static Formatter Y;
    static String Time;
    static ArrayList<String> Array;
    static int Temp_Hour;
    static int Seconds = 0;
    static int Hour_C, Hour = 0, Minute = 0, MinutesCall, Sec = 0;
    static int Day_C, Day = 1, Month_C, Month = 1;
    static Random R = new Random();

    public Day_Month_Year() {


        try {

            Y = new Formatter("./src/tests/Intial_End_Calls.txt");

            for (int i = 0; i < 207360; i++) {
                Time = "";

                Month_C++;
                if (Month_C == 17280) {
                    Month_C = 0;
                    Month++;
                }

                Day_C++;
                if (Day_C == 576) {
                    Day_C = 0;
                    Day++;
                }

                if (Day == 31) {
                    Day = 1;
                }

                Hour_C++;
                if (Hour_C == 23) {
                    Hour_C = 0;
                    Hour++;
                }

                if (Hour == 24) {
                    Hour = 0;
                }

                if (Integer.toString(Hour).length() == 1) {
                    Time += "0" + Integer.toString(Hour);
                } else {
                    Time += Integer.toString(Hour);
                }

                Minute = 0;
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

                if (Day >= 0 && Day <= 9) {
                    Time += "0" + Integer.toString(Day);
                } else {
                    Time += Integer.toString(Day);
                }

                if (Month >= 0 && Month <= 9) {
                    Time += "0" + Integer.toString(Month);
                } else {
                    Time += Integer.toString(Month);
                }
                Time += "2012";


                //Queda igual porque genera el tiempo de llamada
                MinutesCall = 1 + R.nextInt(5400);

                int M = Math.round(MinutesCall / 60);

                Minute += M;

                Temp_Hour = Hour;

                if (Minute >= 60) {
                    Temp_Hour++;
                    Minute = 0;
                }

                if (Temp_Hour >= 24) {
                    Temp_Hour = 0;
                }

                if (Integer.toString(Temp_Hour).length() == 1) {
                    Time += "0" + Integer.toString(Temp_Hour);
                } else {
                    Time += Integer.toString(Temp_Hour);
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
             Y.close();
        } finally {
           
        }
    }

    public static void main(String[] args) {
        new Day_Month_Year();
    }
}
