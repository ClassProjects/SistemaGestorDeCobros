//
//  Call.cpp
//  Sistema Gestor de Cobros
//
//  Created by Jorge Caballero on 2/12/13.
//  Copyright (c) 2013 Jorge Caballero. All rights reserved.
//

#include "Call.h"

using namespace std;

Call::Call(){

	strcpy(FromNumber,"");
	strcpy(DestinationNumber,"");
	strcpy(InitialTime,"");
	strcpy(EndTime,"");
}

Call::Call(string pFromNumber, string pDestinationNumber, string pInitialTime, string pEndTime){
	strcpy(FromNumber ,pFromNumber.c_str());
	strcpy(DestinationNumber ,pDestinationNumber.c_str());
	strcpy(InitialTime ,pInitialTime.c_str());
	strcpy(EndTime ,pEndTime.c_str());
}

void Call::setFromNumber(string pFromNumber){strcpy(FromNumber ,pFromNumber.c_str());}
void Call::setDestinationNumber(string pDestinationNumber){strcpy(DestinationNumber ,pDestinationNumber.c_str());}
void Call::setInitialTime(string pInitialTime){strcpy(InitialTime ,pInitialTime.c_str());}
void Call::setEndTime(string pEndTime){strcpy(EndTime ,pEndTime.c_str());}

string Call::getFromNumber(){return FromNumber;}
string Call::getDestinationNumber(){return DestinationNumber;}
string Call::getInitialTime(){return InitialTime;}
string Call::getEndTime(){return EndTime;}