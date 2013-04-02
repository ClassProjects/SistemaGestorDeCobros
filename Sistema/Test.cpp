#include "Client.h"
#include <iostream>
#include <string>


	int main (){

	cout << "Cuantos Clientes Quiere Ingresar: " << endl;
	int Num = 0;
	cin >> Num;
	Client * C_Array[Num];
	
	for (int i = 0; i < Num; i++){
	string ID,FN,SN,EM,AD;
	cout << "Ingrese el ID del Cliente" << endl;
	cin >> ID;
	cout << "Ingrese el Nombre del Cliente" << endl;
	cin >> FN;
	cout << "Ingrese el Segundo Nombre del CLiente" << endl;
	cin >> SN;
	cout << "Ingrese el Correo " << endl;
	cin >> EM;
	cout << "Ingrese Direccion del Domicilio" << endl;
	cin >> AD;

	C_Array[i]= new Client(ID,FN,SN,EM,AD);
	}

	cout << endl;
	cout << endl;
	for (int i = 0; i < Num; i++){
	string Temp = C_Array[i]->getClientID() + C_Array[i]->getClientFN() + C_Array[i]->getClientLN() + C_Array[i]->getClientEM() + C_Array[i]->getClientAD();
	cout << Temp << endl;
	delete C_Array[i];
	cout << endl;
	}

	return 0;
}
