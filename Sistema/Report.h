#ifndef __Sistema_Gestor_de_Cobros__Report__
#define __Sistema_Gestor_de_Cobros__Report__

#include "Client.h"
#include "ClientFile.h"
#include "Phone.h"
#include "PhoneFile.h"
#include "Call.h"
#include "CallFile.h"
#include "Rates.h"
#include "RatesFile.h"
#include "PhoneType.h"
#include "PhoneTypeFile.h"

#include <iostream>
#include <string>
#include <map>
#include <vector>


	using namespace std;

	class Report {

		fstream reportstream;

		ClientFile* cManage;
		PhoneFile* pManage;
		CallFile * pcaManage;
		map<string, multimap<string,Call*> > ClientPhoneNumbers;
		multimap<string,Call*> ClientDestinationCalls;
		int ClientTotal;

	public: 

		Report();
		void PrintReportClient(string, string, string);	
		void PrintReportDate(string, string, string);
		double* getCallTime(string,string,string);
		void close();
		void open();
		~Report();
	};


#endif /* defined(__Sistema_Gestor_de_Cobros__Report__) */