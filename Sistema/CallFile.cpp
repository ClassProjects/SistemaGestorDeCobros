//
//  CallFile.cpp
//  Sistema Gestor de Cobros
//
//  Created by Jorge Caballero on 2/12/13.
//  Copyright (c) 2013 Jorge Caballero. All rights reserved.
//

#include "CallFile.h"
#include <vector>
#include <iostream>
#include <sstream>

CallFile::CallFile(){
	stream.open ("./lib/indexes/CALLS.txt");
	delstream.open ("./lib/indexes/del/CALLS.txt");
	if (stream.is_open())
	{
		cout << "File CALL open Succesfully" << endl;
	} else {
		cout << "Error opening CALL" << endl;
	}

	if (delstream.is_open())
	{
		cout << "File CALLDELL open Succesfully" << endl;
	} else {
		cout << "Error opening CALLDELL" << endl;
	}
    stream.close();
    delstream.close();

}

Call* CallFile::read(int RRN){
    stream.open ("./lib/indexes/CALLS.txt");
	stream.seekg(0);
	stream.read(buffer, 44);

	string From = "", To = "", Start = "", End = "";

	    if (RRN == 1){
		for (int i = 0; i < sizeof(buffer); ++i){
			if(buffer[i] != ' ' && i < 8){
				From+= buffer[i];
            }else if (buffer[i] != ' ' && i < 16){
                To+= buffer[i];
            }else if(buffer[i] != ' ' && i < 30){
                Start+= buffer[i];
            }else if(buffer[i] != ' ' && i < 44){
                End+= buffer[i];
            }
        }
        
        Call* retVal = new Call(From, To, Start, End);
        stream.close();
        return retVal;

    } else{
        RRN = (RRN*44)-44;
        stream.seekg(RRN);
        stream.read(buffer, 44);
        
        for (int i = 0; i < sizeof(buffer); ++i){
            if(buffer[i] != ' ' && i < 8){
				From+= buffer[i];
            }else if (buffer[i] != ' ' && i < 16){
                To+= buffer[i];
            }else if(buffer[i] != ' ' && i < 30){
                Start+= buffer[i];
            }else if(buffer[i] != ' ' && i < 44){
                End+= buffer[i];
            }
        }
        
		Call* retVal = new Call(From, To, Start, End);  
        stream.close();      
		return retVal;
    }

}

void CallFile::write(string from, string to, string start, string end){
	int length = 0;
    delstream.seekg(0,ios::end);
    length = delstream.tellg();
    delstream.seekg(0,ios::beg);
    char* buffer = new char[length];
    string Call_R = "", NewAvailList = "";
    vector <string> AvailList;

    if(from.length() != 8){
        for (int i = from.length()+1; i <= 8 ; ++i){
            from+= " ";
        }
    }

    if(to.length() != 8){
        for (int i = to.length()+1; i <= 8 ; ++i){
            to+= " ";
        }   
    }

    if(start.length() != 14){
        for (int i = start.length()+1; i <= 14 ; ++i){
            start+= " ";
        }   
    }

    if(end.length() != 14){
        for (int i = end.length()+1; i <= 14 ; ++i){
            end+= " ";
        }   
    }

    Call_R = from + to + start + end;

    if(length == 0){
        stream.seekp(0,ios::end);
        stream.write(Call_R.c_str(),44);
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
        RRN2 = (RRN2*44)-44;
        stream.seekp(RRN2);
        stream.write(Call_R.c_str(), 44);
        stream.close();
        
        cout << AvailList.size() << endl;

        for (int i = 0; i < AvailList.size(); ++i){
            NewAvailList+= AvailList[i] + ",";
        }

        delstream.open ("./lib/indexes/del/CALLS.txt", ios::out|ios::trunc);
        delstream.write(NewAvailList.c_str(), NewAvailList.length());
        delstream.close();
    }
}

void CallFile::modify(int pRRN, string pFrom, string pTo, string pStart, string pEnd){
    stream.close();
    string Call_R;

    if(pFrom.length() != 8){
        for (int i = pFrom.length()+1; i <= 8 ; ++i){
            pFrom+= " ";
        }
    }

    if(pTo.length() != 8){
        for (int i = pTo.length()+1; i <= 8 ; ++i){
            pTo+= " ";
        }   
    }

    if(pStart.length() != 14){
        for (int i = pStart.length()+1; i <= 14 ; ++i){
            pStart+= " ";
        }   
    }

    if(pEnd.length() != 14){
        for (int i = pEnd.length()+1; i <= 14 ; ++i){
            pEnd+= " ";
        }   
    }


    Call_R = pFrom + pTo + pStart + pEnd;

    stream.open ("./lib/indexes/CALLS.txt");
    int RRN = (pRRN*44)-44;
    stream.seekp (RRN);
    stream << Call_R.c_str();
    stream.close();
}

vector<int> CallFile::search(string term){
	vector<int> retVal;
	for (int i = 1; i <= this->getCount(); ++i){
       if (read(i)->getFromNumber() == term){
           	retVal.push_back(i);
            } 
        }
        return retVal;
}

int CallFile::getCount(){
    stream.seekg (0, ios::end);
    int length = stream.tellg();
    stream.seekg (0, ios::beg);
    stream.close();
    return length/44;
}

