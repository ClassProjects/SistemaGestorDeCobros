package corridaenmac;

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
    static String Temp = "";
    static private Timer Tiempo = new Timer(1000, null);
    static int Seconds = 0;
    static int Hour = 0, Minute = 0, MinutesCall, Sec = 0;
    static int Day = 1, Month = 0;
    static Random R = new Random();

    public Day_Month_Year() {

        try {
            Y = new Formatter("./src/tests/Intial_End_Calls.txt");
        } catch (Exception Ex) {
        }

        Tiempo.start();
        Tiempo.addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent Event) {
                        Seconds++;

                        

                        for (int i = 0; i < 10000; i++) {
                            Time = "";

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
                            Day++;


                            //Queda igual porque genera el tiempo de llamada
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
                            // Y.format(Time + "\n");
                        }
                        
                        System.out.println(Seconds + "******************************************************************************");
                    }
                });
        try {
            Y.close();
        } catch (Exception ex) {
        }
    }

    public static void main(String[] args) {
        new Day_Month_Year();
    }
}
