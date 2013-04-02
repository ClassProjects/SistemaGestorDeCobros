#ifndef __Sistema_Gestor_de_Cobros__PhoneTypeFile__
#define __Sistema_Gestor_de_Cobros__PhoneTypeFile__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "PhoneType.h"

class PhoneTypeFile
{
	fstream stream;
	fstream delstream;// fstream manejador del archivo
	char buffer[26]; // Buffer con 123 espacios para el registro
public:
	PhoneTypeFile(); // Abre archivo "CLIENTS.txt" y "CLIENTDEL.txt"
	void open(); // Opens files
	PhoneType* read(int RRN); // Lee el registro en el numero RRN
	bool write (PhoneType* phoneType); // Escribe "cliente" al final del archivo
	int getCount(); //Retorna la cantidad de registros en el archivo
	int search(string term); //Retorna un RRN del regitro solicitado, retorna -1 si no encontro el registro
	bool erase(int RRN); // Elimina el registro en el numero RRN
	void close();
	PhoneType* read2(int RRN);
	void replace(int RRN, PhoneType* newClient);
	~PhoneTypeFile(); // Mutila
};

#endif /* defined(__Sistema_Gestor_de_Cobros__PhoneTypeFile__) */
