#ifndef __Sistema_Gestor_de_Cobros__PhoneListIndex__
#define __Sistema_Gestor_de_Cobros__PhoneListIndex__

#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>

#include "Phone.h"
#include "PhoneFile.h"

class PhoneListIndex{
	fstream stream;
	fstream delstream;// fstream manejador del archivo`
	fstream indexstream;// ftsream manejador de indices
	fstream indexstream2;
	char buffer1[19]; //RRN y ClientID
	char buffer2[14]; //RRN y Phone Numba
	multimap<string,int> PhoneIndex1; // ID y RRN
	map<string,int> PhoneIndex2; //RRN y Number
	PhoneFile* pManage;
	

public:

	PhoneListIndex(); // Abre archivo "CLIENTS.txt" y "CLIENTDEL.txt"
	void open(); // Opens files
	Phone* read(int RRN); // Lee el registro en el numero RRN NO FUNCIONA
	void write(string, string, string); // Escribe "cliente" al final del archivo
	void modify(int, string, string, string); // Modifica el campo indicado por el usuario en el registro
	int getCount(); //Retorna la cantidad de registros en el archivo
	int search(string); //Retorna un RRN del regitro solicitado, retorna -1 si no encontro el registro
	bool erase(int RRN); // Elimina el registro en el numero RRN
	void close(); //Sera que Cierra?
	void replace(int RRN, Phone* newPhone); 
	void list();
	~PhoneListIndex(); // Mutila
};
#endif /* defined(__Sistema_Gestor_de_Cobros__PhoneListIndex__) */
