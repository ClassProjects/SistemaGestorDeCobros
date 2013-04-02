//
//  Rates.cpp
//  Sistema Gestor de Cobros
//
//  Created by Jorge Caballero on 2/12/13.
//  Copyright (c) 2013 Jorge Caballero. All rights reserved.
//

#include "Rates.h"
#include <cstring>

using namespace std;

Rates::Rates(){
	strcpy(RateCode,"");
	strcpy(PhoneTypeID,"");
	strcpy(RateInitial,"");
	strcpy(RateEnd,"");
	strcpy(RatePrice,"");
}

Rates::Rates(string pRateCode, string pPhoneTypeID, string pRateInitial, string pRateEnd, string pRatePrice){
	strcpy(RateCode, pRateCode.c_str());
	strcpy(PhoneTypeID, pPhoneTypeID.c_str());
	strcpy(RateInitial, pRateInitial.c_str());
	strcpy(RateEnd, pRateEnd.c_str());
	strcpy(RatePrice, pRatePrice.c_str());
}

string Rates::toStringFormated(){
	return "";
}

void Rates::setRateCode(string pRateCode){strcpy(RateCode, pRateCode.c_str());}
void Rates::setPhoneTypeID(string pPhoneTypeID){strcpy(PhoneTypeID, pPhoneTypeID.c_str());}
void Rates::setRateInitial(string pRateInitial){strcpy(RateInitial, pRateInitial.c_str());}
void Rates::setRateEnd(string pRateEnd){strcpy(RateEnd, pRateEnd.c_str());}
void Rates::setRatePrice(string pRatePrice){strcpy(RatePrice, pRatePrice.c_str());}

string Rates::getRateCode(){return RateCode;}
string Rates::getPhoneTypeID(){return PhoneTypeID;}
string Rates::getRateInitial(){return RateInitial;}
string Rates::getRateEnd(){return RateEnd;}
string Rates::getRatePrice(){return RatePrice;}

string Rates::toString(){
	return string(RateCode) + "\t" + string(PhoneTypeID) + "\t" + string(RateInitial) + "\t" + string(RateEnd) + "\t" + string(RatePrice);
}