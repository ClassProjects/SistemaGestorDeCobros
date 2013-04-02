//
//  RatesFile.cpp
//  Sistema Gestor de Cobros
//
//  Created by Jorge Caballero on 2/12/13.
//  Copyright (c) 2013 Jorge Caballero. All rights reserved.
//

#include "RatesFile.h"
#include <string>
#include <cstring>
#include <vector>

using namespace std;

RatesFile::RatesFile(){
	stream.open ("./lib/files/RATES.txt");
	delstream.open ("./lib/files/del/RATES.txt");
	/*if (stream.is_open())
	{
		cout << "File RATESFILE open Succesfully" << endl;
	} else {
		cout << "Error opening RATESFILE - Del" << endl;
	}

	if (delstream.is_open())
	{
		cout << "File RATESFILE open Succesfully" << endl;
	} else {
		cout << "Error opening RATESFILE - Del" << endl;
	}*/
}


void RatesFile::open(){

}

Rates* RatesFile::read(int RRN){
	stream.seekg(0);
	stream.read(buffer, 20);

	string RateCode = "", PhoneTypeID = "", RateInitial = "", RateEnd = "", RatePrice = "";

	    if (RRN == 1){
		for (int i = 0; i < sizeof(buffer); ++i){
			if(buffer[i] != ' ' && i < 2){
				RateCode+= buffer[i];
            }else if (buffer[i] != ' ' && i < 2){
                PhoneTypeID+= buffer[i];
            }else if(buffer[i] != ' ' && i < 6){
                RateInitial+= buffer[i];
            }else if(buffer[i] != ' ' && i < 6){
                RateEnd+= buffer[i];
            }else if(buffer[i] != ' ' && i < 4){
                RatePrice+= buffer[i];
            }
        }
        
        Rates* retVal = new Rates(RateCode, PhoneTypeID, RateInitial, RateEnd, RatePrice);
        return retVal;
        //cout << RateCode + " " + PhoneTypeID + " " + RateInitial + " " + ClientEM + " " + ClientAD << endl;
    }else{
        RRN = (RRN*20)-20;
        stream.seekg(RRN);
        stream.read(buffer, 20);
        
        for (int i = 0; i < sizeof(buffer); ++i){
            if(buffer[i] != ' ' && i < 2){
                RateCode+= buffer[i];
            }else if (buffer[i] != ' ' && i < 2){
                PhoneTypeID+= buffer[i];
            }else if(buffer[i] != ' ' && i < 6){
                RateInitial+= buffer[i];
            }else if(buffer[i] != ' ' && i < 6){
                RateEnd+= buffer[i];
            }else if(buffer[i] != ' ' && i < 4){
                RatePrice+= buffer[i];
            }
        }
        
        Rates* retVal = new Rates(RateCode, PhoneTypeID, RateInitial, RateEnd, RatePrice);
        return retVal;
        //cout << RateCode + " " + PhoneTypeID + " " + RateInitial + " " + ClientEM + " " + ClientAD << endl;
    }

}

bool RatesFile::write (Rates* phoneType){

}

int RatesFile::getCount(){
	stream.seekg (0, ios::end);
  	int length = stream.tellg();
  	stream.seekg (0, ios::beg);
  	return length/25;
}

int RatesFile::search(string term){
    for (int i = 1; i <= this->getCount(); ++i){
       if (read(i)->getRateCode() == term){
            return i;
            } 
        }
        return -1;
}

bool RatesFile::erase(int RRN){
	//
}

void RatesFile::close(){
	stream.close();
	delstream.close();

}

void RatesFile::replace(int RRN, Rates* newPhoneType){

}