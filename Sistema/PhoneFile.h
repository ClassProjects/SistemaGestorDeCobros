#ifndef __Sistema_Gestor_de_Cobros__PhoneFile__
#define __Sistema_Gestor_de_Cobros__PhoneFile__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "Phone.h"

class PhoneFile
{
	fstream stream;
	fstream delstream;// fstream manejador del archivo
	char buffer[23]; // Buffer con 123 espacios para el registro
public:
	PhoneFile(); // Abre archivo "CLIENTS.txt" y "CLIENTDEL.txt"
	void open(); // Opens files
	Phone* read(int RRN); // Lee el registro en el numero RRN
	void write (string,string,string); // Escribe "cliente" al final del archivo
	int getCount(); //Retorna la cantidad de registros en el archivo
	void modify(int, string, string, string);
	int search(string term); //Retorna un RRN del regitro solicitado, retorna -1 si no encontro el registro
	void erase(int RRN); // Elimina el registro en el numero RRN
	void close();
	Phone* read2(int RRN);
	//void replace(int RRN, Phone* newPhone);
	~PhoneFile(); // Mutila
};

#endif /* defined(__Sistema_Gestor_de_Cobros__PhoneFile__) */
