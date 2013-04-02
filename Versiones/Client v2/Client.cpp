//
//  Client.cpp
//  Sistema Gestor de Cobros
//
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

	ClientID = "";
	ClientFN = "";
	ClientLN = "";
	ClientEM = "";
	ClientAD = "";
}

Client::Client(string pClientID, string pClientFN, string pClientLN, string pClientEM, string pClientAD){
	ClientID = pClientID;
	ClientFN = pClientFN;
	ClientLN = pClientLN;
	ClientEM = pClientEM;
	ClientAD = pClientAD;
}

void Client::setClientID(string pClientID){ClientID = pClientID;}
void Client::setClientFN(string pClientFN){ClientFN = pClientFN;}
void Client::setClientLN(string pClientLN){ClientLN = pClientLN;}
void Client::setClientEM(string pClientEM){ClientEM = pClientEM;}
void Client::setClientAD(string pClientAD){ClientAD = pClientAD;}

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




