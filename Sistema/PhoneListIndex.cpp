//
//  PhoneListIndex.cpp
//  Sistema Gestor de Cobros
//
//  Created by Jorge Caballero on 2/12/13.
//  Copyright (c) 2013 Jorge Caballero. All rights reserved.
//

#include "PhoneListIndex.h"
#include "PhoneFile.h"
#include "Phone.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

PhoneListIndex::PhoneListIndex(){
	pManage = new PhoneFile();
	indexstream.open("./lib/indexes/PhoneIndex_1.txt");
	
	int lengthIndex = 0;
	indexstream.seekg(0,ios::end);
	lengthIndex = indexstream.tellg();
	indexstream.seekg(0,ios::beg);

	for(int i = 1; i <= lengthIndex/19; i++){
		int RRN = (i*19) - 19;
		indexstream.seekg(RRN);
		indexstream.read(buffer1,19);

		string TempClientID_S = "", TempRRN_S = ""; int TempRRN_I;

		for(int j = 0; j < 19; j++){
			
			if(j < 6){
				TempRRN_S+= buffer1[j];

			}else if(j < 19){
				TempClientID_S+= buffer1[j];
			}
		}
			istringstream (TempRRN_S) >> TempRRN_I;
			PhoneIndex1.insert(pair<string, int>(TempClientID_S,TempRRN_I));
	}
		indexstream.close();


		indexstream.open("./lib/indexes/PhoneIndex_2.txt");

		lengthIndex = 0;
		indexstream.seekg(0,ios::end);
		lengthIndex = indexstream.tellg();
		indexstream.seekg(0,ios::beg);
		

		for(int i = 1; i <= lengthIndex/14; i++){
			int RRN = (i*14) - 14;
			indexstream.seekg(RRN);
			indexstream.read(buffer2,14);

			string PhoneNumber_S = "", TempRRN_S = ""; int TempRRN_I;

			for(int j = 0; j < 14; j++){
				if(j < 6){
					TempRRN_S+= buffer2[j];

				}else if(j < 14){
					PhoneNumber_S+= buffer2[j];
				}
			}
			istringstream (TempRRN_S) >> TempRRN_I;
			PhoneIndex2.insert(pair<string, int>(PhoneNumber_S,TempRRN_I));
		}	
		indexstream.close();
}

void PhoneListIndex::open(){

}

Phone* PhoneListIndex::read(int RRN_Index){
	return	pManage->read(RRN_Index);
}

void PhoneListIndex::write(string phoneNumber, string phoneType, string ClientID){
	pManage->write(phoneNumber, phoneType, ClientID);

	PhoneIndex1.insert(pair<string, int>(ClientID, pManage->search(phoneNumber)));
	PhoneIndex2.insert(pair<string, int>(phoneNumber, pManage->search(phoneNumber)));
}

void PhoneListIndex::modify(int pRRN_Index, string phoneNumber, string phoneType, string ClientID){


	PhoneIndex1.erase(pManage->read(pRRN_Index)->getClientID()); // ID y RRN
	PhoneIndex2.erase(pManage->read(pRRN_Index)->getPhoneNumber()); //RRN y PhoneNumber

	pManage->modify(pRRN_Index, phoneNumber, phoneType, ClientID);

	PhoneIndex1.insert(pair<string, int>(ClientID,pManage->search(phoneNumber)));
	PhoneIndex2.insert(pair<string, int>(phoneNumber,pManage->search(phoneNumber)));
}

int PhoneListIndex::getCount(){
	
	return PhoneIndex1.size();
}

int PhoneListIndex::search(string term){
	return	PhoneIndex2.find(term)->second;
}

void PhoneListIndex::close(){
	indexstream.open("./lib/indexes/PhoneIndex_1.txt", ios::out|ios::trunc); //RRN - ID

	for (auto& x: PhoneIndex1) {
		string rrn = to_string(x.second);

				while(rrn.length() <= 5){
					rrn = "0" + rrn;
				}
		string retval = rrn + x.first;
    	indexstream.write(retval.c_str(),19);
    }
	indexstream.close();

	indexstream.open("./lib/indexes/PhoneIndex_2.txt", ios::out|ios::trunc); //RRN - Numba

	for (auto& x: PhoneIndex2) {
		string rrn = to_string(x.second);

				while(rrn.length() <= 5){
					rrn = "0" + rrn;
				}
		string retval = rrn + x.first;
    	indexstream.write(retval.c_str(),14);
    }
	indexstream.close();
}

bool PhoneListIndex::erase(int pRRN_Index){
	PhoneIndex1.erase(pManage->read(pRRN_Index)->getClientID()); //RRN y ID
	PhoneIndex2.erase(pManage->read(pRRN_Index)->getPhoneNumber()); //RRN y PhoneNumbers
	pManage->erase(pRRN_Index);
	return true;
}

void PhoneListIndex::list(){
	for (auto& x: PhoneIndex2) {
		cout << pManage->read(x.second)->toString() << endl;
    }

}