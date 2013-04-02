//Libs
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

//Clases
#include "Client.h"
#include "ClientFile.h"
#include "Phone.h"
#include "PhoneFile.h"
#include "Rates.h"
#include "RatesFile.h"
#include "PhoneType.h"
#include "PhoneTypeFile.h"
#include "ClientListIndex.h"
#include "PhoneListIndex.h"
#include "Report.h"
#include "ReportIndex.h"
#include "Tree.cpp"

using namespace std;

int main(int argc, const char * argv[])
{
    system("clear");
    cout << "Loading..." << endl;
    int digits;
    string ClientFN, ClientLN, ClientEM, ClientAD,ClientID;
    string PhoneNumber, PhoneType;
    cout << "Opening files..." << endl;
    cout << "Opening Client and ClientIndex..." << endl;
    ClientListIndex* cManage = new ClientListIndex();
    cout << "Client and ClientIndex opened succesfully!" << endl;
    cout << "Opening Rates..." << endl;
    RatesFile* rManage = new RatesFile();
    cout << "Rates opened succesfully!" << endl;
    cout << "Opening Phones and PhoneIndex..." << endl;
    PhoneListIndex* pManage = new PhoneListIndex();
    cout << "Phones and PhoneIndex opened succesfully!" << endl;
    PhoneTypeFile* ptManage = new PhoneTypeFile();
    cout << "Files opened succesfully" << endl;
    cout << "Loading Client Tree..." << endl;

    Elem cTree;
    RootTracker cTracker;
    Node* cRoot_ptr = new Node(cTracker);

    cTracker.set_root (null_ptr, cRoot_ptr);

    for (int i = 1; i <= cManage->getCount(); ++i){

        cTree.m_key = cManage->read(i)->getClientID();
        //cout << cTree.m_key << endl;
        string temp = "";
        strstream stm;
        stm << cManage->search(cTree.m_key);
        stm >> temp;
        cTree.m_payload = temp;
        cTracker.get_root()->tree_insert(cTree);
    }
    cout << "Client Tree loaded succesfully!" << endl;
    cout << "Loading Phone Tree..." << endl;
    Elem pTree;
    RootTracker pTracker;
    Node* pRoot_ptr = new Node(pTracker);
    pTracker.set_root (null_ptr, pRoot_ptr);

    for (int i = 1; i <= pManage->getCount(); ++i){
        pTree.m_key = pManage->read(i)->getClientID();
        pTree.m_payload = (pManage->search(pManage->read(i)->getClientID()));
        pTracker.get_root()->tree_insert(pTree);
    }

    Elem wanted;
    wanted.m_key = "1801199310042";
    Node* ultimo;
    Elem& result = cTracker.get_root()->search (wanted, ultimo);

    cout << "Phone Tree loaded succesfully!" << endl;    


    Report* R = new Report();
    ReportIndex* RI = new ReportIndex();

    Client* NewClient;
    Rates* NewRate;
    Phone* NewPhone;
    
    int user_sel_main = -1;
    int user_sel = -1;
    int user_sel_sub = -1;
    string Valid = "";
    ostringstream ss;
    system("clear");
    do {
        system("clear");
        //cout << "RRN = " << result.m_payload << endl;
        cout << "SISTEMA GESTOR DE COBROS" << endl;
        cout << "# MENU PRINCIPAL #" << endl;
        cout << "1. Mantenimiento" << endl;
        cout << "2. Reportes Sin Indices" << endl;
        cout << "3. Reportes con Indices Lineales" << endl;
        cout << "4. Reportes con Indices con Arbol B" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccion -> ";


        while (true){
            getline(cin,Valid);
            stringstream myStream(Valid);

            if (myStream >> user_sel_main)
                break;
            cout << "La entrada no es valida, Ingrese un valor numerico: " << endl; 
        }
        
        switch (user_sel_main) {
            case 1:
                //Mantenimiento
            do {
                system("clear");
                cout << "  # MENU DE MANTENIMIENTO #" << endl;
                cout << "  1. Clientes" << endl;
                cout << "  2. Telefonos" << endl;
                cout << "  3. Tipos de Telefonos" << endl;
                cout << "  4. Tarifas" << endl;
                cout << "  0. Salir al Menu Principal" << endl;
                cout << "  Seleccion -> ";

                while (true){
                    getline(cin,Valid);
                    stringstream myStream(Valid);

                    if (myStream >> user_sel)
                        break;
                    cout << "La entrada no es valida, Ingrese un valor numerico: " << endl;  
                }

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

                        while (true){
                            getline(cin,Valid);
                            stringstream myStream(Valid);

                            if (myStream >> user_sel_sub)
                                break;
                            cout << "La entrada no es valida, Ingrese un valor numerico: " << endl;  
                        }                        

                        switch (user_sel_sub) {

                            case 1:
                                        //Agregar
                                        //cin.ignore(10, '\n');
                            cout << "Ingrese el ID del Cliente: ";
                            getline(cin,ClientID);
                            cout << "Ingrese el Primer Nombre del Cliente: ";
                            getline(cin,ClientFN);
                            cout << "Ingrese el Apellido del Cliente ";
                            getline(cin,ClientLN);
                            cout << "Ingrese el E-Mail del Cliente: ";
                            getline(cin,ClientEM);
                            cout << "Ingrese la Direccion del Cliente: ";
                            getline(cin,ClientAD);
                            cManage->write(ClientID,ClientFN,ClientLN,ClientEM,ClientAD);

                            break;
                            case 2:
                                        //Buscar
                            cout << "Ingrese el ID del Cliente a Buscar" << endl;
                            cin >> ClientID;

                            if(cManage->search(ClientID) == -1){
                                cout << "No se Encontro el Registro Buscado" << endl;
                            }else {
                                cout << cManage->read(cManage->search(ClientID))->toString() << endl;
                            }

                            break;   

                            case 3:
                                        //Modificar
                            cout << "Ingrese el ID del Cliente a Modificar" << endl;
                            cin >> ClientID;
                            digits = cManage->search(ClientID);

                            if (digits == -1) {
                                cout << "No se encontro el Registro Buscado" << endl;
                            } else {
                                cout << "El Registro Buscado se Encontro, su RRN es " << digits << endl;
                                cout << cManage->read(digits)->toString() << endl;

                                //cin.ignore(10, '\n');
                                cout << "Ingrese el ID del Cliente: ";
                                getline(cin,ClientID);
                                cout << "Ingrese el Primer Nombre del Cliente: ";
                                getline(cin,ClientFN);
                                cout << "Ingrese el Apellido del Cliente ";
                                getline(cin,ClientLN);
                                cout << "Ingrese el E-Mail del Cliente: ";
                                getline(cin,ClientEM);
                                cout << "Ingrese la Direccion del Cliente: ";
                                getline(cin,ClientAD);
                                cManage->modify(digits,ClientID,ClientFN,ClientLN,ClientEM,ClientAD);
                            }
                                        //Validar si el ID no esta siendo utilido

                            break;
                            case 4:
                                        //Borrar
                                        //cin.ignore(10, '\n');
                            cout << "Ingrese el ID del Cliente a eliminar" << endl;
                            cin >> ClientID;
                            digits = cManage->search(ClientID);
                            if (digits == -1){
                                cout << "No se encontro el registro buscado" << endl;
                            } else {
                                if (cManage->erase(digits)){
                                    cout << "Archivo Eliminado Correctamente" << endl;
                                } else {
                                    cout << "Error Eliminando el Registro" << endl;
                                }
                            }
                            break;
                            case 5:
                                        //Listar
                            cManage->list();
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

                        while (true){
                            getline(cin,Valid);
                            stringstream myStream(Valid);

                            if (myStream >> user_sel_sub)
                                break;
                            cout << "La entrada no es valida, Ingrese un valor numerico: " << endl;  
                        } 

                        switch (user_sel_sub) {
                            case 1:
                                        //Agregar
                                        //cin.ignore(10, '\n');
                            cout << "Ingrese Numero de Telefono" <<endl;
                            cin >> PhoneNumber;
                            cout << "Ingrese el Codigo del Tipo del Telefono" <<endl;
                            cin >> PhoneType;
                            cout << "Numero de ID del Cliente" << endl;
                            cin >> ClientID;
                            pManage->write(PhoneNumber,PhoneType,ClientID);

                            break;
                            case 2:
                                        //Buscar
                            cout << "Ingrese el Telefono que desea Buscar" << endl;
                            cin >> PhoneNumber;
                            if(pManage->search(ClientID) == -1){
                                cout << "No se encontro el Registro Buscado" << endl;
                            }else {
                                cout << pManage->read(cManage->search(PhoneNumber))->toString() << endl;
                                            //cout << "El Telfono: " + ClientID + " le pertenece a " + cManage->read(cManage->ClientIndex.find(ClientID)->second)->getClientFN();
                            }
                            break;
                            case 3:
                                        //Modificar
                            cout << "Ingrese el numero de telefono que desea modificar" << endl;
                            //cin.ignore(10, '\n');
                            getline(cin, PhoneNumber);
                            digits = pManage->search(PhoneNumber);
                            if (digits == -1) {
                                cout << "No se encontro el Registro Buscado" << endl;
                            } else {
                                cout << "El Registro Buscado se Encontro, su RRN es " << digits << endl;
                                cout << pManage->read(digits)->toString() << endl;

                                //cin.ignore(10, '\n');
                                cout << "Ingrese el Nuevo numero de telefono: ";
                                getline(cin,PhoneNumber);
                                cout << "Ingrese el Nuevo tipo de telefono: ";
                                getline(cin,PhoneType);
                                cout << "Ingrese el Nuevo ID del usuario propietario: ";
                                getline(cin,ClientID);

                                pManage->modify(digits,PhoneNumber,PhoneType,ClientID);
                            }
                            break;
                            case 4:
                                        //Borrar
                            //cin.ignore(10, '\n');
                            cout << "Ingrese el numero de telefono a eliminar" << endl;
                            cin >> PhoneNumber;
                            digits = pManage->search(PhoneNumber);
                            if (digits == -1){
                                cout << "No se encontro el registro buscado" << endl;
                            } else {
                                if (pManage->erase(digits)){
                                    cout << "Archivo Eliminado Correctamente" << endl;
                                } else {
                                    cout << "Error Eliminando el Registro" << endl;
                                }
                            }
                            break;
                            case 5:
                                        //Listar

                            pManage->list();

                            break;
                        }

                    } while (user_sel_sub != 0);
                    break;
                    case 3:
                            //Tipos de Telefonos
                    do {

                        cout << "    # TIPOS DE TELEFONOS #" << endl;
                        cout << "    1. Buscar" << endl;
                        cout << "    2. Listar" << endl;
                        cout << "    0. Salir al Menu de Mantenimiento" << endl;
                        cout << "    Seleccion -> ";

                        while (true){
                            getline(cin,Valid);
                            stringstream myStream(Valid);

                            if (myStream >> user_sel_sub)
                                break;
                            cout << "La entrada no es valida, Ingrese un valor numerico: " << endl;  
                        } 

                        switch (user_sel_sub) {

                            case 1:
                                        //Buscar
                            cout << "Ingrese el Tipo de Telefono a Buscar" << endl;
                            cin >> PhoneType;
                            digits = ptManage->search(PhoneType);
                            if (digits == -1)
                            {
                                cout << "No se encontro el Registro Buscado" << endl;
                            } else {
                                cout << "El Registro Buscado se encontro, su RRN es " + digits << endl;
                                (ptManage->read(digits))->toString();
                            }
                            break;

                            case 2:
                                        //Listar

                            for (int i = 1; i < ptManage->getCount(); ++i)
                            {
                                cout << (ptManage->read(i))->toString() << endl;

                            }
                            break;
                        }

                    } while (user_sel_sub != 0);
                    break;
                    case 4:
                            //Tarifas
                    do {

                        cout << "    # TARIFAS #" << endl;
                        cout << "    1. Buscar" << endl;
                        cout << "    2. Listar" << endl;
                        cout << "    0. Salir al Menu de Mantenimiento" << endl;
                        cout << "    Seleccion -> ";
                        
                        while (true){
                            getline(cin,Valid);
                            stringstream myStream(Valid);

                            if (myStream >> user_sel_sub)
                                break;
                            cout << "La entrada no es valida, Ingrese un valor numerico: " << endl;  
                        } 

                        switch (user_sel_sub) {

                            case 1:
                                        //Buscar

                            break;

                            case 2:
                                        //Listar
                            for (int i = 1; i < rManage->getCount(); ++i)
                            {
                                cout << (rManage->read(i))->toString() << endl;
                            }
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
                    //system("clear");
                cout << "  # REPORTES SIN INDICES #" << endl;
                cout << "  1. Llamada por Cliente por Rango de Fecha" << endl;
                cout << "  2. Generar Todas las Facturas por Rango de Fecha" << endl;
                cout << "  0. Salir al Menu Principal" << endl;
                cout << "  Seleccion -> ";
                
                while (true){
                    getline(cin,Valid);
                    stringstream myStream(Valid);

                    if (myStream >> user_sel)
                        break;
                    cout << "La entrada no es valida, Ingrese un valor numerico: " << endl;  
                } 

                switch (user_sel) {
                    case 1:
                            //Cliente x rango
                    //cin.ignore(10, '\n');
                    cout << "Ingrese el numero de Identidad: " << endl;
                    cin >> ClientID;
                    cout << "Ingrese el rango de inicio (Ejemplo DDMMAAAA -> 01042012):" << endl;
                    cin >> ClientAD;
                    cout << "Ingrese el fin de rango (Ejemplo DDMMAAAA -> 01042012): " <<  endl;
                    cin >> ClientLN;
                    R->open();
                    R->PrintReportClient(ClientID,ClientAD,ClientLN);
                    R->close();
                    cout << "Reporte generado, Favor revise el archivo /Reports/ReportL.txt para ver el resultado" << endl;
                    break;
                    case 2:
                            //Todas las facturas x rango
                    //cin.ignore(10, '\n');
                    cout << "Ingrese el rango de inicio (Ejemplo DDMMAAAA -> 01042012):" << endl;
                    getline(cin,ClientAD);
                    cout << "Ingrese el fin de rango (Ejemplo DDMMAAAA -> 01042012): " <<  endl;
                    getline(cin, ClientLN);
                    R->open();
                    for (int i = 1; i <= cManage->getCount(); ++i){
                        R->PrintReportClient(cManage->read(i)->getClientID(),ClientAD,ClientLN);
                    }
                    R->close();
                    cout << "Reporte generado, Favor revise el archivo /Reports/ReportL.txt para ver el resultado" << endl;
                    break;
                }
            } while (user_sel != 0);
                //Fin Reportes sin indices
            break;
            case 3:
                //Reportes con indices lineales
            do {
                cout << "  # REPORTES CON INDICES LINEALES #" << endl;
                cout << "  1. Llamada por Cliente por Rango de Fecha" << endl;
                cout << "  2. Generar Todas las Facturas por Rango de Fecha" << endl;
                cout << "  0. Salir al Menu Principal" << endl;
                cout << "  Seleccion -> ";

                while (true){
                    getline(cin,Valid);
                    stringstream myStream(Valid);

                    if (myStream >> user_sel)
                        break;
                    cout << "La entrada no es valida, Ingrese un valor numerico: " << endl;  
                } 

                switch (user_sel) {
                    case 1:
                            //Cliente x rango
                    //cin.ignore(10, '\n');
                    cout << "Ingrese el numero de Identidad: " << endl;
                    cin >> ClientID;
                    cout << "Ingrese el rango de inicio (Ejemplo DDMMAAAA -> 01042012):" << endl;
                    cin >> ClientAD;
                    cout << "Ingrese el fin de rango (Ejemplo DDMMAAAA -> 01042012): " <<  endl;
                    cin >> ClientLN;
                    RI->open();
                    RI->PrintReportClient(ClientID,ClientAD,ClientLN);
                    RI->close();
                    cout << "Reporte generado, Favor revise el archivo /Reports/ReportR.txt para ver el resultado" << endl;
                    break;
                    case 2:
                            //Todas las facturas x rango
                    //cin.ignore(10, '\n');
                    cout << "Ingrese el rango de inicio (Ejemplo DDMMAAAA -> 01042012):" << endl;
                    getline(cin,ClientAD);
                    cout << "Ingrese el fin de rango (Ejemplo DDMMAAAA -> 01042012): " <<  endl;
                    getline(cin, ClientLN);
                    RI->open();
                    for (int i = 1; i <= cManage->getCount(); ++i){
                        RI->PrintReportClient(cManage->read(i)->getClientID(),ClientAD,ClientLN);
                    }
                    RI->close();
                    cout << "Reporte generado, Favor revise el archivo /Reports/ReportR.txt para ver el resultado" << endl;
                    break;
                }

            } while (user_sel != 0);
                //Fin Reportes con indices lineales
            break;
            case 4:
                //Reportes con indices con arbol B
            do {

                cout << "  # REPORTES CON INDICES CON ARBOL B #" << endl;
                cout << "  1. Llamada por Cliente por Rango de Fecha" << endl;
                cout << "  2. Generar Todas las Facturas por Rango de Fecha" << endl;
                cout << "  0. Salir al Menu Principal" << endl;
                cout << "  Seleccion -> ";
                
                while (true){
                    getline(cin,Valid);
                    stringstream myStream(Valid);

                    if (myStream >> user_sel)
                        break;
                    cout << "La entrada no es valida, Ingrese un valor numerico: " << endl;  
                } 

                switch (user_sel) {
                    case 1:
                            //Cliente x rango
                        //cin.ignore(10, '\n');
                        cout << "Ingrese el numero de Identidad: " << endl;
                        cin >> ClientID;
                        cout << "Ingrese el rango de inicio (Ejemplo DDMMAAAA -> 01042012):" << endl;
                        cin >> ClientAD;
                        cout << "Ingrese el fin de rango (Ejemplo DDMMAAAA -> 01042012): " <<  endl;
                        cin >> ClientLN;
                        wanted.m_key = ClientID;
                        result = cTracker.get_root()->search (wanted, ultimo);
                        cout << result.m_payload << endl;

                    break;
                    case 2:
                            //Todas las facturas x rango
                         //cin.ignore(10, '\n');
                        cout << "Ingrese el rango de inicio (Ejemplo DDMMAAAA -> 01042012):" << endl;
                        getline(cin,ClientAD);
                        cout << "Ingrese el fin de rango (Ejemplo DDMMAAAA -> 01042012): " <<  endl;
                        getline(cin, ClientLN);
                        for (int i = 1; i <= cManage->getCount(); ++i){
                            RI->PrintReportClient(cManage->read(i)->getClientID(),ClientAD,ClientLN);
                        }
                    break;
                }

            } while (user_sel != 0);
                //Fin Reportes con indices con arbol B
            break;
        }
        
        
    } while (user_sel_main != 0);
    cManage->close();
    pManage->close();
    system("clear");
    return 0;
}

