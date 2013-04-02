#ifndef __Sistema_Gestor_de_Cobros__CallFile__
#define __Sistema_Gestor_de_Cobros__CallFile__

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include "Call.h"

class CallFile{
fstream stream;
fstream delstream;
char buffer[123]; 

public:
	CallFile();
	void open(); // Opens files
	Call* read(int RRN); // Lee el registro en el numero
	void write(string, string, string, string); // Escribe "cliente" al final del archivo
	void modify(int, string, string, string, string); // Modifica el campo indicado por el usuario en el registro
	int getCount(); //Retorna la cantidad de registros en el archivo
	vector<int> search(string); //Retorna un RRN del regitro solicitado, retorna -1 si no encontro el registro
	bool erase(int RRN); // Elimina el registro en el numero RRN
	void close(); //Sera que Cierra?
	void replace(int RRN, Call* newCall); 
	~CallFile();

	/* data */
};


#endif /* defined(__Sistema_Gestor_de_Cobros__CallFile__) */
