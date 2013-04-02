//
//  Client.cpp
//  Sistema Gestor de Cobros
//  Created by Jorge Caballero on 2/13/13.
//  Copyright (c) 2013 Jorge Caballero. All rights reserved.
//

#include "Client.h"
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

Client::Client(){
    strcpy(ClientID,"");
    strcpy(ClientFN,"");
	strcpy(ClientLN,"");
	strcpy(ClientEM,"");
	strcpy(ClientAD,"");
}

Client::Client(string pClientID, string pClientFN, string pClientLN, string pClientEM, string pClientAD){
	strcpy(ClientID, pClientID.c_str());
	strcpy(ClientFN, pClientFN.c_str());
	strcpy(ClientLN, pClientLN.c_str());
	strcpy(ClientEM, pClientEM.c_str());
	strcpy(ClientAD, pClientAD.c_str());
}

void Client::setClientID(string pClientID){strcpy(ClientID, pClientID.c_str());}
void Client::setClientFN(string pClientFN){strcpy(ClientFN, pClientFN.c_str());}
void Client::setClientLN(string pClientLN){strcpy(ClientLN, pClientLN.c_str());}
void Client::setClientEM(string pClientEM){strcpy(ClientEM, pClientEM.c_str());}
void Client::setClientAD(string pClientAD){strcpy(ClientAD, pClientAD.c_str());}

string Client::getClientID(){return ClientID;}
string Client::getClientFN(){return ClientFN;}
string Client::getClientLN(){return ClientLN;}
string Client::getClientEM(){return ClientEM;}
string Client::getClientAD(){return ClientAD;}

string Client::toString(){
	//string buffToString = "ID: -" + string(ClientID)+ "-\nNombre: -" + string(ClientFN) + "- \nApellido: -" + string(ClientLN) + "-\nEmail: -" + string(ClientEM) + "- \nAddress: -" + string(ClientAD) +"-\n";
	string buffToString = string(ClientID)+ " " + string(ClientFN) + " " + string(ClientLN) + " " +  string(ClientEM) + " " +string(ClientAD);	
	return buffToString;
}




