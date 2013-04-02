//
//  ClientFile.cpp
//  Sistema Gestor de Cobros
//

#include "ClientFile.h"
#include "Client.h"
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

ClientFile::ClientFile(){
	stream.open ("./lib/indexes/CLIENTS.txt");
	delstream.open ("./lib/indexes/del/CLIENTS.txt");
	/*if (stream.is_open())
	{
		cout << "File CLIENT open Succesfully" << endl;
	} else {
		cout << "Error opening CLIENT" << endl;
	}

	if (delstream.is_open())
	{
		cout << "File clidel open Succesfully" << endl;
	} else {
		cout << "Error opening clidel" << endl;
	}*/
	stream.close();
	delstream.close();

}
void ClientFile::open(){

}

Client* ClientFile::read(int RRN){
	stream.open ("./lib/indexes/CLIENTS.txt");
	delstream.open ("./lib/indexes/del/CLIENTS.txt");
	stream.seekg(0);
	stream.read(buffer, 123);

	string ClientID = "", ClientFN = "", ClientLN = "", ClientEM = "", ClientAD = "";

	    if (RRN == 1){
		for (int i = 0; i < sizeof(buffer); ++i){
			if(i < 13){
				ClientID+= buffer[i];
            }else if (i < 33){
                ClientFN+= buffer[i];
            }else if(i < 53){
                ClientLN+= buffer[i];
            }else if(i < 83){
                ClientEM+= buffer[i];
            }else if(i < 123){
                ClientAD+= buffer[i];
            }
        }
        
        Client* retVal = new Client(ClientID, ClientFN, ClientLN, ClientEM, ClientAD);
        stream.close();
	delstream.close();
        return retVal;

    } else{
        RRN = (RRN*123)-123;
        stream.seekg(RRN);
        stream.read(buffer, 123);
        
        for (int i = 0; i < sizeof(buffer); ++i){
            if(i < 13){
                ClientID+= buffer[i];
            }else if (i < 33){
                ClientFN+= buffer[i];
            }else if(i < 53){
                ClientLN+= buffer[i];
            }else if(i < 83){
                ClientEM+= buffer[i];
            }else if(i < 123){
                ClientAD+= buffer[i];
            }
        }
        
        Client* retVal = new Client(ClientID, ClientFN, ClientLN, ClientEM, ClientAD);
        stream.close();
	delstream.close();
        return retVal;

    }
}    

void ClientFile::write(string pClientID, string pClientFN, string pClientLN, string pClientEM, string pClientAD) {
	stream.open ("./lib/indexes/CLIENTS.txt");
	delstream.open ("./lib/indexes/del/CLIENTS.txt");
	int length = 0;
	delstream.seekg(0,ios::end);
	length = delstream.tellg();
	delstream.seekg(0,ios::beg);
	char* buffer = new char[length];
	string RRN = "", Client_R = "", NewAvailList = "";
	vector <string> AvailList;

	if(pClientID.length() != 13){
		for (int i = pClientID.length()+1; i <= 13 ; ++i){
			pClientID+= " ";
		}
	}

	if(pClientFN.length() != 20){
		for (int i = pClientFN.length()+1; i <= 20 ; ++i){
			pClientFN+= " ";
		}	
	}

	if(pClientLN.length() != 20){
		for (int i = pClientLN.length()+1; i <= 20 ; ++i){
			pClientLN+= " ";
		}	
	}

	if(pClientEM.length() != 30){
		for (int i = pClientEM.length()+1; i <= 30 ; ++i){
			pClientEM+= " ";
		}	
	}

	if(pClientAD.length() != 40){
		for (int i = pClientAD.length()+1; i <= 40 ; ++i){
			pClientAD+= " ";
		}	
	}

	Client_R = pClientID + pClientFN + pClientLN + pClientEM + pClientAD;

	if(length == 0){
		stream.seekp(0,ios::end);
		stream.write(Client_R.c_str(),123);
		delstream.close();
		stream.close();

	} else {
		delstream.read(buffer,length);
		string Temp = "";

		for(int i = 0; i < length; i++){	
			if(buffer[i] != ','){
				Temp+= buffer[i];
			}else{
				AvailList.push_back(Temp);
				Temp = "";
			}
		}

		delstream.close();
		int RRN2;
		istringstream (AvailList[0]) >> RRN2;
		AvailList.erase(AvailList.begin());
		RRN2 = (RRN2*123)-123;
        stream.seekp(RRN2);
        stream.write(Client_R.c_str(), 123);
        stream.close();
        
        cout << AvailList.size() << endl;

        for (int i = 0; i < AvailList.size(); ++i){
        	NewAvailList+= AvailList[i] + ",";
        }

 		delstream.open ("./lib/indexes/del/CLIENTS.txt", ios::out|ios::trunc);
        delstream.write(NewAvailList.c_str(), NewAvailList.length());
        delstream.close();
	}
}

void ClientFile::modify(int pRRN, string pClientID, string pClientFN, string pClientLN, string pClientEM, string pClientAD) {
	string Client_R;

	if(pClientID.length() != 13){
		for (int i = pClientID.length()+1; i <= 13 ; ++i){
			pClientID+= " ";
		}
	}

	if(pClientFN.length() != 20){
		for (int i = pClientFN.length()+1; i <= 20 ; ++i){
			pClientFN+= " ";
		}	
	}

	if(pClientLN.length() != 20){
		for (int i = pClientLN.length()+1; i <= 20 ; ++i){
			pClientLN+= " ";
		}	
	}

	if(pClientEM.length() != 30){
		for (int i = pClientEM.length()+1; i <= 30 ; ++i){
			pClientEM+= " ";
		}	
	}

	if(pClientAD.length() != 40){
		for (int i = pClientAD.length()+1; i <= 40 ; ++i){
			pClientAD+= " ";
		}	
	}

	Client_R = pClientID + pClientFN + pClientLN + pClientEM + pClientAD;

	stream.open ("./lib/indexes/CLIENTS.txt");
    int RRN = (pRRN*123)-123;
    stream.seekp (RRN);
    stream << Client_R.c_str();
    stream.close();
}

int ClientFile::getCount(){ 
	stream.open ("./lib/indexes/CLIENTS.txt");
	stream.seekg (0, ios::end);
  	int length = stream.tellg();
  	stream.seekg (0, ios::beg);
  	stream.close();
  	return length/123;
}

int ClientFile::search(string pClientID){

		
	for (int i = 1; i <= this->getCount(); ++i){
       if (read(i)->getClientID() == pClientID){

           	return i;
            } 
        }
;
        return -1;
}

void ClientFile::close(){
	stream.close();
	delstream.close();
}

bool ClientFile::erase(int pRRN){

	delstream.close();
	delstream.open("./lib/indexes/del/CLIENTS.txt");
	stringstream ss;
	ss << pRRN;
  	string AL = ss.str() + ",";
 
  	delstream.seekp(0,ios::end);
	delstream.write(AL.c_str(),AL.length());
	delstream.close();

	string Inactive = this->read(pRRN)->getClientID();
	Inactive[0] = '*';
	this->modify(pRRN,Inactive,this->read(pRRN)->getClientFN(),this->read(pRRN)->getClientLN(), this->read(pRRN)->getClientEM(),this->read(pRRN)->getClientAD());

	return true;
}

void ClientFile::replace(int RRN, Client* repCli){
	
}