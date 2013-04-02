#ifndef __Sistema_Gestor_de_Cobros__ClientListIndex__
#define __Sistema_Gestor_de_Cobros__ClientListIndex__

#include "ClientFile.h"
#include "Client.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <map>


using namespace std;

class ClientListIndex{
	fstream stream;
	fstream delstream;// fstream manejador del archivo`
	fstream indexstream;// ftsream manejador de indices
	char bufferIndex[19]; // Buffer con 19 espacios para el registro
	map<string,int> ClientIndex;
	ClientFile* cManage;


public:

	ClientListIndex(); // Abre archivo "CLIENTS.txt" y "CLIENTDEL.txt"
	void open(); // Opens files
	Client* read(int RRN); // Lee el registro en el numero RRN NO FUNCIONA
	void write(string, string, string, string, string); // Escribe "cliente" al final del archivo
	void modify(int, string, string, string, string, string); // Modifica el campo indicado por el usuario en el registro
	int getCount(); //Retorna la cantidad de registros en el archivo
	int search(string); //Retorna un RRN del regitro solicitado, retorna -1 si no encontro el registro
	bool erase(int RRN); // Elimina el registro en el numero RRN
	void close(); //Sera que Cierra?
	void replace(int RRN, Client* newClient); 
	void list();
	~ClientListIndex(); // Mutila
};

#endif /* defined(__Sistema_Gestor_de_Cobros__ClientListIndex__) */
