#include "ReportIndex.h"
#include "ClientListIndex.h"
#include "Phone.h"
#include "PhoneListIndex.h"
#include "Call.h"
#include "CallFile.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>

	using namespace std;

	ReportIndex::ReportIndex(){
		pManage = new PhoneListIndex();
		pcaManage = new CallFile();
		cManage = new ClientListIndex();
		
	}

	void ReportIndex::PrintReportClient(string pClientID, string pInial_Date, string pEnd_Date){
		ClientTotal = 0;
		

		reportstream << "\n\n\n\n**********************************************************************************"<< endl;
		reportstream << "Nombre Cliente:  " + cManage->read(cManage->search(pClientID))->getClientFN() << " " << cManage->read(cManage->search(pClientID))->getClientLN()<< endl; 
		reportstream << "Direccion:  " + cManage->read(cManage->search(pClientID))->getClientAD()<< endl;
		reportstream << "Desde: " << pInial_Date << "\tHasta: " << pEnd_Date << endl;
		reportstream << "\t\tD e t a l l e  d e  L l a m a d a s" << endl;
		reportstream << "------------------------------------------------------------" << endl;
	
		for (int i = 1; i <= pManage->getCount(); i++){

			if((pManage->read(i))->getClientID() == pClientID){
				
				for (int j = 1; j <= 207058; j++){
					
					if(pcaManage->read(j)->getFromNumber() == pManage->read(i)->getPhoneNumber() && pcaManage->read(j)->getInitialTime() >= pInial_Date && pcaManage->read(j)->getEndTime() <= pEnd_Date ){
						ClientDestinationCalls.insert(pair<string,Call*>(pManage->read(pManage->search(pcaManage->read(j)->getDestinationNumber()))->getPhoneType(), pcaManage->read(j)));
					}
				}

					ClientPhoneNumbers.insert(pair<string, multimap<string,Call*> >(pManage->read(i)->getPhoneNumber(),ClientDestinationCalls));
					ClientDestinationCalls.clear();
			}
		}
			
	for (auto& x: ClientPhoneNumbers) {
    		reportstream << "\nNumero de Telefono: " << x.first << endl;
    		for(auto& y: x.second){
    			double* ptr = getCallTime(y.second->getInitialTime().substr(0,6), y.second->getEndTime().substr(0,6),y.first);
    			ClientTotal += ptr[1];
    			reportstream << "\t"  << y.first << "\t" << y.second->getDestinationNumber() << "\t"<< y.second->getInitialTime().substr(0,6).substr(0,2) <<":"<< y.second->getInitialTime().substr(0,6).substr(2,2) <<":"<< y.second->getInitialTime().substr(0,6).substr(4,2) << "\t" << y.second->getEndTime().substr(0,6).substr(0,2) <<":"<< y.second->getEndTime().substr(0,6).substr(2,2) <<":"<< y.second->getEndTime().substr(0,6).substr(4,2) <<"\t" << y.second->getInitialTime().substr(6,13).substr(0,2) << "/" << y.second->getInitialTime().substr(6,13).substr(2,2) << "/" << y.second->getInitialTime().substr(6,13).substr(4,4) << "\t " << ptr[0] << "\t" << ptr[1] << endl;
    		}
    	}

    	reportstream << "\n\n\t\tSUBTOTAL:\t" << ClientTotal << endl;
    	reportstream << "\t\tISV:\t" << (ClientTotal * 0.12) << endl;
    	reportstream << "\t\tTOTAL A PAGAR:\t" << (ClientTotal + (ClientTotal * 0.12)) << endl;
		
		reportstream.flush();
		
	}

	void ReportIndex::close(){
		reportstream.close();
	}

	void ReportIndex::open(){
		reportstream.open("./reports/ReportsI.txt");
	}


	double* ReportIndex::getCallTime(string pStart,string pEnd, string type){
		double* pointer;
		double info[1];
		pointer = info;
		int Minutes = 0;

		if (pStart.substr(0,2) == pEnd.substr(0,2)){
	         istringstream Minutes_S (pEnd.substr(2,2));
	         Minutes_S >> Minutes;

		  } else {
		  	istringstream Minutes_S (pEnd.substr(2,2));
	        Minutes_S >> Minutes;
		    Minutes += 60;

		  }

		  info[0] = Minutes;

		  if (type == "AM"){
		  		info[1] = 4.25;
		  		if (stoi(pStart.substr(0,2)) >= 6 && stoi(pStart.substr(0,2)) <=18){
		  			info[1] += Minutes;
		  		} else {
		  			info[1] += 0.50*Minutes;
		  		}
		  	} else if (type == "TM"){
		  		info[1] = 4.15;
		  		if (stoi(pStart.substr(0,2)) >= 6 && stoi(pStart.substr(0,2)) <=18){
		  			info[1] += Minutes;
		  		} else {
		  			info[1] += 0.45*Minutes;
		  		}
		  	} else if (type == "AF"){
		  		info[1] = 0.25;
		  		if (stoi(pStart.substr(0,2)) >= 7 && stoi(pStart.substr(0,2)) <= 19){
		  			info[1] += Minutes;
		  		} else {
		  			info[1] += 0.20*Minutes;
		  		}
		  	} else if (type == "TF"){
		  		info[1] = 0.22;
		  		if (stoi(pStart.substr(0,2)) >= 10 && stoi(pStart.substr(0,2)) <=17){
		  			info[1] += Minutes;
		  		} else {
		  			info[1] += 0.25*Minutes;
		  		}
		  	} else if (type == "SA"){
		  		info[1] = 9.99 + Minutes;
		  	} else if (type == "DI"){
		  		info[1] = 0.11 + Minutes;
		  	} else if (type == "NO"){
		  		info[1] = 0.08;
		  		if (stoi(pStart.substr(0,2)) >= 6 && stoi(pStart.substr(0,2)) <=18){
		  			info[1] += Minutes;
		  		} else {
		  			info[1] += 0.70*Minutes;
		  		}
		  	}	  
	
		return pointer;

	}
