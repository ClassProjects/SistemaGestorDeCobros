//
//  PhoneType.cpp
//  Sistema Gestor de Cobros
//
//  Created by Jorge Caballero on 2/12/13.
//  Copyright (c) 2013 Jorge Caballero. All rights reserved.
//

#include "PhoneType.h"
#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

PhoneType::PhoneType(){
	strcpy(PhoneTypeID,"");
	strcpy(PhoneDescription,"");
	strcpy(BaseRate,"");
}

PhoneType::PhoneType(string pPhoneTypeID, string pPhoneDescription, string pBaseRate){
	strcpy(PhoneTypeID, pPhoneTypeID.c_str());
	strcpy(PhoneDescription, pPhoneDescription.c_str());
	strcpy(BaseRate, pBaseRate.c_str());
}

void PhoneType::setPhoneTypeID(string pPhoneTypeID){strcpy(PhoneTypeID, pPhoneTypeID.c_str());}
void PhoneType::setPhoneDescription(string pPhoneDescription){strcpy(PhoneDescription, pPhoneDescription.c_str());}
void PhoneType::setBaseRate(string pBaseRate){strcpy(BaseRate, pBaseRate.c_str());}

string PhoneType::getPhoneTypeID(){return PhoneTypeID;}
string PhoneType::getPhoneDescription(){return PhoneDescription;}
string PhoneType::getBaseRate(){return BaseRate;}

string PhoneType::toString(){
	string retVal = string(PhoneTypeID) + "\t" + string(PhoneDescription) + "\t" + string(BaseRate);
	return retVal;
}