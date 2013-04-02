//
//  Client.h
//  Sistema Gestor de Cobros
//
//  Created by Guillermo E. Mazzoni & Jorge Caballero on 2/13/13.
//  Copyright (c) 2013 Jorge Caballero. All rights reserved.
//

#ifndef __Sistema_Gestor_de_Cobros__Client__
#define __Sistema_Gestor_de_Cobros__Client__

#include <iostream>
#include <string>

using namespace std;

class Client {
    
private:
	char ClientID[13];
	char ClientFN[20];
	char ClientLN[20];
	char ClientEM[30];
	char ClientAD[40];
    
public:
	Client();
	Client(string,string,string,string,string);
    
	void setClientID(string);
	void setClientFN(string);
	void setClientLN(string);
	void setClientEM(string);
	void setClientAD(string);
    
	string getClientID();
	string getClientFN();
	string getClientLN();
	string getClientEM();
	string getClientAD();

	string toString();
};

#endif /* defined(__Sistema_Gestor_de_Cobros__Client__) */
