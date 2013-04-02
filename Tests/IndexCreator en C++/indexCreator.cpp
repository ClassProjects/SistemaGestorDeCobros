//#include <stdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

#include "ClientFile.h"
#include "Client.h"

using namespace std;

int main(){
	//Parameters - Change these acording on your needs
	int inFileBufferSize = 123;
	int indexSize = 13;
	int rrnSize = 5;
	//ifstream instream ("CLIENTS.txt"); 
	ofstream output ("CLIENT_INDEX.txt");

	//Don't touch this shit!
	char inbuffer[inFileBufferSize];
	string salida;
	//string rrn;
	string fileText;
	ClientFile *cManage = new ClientFile();
	Client *client;


	//Magic
  	for (int i = 1; i < cManage->getCount(); ++i){

		client = cManage->read(i);
		
		ostringstream convert;
		convert << i;
        string rrn = convert.str();

        while(rrn.length() <= 5){
        	rrn = "0" + rrn;
        }

        salida = rrn + client->getClientID();

        output.write(salida.c_str(),salida.length());

  	}

  	return 0;

}