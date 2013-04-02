//
//  main.cpp
//  Sistema Gestor de Cobros
//
//  Created by Jorge Caballero on 2/11/13.
//  Copyright (c) 2013 Jorge Caballero. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int user_sel_main = -1;
    int user_sel = -1;
    int user_sel_sub = -1;
    do {
        cout << "SISTEMA GESTOR DE COBROS" << endl;
        cout << "# MENU PRINCIPAL #" << endl;
        cout << "1. Mantenimiento" << endl;
        cout << "2. Reportes sin indices" << endl;
        cout << "3. Reportes con indices lineales" << endl;
        cout << "4. Reportes con indices con arbol B" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccion -> ";
        cin >> user_sel_main;
        
        switch (user_sel_main) {
            case 1:
                //Mantenimiento
                do {
                    cout << "  # MENU DE MANTENIMIENTO #" << endl;
                    cout << "  1. Clientes" << endl;
                    cout << "  2. Telefonos" << endl;
                    cout << "  3. Tipos de Telefonos" << endl;
                    cout << "  4. Tarifas" << endl;
                    cout << "  0. Salir al Menu Principal" << endl;
                    cout << "  Seleccion -> ";
                    cin >> user_sel;
                    
                    switch (user_sel) {
                        case 1:
                            //Clientes
                            do {
                                cout << "    # CLIENTES #" << endl;
                                cout << "    1. Agregar" << endl;
                                cout << "    2. Buscar" << endl;
                                cout << "    3. Modificar" << endl;
                                cout << "    4. Borrar" << endl;
                                cout << "    5. Listar" << endl;
                                cout << "    0. Salir al Menu de Mantenimiento" << endl;
                                cout << "    Seleccion -> ";
                                cin >> user_sel_sub;
                                
                                switch (user_sel_sub) {
                                    case 1:
                                        //Agregar
                                        break;
                                    case 2:
                                        //Buscar
                                        break;
                                    case 3:
                                        //Modificar
                                        break;
                                    case 4:
                                        //Borrar
                                        break;
                                    case 5:
                                        //Listar
                                        break;
                                }
                                
                            } while (user_sel_sub != 0);
                            break;
                        case 2:
                            //Telefonos
                            do {
                                cout << "    # TELEFONOS #" << endl;
                                cout << "    1. Agregar" << endl;
                                cout << "    2. Buscar" << endl;
                                cout << "    3. Modificar" << endl;
                                cout << "    4. Borrar" << endl;
                                cout << "    5. Listar" << endl;
                                cout << "    0. Salir al Menu de Mantenimiento" << endl;
                                cout << "    Seleccion -> ";
                                cin >> user_sel_sub;
                                
                                switch (user_sel_sub) {
                                    case 1:
                                        //Agregar
                                        break;
                                    case 2:
                                        //Buscar
                                        break;
                                    case 3:
                                        //Modificar
                                        break;
                                    case 4:
                                        //Borrar
                                        break;
                                    case 5:
                                        //Listar
                                        break;
                                }
                                
                            } while (user_sel_sub != 0);
                            break;
                        case 3:
                            //Tipos de Telefonos
                            do {
                                cout << "    # TIPOS DE TELEFONOS #" << endl;
                                cout << "    1. Agregar" << endl;
                                cout << "    2. Buscar" << endl;
                                cout << "    3. Modificar" << endl;
                                cout << "    4. Borrar" << endl;
                                cout << "    5. Listar" << endl;
                                cout << "    0. Salir al Menu de Mantenimiento" << endl;
                                cout << "    Seleccion -> ";
                                cin >> user_sel_sub;
                                
                                switch (user_sel_sub) {
                                    case 1:
                                        //Agregar
                                        break;
                                    case 2:
                                        //Buscar
                                        break;
                                    case 3:
                                        //Modificar
                                        break;
                                    case 4:
                                        //Borrar
                                        break;
                                    case 5:
                                        //Listar
                                        break;
                                }
                                
                            } while (user_sel_sub != 0);
                            break;
                        case 4:
                            //Tarifas
                            do {
                                cout << "    # TARIFAS #" << endl;
                                cout << "    1. Agregar" << endl;
                                cout << "    2. Buscar" << endl;
                                cout << "    3. Modificar" << endl;
                                cout << "    4. Borrar" << endl;
                                cout << "    5. Listar" << endl;
                                cout << "    0. Salir al Menu de Mantenimiento" << endl;
                                cout << "    Seleccion -> ";
                                cin >> user_sel_sub;
                                
                                switch (user_sel_sub) {
                                    case 1:
                                        //Agregar
                                        break;
                                    case 2:
                                        //Buscar
                                        break;
                                    case 3:
                                        //Modificar
                                        break;
                                    case 4:
                                        //Borrar
                                        break;
                                    case 5:
                                        //Listar
                                        break;
                                }
                                
                            } while (user_sel_sub != 0);
                            break;
                    }
                    
                } while (user_sel != 0);
                //Fin Mantenimiento
                break;
            case 2:
                //Reportes sin indices
                do {
                    cout << "  # REPORTES SIN INDICES #" << endl;
                    cout << "  1. Llamada por cliente por rango de fecha" << endl;
                    cout << "  2. Generar todas las facturas por rango de fecha" << endl;
                    cout << "  0. Salir al Menu Principal" << endl;
                    cout << "  Seleccion -> ";
                    cin >> user_sel;
                    
                    switch (user_sel) {
                        case 1:
                            //Cliente x rango
                            break;
                        case 2:
                            //Todas las facturas x rango
                            break;
                    }
                } while (user_sel != 0);
                //Fin Reportes sin indices
                break;
            case 3:
                //Reportes con indices lineales
                do {
                    cout << "  # REPORTES CON INDICES LINEALES #" << endl;
                    cout << "  1. Llamada por cliente por rango de fecha" << endl;
                    cout << "  2. Generar todas las facturas por rango de fecha" << endl;
                    cout << "  0. Salir al Menu Principal" << endl;
                    cout << "  Seleccion -> ";
                    cin >> user_sel;
                    
                    switch (user_sel) {
                        case 1:
                            //Cliente x rango
                            break;
                        case 2:
                            //Todas las facturas x rango
                            break;
                    }

                } while (user_sel != 0);
                //Fin Reportes con indices lineales
                break;
            case 4:
                //Reportes con indices con arbol B
                do {
                    cout << "  # REPORTES CON INDICES CON ARBOL B #" << endl;
                    cout << "  1. Llamada por cliente por rango de fecha" << endl;
                    cout << "  2. Generar todas las facturas por rango de fecha" << endl;
                    cout << "  0. Salir al Menu Principal" << endl;
                    cout << "  Seleccion -> ";
                    cin >> user_sel;
                    
                    switch (user_sel) {
                        case 1:
                            //Cliente x rango
                            break;
                        case 2:
                            //Todas las facturas x rango
                            break;
                    }

                } while (user_sel != 0);
                //Fin Reportes con indices con arbol B
                break;
        }
        
        
    } while (user_sel_main != 0);
    return 0;
}

