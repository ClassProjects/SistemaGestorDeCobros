package gui_linecommand;

import java.util.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;

public class VentanaClientes extends JFrame {

    JLabel Title = new JLabel("Agregar a un Cliente");
    JLabel ClientImg = new JLabel(new ImageIcon(getClass().getResource("ClientImg.png")));
    JPanel Panel = new JPanel();
    JLabel NumberIDLabel = new JLabel("Numero de Identidad del Cliente:");
    JTextField NumberIDField = new JTextField(11);
    JLabel FirstNameLabel = new JLabel("Nombre del Cliente:");
    JTextField FirstNameField = new JTextField(14);
    JLabel SecondNameLabel = new JLabel("Apellido del Cliente:");
    JTextField SecondNameField = new JTextField(14);
    JLabel EmailLabel = new JLabel("Correo Electronico del Cliente:");
    JTextField EmailField = new JTextField(14);
    JLabel DirPostalLabel = new JLabel("Direccion Postal del Cliente:");
    JTextField DirPostalField = new JTextField(14);

    public VentanaClientes() {

        super("Agregar a un Cliente");
        setSize(270, 370);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        Panel.setBackground(Color.YELLOW);

        Panel.add(Title);
        Panel.add(ClientImg);
        Title.setFont(new Font("TlwgTypewriter", Font.BOLD, 20));
        Panel.add(NumberIDLabel);
        Panel.add(NumberIDField);
        Panel.add(FirstNameLabel);
        Panel.add(FirstNameField);
        Panel.add(SecondNameLabel);
        Panel.add(SecondNameField);
        Panel.add(EmailLabel);
        Panel.add(EmailField);
        Panel.add(DirPostalLabel);
        Panel.add(DirPostalField);

        add(Panel);
        setVisible(true);


    }

    public static void main(String[] args) {
        new VentanaClientes();
    }
}
