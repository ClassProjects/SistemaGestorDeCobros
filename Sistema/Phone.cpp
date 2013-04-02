//
//  Phone.cpp
//  Sistema Gestor de Cobros
//
//  Created by Jorge Caballero on 2/12/13.
//  Copyright (c) 2013 Jorge Caballero. All rights reserved.
//

#include "Phone.h"
#include <iostream>
#include <string>
#include <cstring>

Phone::Phone(){
	strcpy(PhoneNumber,"");
	strcpy(PhoneType,"");
	strcpy(ClientID,"");

}

Phone::Phone(string pPhoneNumber,string pPhoneType, string pClientID){
	strcpy(PhoneNumber, pPhoneNumber.c_str());
	strcpy(PhoneType, pPhoneType.c_str());
	strcpy(ClientID, pClientID.c_str());
}

void Phone::setPhoneNumber(string pPhoneNumber){strcpy(PhoneNumber, pPhoneNumber.c_str());}
void Phone::setPhoneType(string pPhoneType){strcpy(PhoneType, pPhoneType.c_str());}

string Phone::getPhoneNumber(){return PhoneNumber;}
string Phone::getPhoneType(){return PhoneType;}
string Phone::getClientID(){return ClientID;}

string Phone::toString(){
	return string(PhoneNumber) + " " + string(PhoneType) + " " + string(ClientID);
}


