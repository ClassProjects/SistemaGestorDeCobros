//
//  PhoneTypeFile.cpp
//  Sistema Gestor de Cobros
//
//  Created by Guillermo E. Mazzoni & Jorge Caballero on 2/12/2.
//  Copyright (c) 2013 Jorge Caballero. All rights reserved.
//

#include "PhoneTypeFile.h"
#include "PhoneType.h"
#include <string>
#include <cstring>
#include <vector>

using namespace std;

PhoneTypeFile::PhoneTypeFile(){
	stream.open ("./lib/files/PHONETYPES.txt");
	delstream.open ("./lib/files/del/PHONETYPES.txt");
	/*if (stream.is_open())
	{
		cout << "File PHONETYPE open Succesfully" << endl;
	} else {
		cout << "Error opening PHONETYPE - Del" << endl;
	}

	if (delstream.is_open())
	{
		cout << "File PHONETYPE open Succesfully" << endl;
	} else {
		cout << "Error opening PHONETYPE - Del" << endl;
	} */
}


void PhoneTypeFile::open(){

}

PhoneType* PhoneTypeFile::read(int RRN){
	stream.seekg(0);
	stream.read(buffer, 26);

	string PhoneTypeID = "", PhoneDescription = "", BaseRate = "";

	    if (RRN == 1){
		for (int i = 0; i < sizeof(buffer); ++i){
			if(buffer[i] != ' ' && i < 2){
				PhoneTypeID+= buffer[i];
            }else if (buffer[i] != ' ' && i < 22){
                PhoneDescription+= buffer[i];
            }else if(buffer[i] != ' ' && i < 26){
                BaseRate+= buffer[i];
            }
        }
        
        PhoneType* retVal = new PhoneType(PhoneTypeID, PhoneDescription, BaseRate);
        return retVal;
        //cout << PhoneTypeID + " " + PhoneDescription + " " + BaseRate + " " + ClientEM + " " + ClientAD << endl;
    }else{
        RRN = (RRN*26)-26;
        stream.seekg(RRN);
        stream.read(buffer, 26);
        
        for (int i = 0; i < sizeof(buffer); ++i){
            if(buffer[i] != ' ' && i < 2){
                PhoneTypeID+= buffer[i];
            }else if (buffer[i] != ' ' && i < 22){
                PhoneDescription+= buffer[i];
            }else if(buffer[i] != ' ' && i < 26){
                BaseRate+= buffer[i];
            }
        }
        
        PhoneType* retVal = new PhoneType(PhoneTypeID, PhoneDescription, BaseRate);
        return retVal;
        //cout << PhoneTypeID + " " + PhoneDescription + " " + BaseRate + " " + ClientEM + " " + ClientAD << endl;
    }

}

bool PhoneTypeFile::write (PhoneType* phoneType){

}

int PhoneTypeFile::getCount(){
	stream.seekg (0, ios::end);
  	int length = stream.tellg();
  	stream.seekg (0, ios::beg);
  	return length/25;
}

int PhoneTypeFile::search(string term){
    for (int i = 1; i <= this->getCount(); ++i){
       if (read(i)->getPhoneTypeID() == term){
            return i;
            } 
        }
        return -1;
}

bool PhoneTypeFile::erase(int RRN){
	//
}

void PhoneTypeFile::close(){
	stream.close();
	delstream.close();

}

void PhoneTypeFile::replace(int RRN, PhoneType* newPhoneType){

}
