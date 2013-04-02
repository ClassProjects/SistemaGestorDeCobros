#include "ClientListIndex.h"
#include "ClientFile.h"
#include "Client.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

ClientListIndex::ClientListIndex(){
	//stream.open ("./lib/indexes/CLIENTS.txt");
	//delstream.open ("./lib/indexes/del/CLIENTS.txt");
	indexstream.open("./lib/indexes/CLIENT_INDEX.txt");

	cManage = new ClientFile();
	
	/*if (stream.is_open())
	{
		cout << "File ClientListIndex open Succesfully" << endl;
	} else {
		cout << "Error opening ClientListIndex" << endl;
	}

	if (delstream.is_open())
	{
		cout << "File clidel open Succesfully" << endl;
	} else {
		cout << "Error opening clidel" << endl;
	}*/

	int lengthIndex = 0;
	indexstream.seekg(0,ios::end);
	lengthIndex = indexstream.tellg();
	indexstream.seekg(0,ios::beg);
	char* bufferIndex = new char[19];
	for(int i = 1; i <= lengthIndex/19; i++){

		int RRN = (i*19) - 19;
		indexstream.seekg(RRN);
		indexstream.read(bufferIndex,19);
		string TempRRN_S = "", TempClientID_S = "";
		int TempRRN_I = 0;
		 

		for(int j = 0; j < 19; j++){
			if(j < 6){
				TempRRN_S+= bufferIndex[j];

			}else if(j < 19){
				TempClientID_S+= bufferIndex[j];
			}

			istringstream (TempRRN_S) >> TempRRN_I;
		}
		
		ClientIndex.insert(pair<string, int>(TempClientID_S,TempRRN_I));
	}

	indexstream.close();

}
void ClientListIndex::open(){

	for (auto& x: ClientIndex) {
    	cout << x.first << " : " << x.second << '\n';
    }

}

Client* ClientListIndex::read(int RRN_Index){
	return	cManage->read(RRN_Index);
	}

void ClientListIndex::write(string pClientID, string pClientFN, string pClientLN, string pClientEM, string pClientAD) {
	
	cManage->write(pClientID, pClientFN, pClientLN, pClientEM, pClientAD);


	ClientIndex.insert(pair<string, int>(pClientID,cManage->search(pClientID)));


	/*for (auto& x: ClientIndex) {
    	cout << x.first << " : " << x.second << '\n';
    }*/
	
}

void ClientListIndex::modify(int pRRN_Index, string pClientID, string pClientFN, string pClientLN, string pClientEM, string pClientAD) {
	 ClientIndex.erase(cManage->read(pRRN_Index)->getClientID());
	 cManage->modify(pRRN_Index, pClientID, pClientFN, pClientLN, pClientEM, pClientAD);
	 ClientIndex.insert(pair<string, int>(pClientID,cManage->search(pClientID)));

}

int ClientListIndex::getCount(){ 
	return ClientIndex.size()+1;
}

int ClientListIndex::search(string pClientID){
	return	ClientIndex.find(pClientID)->second;
}

void ClientListIndex::close(){

	indexstream.open("./lib/indexes/CLIENT_INDEX.txt", ios::out|ios::trunc);

	for (auto& x: ClientIndex) {
		string rrn = to_string(x.second);

				while(rrn.length() <= 5){
					rrn = "0" + rrn;
				}
		string retval = rrn + x.first;
    	indexstream.write(retval.c_str(),retval.length());
    }
	indexstream.close();
}

bool ClientListIndex::erase(int pRRN_Index){
	ClientIndex.erase(cManage->read(pRRN_Index)->getClientID());
	cManage->erase(pRRN_Index);
	return true;

}

void ClientListIndex::list(){
	for (auto& x: ClientIndex) {
    	cout << cManage->read(x.second)->toString() << '\n';
    }
}