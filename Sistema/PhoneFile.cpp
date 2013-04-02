#include "PhoneFile.h"
#include <string>
#include <cstring>
#include <vector>
#include "Phone.h"

PhoneFile::PhoneFile(){
	stream.open ("./lib/indexes/PHONES.txt");
	delstream.open ("./lib/indexes/del/PHONES.txt");

    stream.close();
    delstream.close();
}


void PhoneFile::open(){

}

Phone* PhoneFile::read(int RRN){
    stream.open ("./lib/indexes/PHONES.txt");
	stream.seekg(0);
	stream.read(buffer, 23);

	string PhoneTypeID = "", PhoneDescription = "", BaseRate = "";

	    if (RRN == 1){
		for (int i = 0; i < sizeof(buffer); ++i){
			if(buffer[i] != ' ' && i < 8){
				PhoneTypeID+= buffer[i];
            }else if (buffer[i] != ' ' && i < 10){
                PhoneDescription+= buffer[i];
            }else if(buffer[i] != ' ' && i < 23){
                BaseRate+= buffer[i];
            }
        }
        
        Phone* retVal = new Phone(PhoneTypeID, PhoneDescription, BaseRate);
        stream.close();
        return retVal;

    }else{
        RRN = (RRN*23)-23;
        stream.seekg(RRN);
        stream.read(buffer, 23);
        
        for (int i = 0; i < sizeof(buffer); ++i){
            if(buffer[i] != ' ' && i < 8){
				PhoneTypeID+= buffer[i];
            }else if (buffer[i] != ' ' && i < 10){
                PhoneDescription+= buffer[i];
            }else if(buffer[i] != ' ' && i < 23){
                BaseRate+= buffer[i];
            }
        }
        
        Phone* retVal = new Phone(PhoneTypeID, PhoneDescription, BaseRate);
        stream.close();
        return retVal;
    }

}

void PhoneFile::write (string pPhoneNumber, string pPhoneType, string pClientID){
    stream.open ("./lib/indexes/PHONES.txt");
    delstream.open ("./lib/indexes/del/PHONES.txt");
    int length = 0;
    delstream.seekg(0,ios::end);
    length = delstream.tellg();
    delstream.seekg(0,ios::beg);
    char* buffer = new char[length];
    string RRN = "", Phone_R = "", NewAvailList = "";
    vector <string> AvailList;

    if(pPhoneNumber.length() != 8){
        for (int i = pPhoneNumber.length()+1; i <= 8 ; ++i){
            pPhoneNumber+= " ";
        }
    }

    if(pPhoneType.length() != 2){
        for (int i = pPhoneType.length()+1; i <= 2 ; ++i){
            pPhoneType+= " ";
        }   
    }

    if(pClientID.length() != 13){
        for (int i = pClientID.length()+1; i <= 13 ; ++i){
            pClientID+= " ";
        }   
    }

    Phone_R = pPhoneNumber + pPhoneType + pClientID;

    if(length == 0){
        stream.seekp(0,ios::end);
        stream.write(Phone_R.c_str(),23);
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
        RRN2 = (RRN2*23)-23;
        stream.seekp(RRN2);
        stream.write(Phone_R.c_str(), 23);
        stream.close();
        
        cout << AvailList.size() << endl;

        for (int i = 0; i < AvailList.size(); ++i){
            NewAvailList+= AvailList[i] + ",";
        }
        delstream.close();
        delstream.open ("./lib/indexes/del/PHONES.txt", ios::out|ios::trunc);
        delstream.write(NewAvailList.c_str(), NewAvailList.length());
        delstream.close();
    }
}

void PhoneFile::modify(int pRRN, string pPhoneNumber, string pPhoneType, string pClientID){
    
    
    string Phone_R;

    if(pPhoneNumber.length() != 8){
        for (int i = pPhoneNumber.length()+1; i <= 8 ; ++i){
            pPhoneNumber+= " ";
        }
    }

    if(pPhoneType.length() != 2){
        for (int i = pPhoneType.length()+1; i <= 2 ; ++i){
            pPhoneType+= " ";
        }   
    }

    if(pClientID.length() != 13){
        for (int i = pClientID.length()+1; i <= 13 ; ++i){
            pClientID+= " ";
        }   
    }

    Phone_R = pPhoneNumber + pPhoneType + pClientID;

    stream.open ("./lib/indexes/PHONES.txt");
    int RRN = (pRRN*23)-23;
    stream.seekp (RRN);
    stream << Phone_R.c_str();
    stream.close();
}

void PhoneFile::erase(int pRRN){
    delstream.close();
    delstream.open("./lib/indexes/del/PHONES.txt");
    stringstream ss;
    ss << pRRN;
    string AL = ss.str() + ",";
 
    delstream.seekp(0,ios::end);
    delstream.write(AL.c_str(),AL.length());
    delstream.close();

    string Inactive = this->read(pRRN)->getPhoneNumber();
    Inactive[0] = '*';
    this->modify(pRRN,Inactive,this->read(pRRN)->getPhoneType(), this->read(pRRN)->getClientID());

}

int PhoneFile::getCount(){
    stream.open ("./lib/indexes/PHONES.txt");
	stream.seekg (0, ios::end);
  	int length = stream.tellg();
  	stream.seekg (0, ios::beg);
    stream.close();
  	return length/23;
}

int PhoneFile::search(string term){
    for (int i = 1; i <= this->getCount(); ++i){
       if (read(i)->getPhoneNumber() == term){
            return i;
            } 
        }
        return -1;
}

void PhoneFile::close(){
	stream.close();
	delstream.close();

}
