#ifndef __Sistema_Gestor_de_Cobros__ReportIndex__
#define __Sistema_Gestor_de_Cobros__ReportIndex__

#include "Client.h"
#include "ClientListIndex.h"
#include "Phone.h"
#include "PhoneListIndex.h"
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

	class ReportIndex {

		fstream reportstream;

		ClientListIndex* cManage;
		PhoneListIndex* pManage;
		CallFile * pcaManage;
		map<string, multimap<string,Call*> > ClientPhoneNumbers;
		multimap<string,Call*> ClientDestinationCalls;
		int ClientTotal;

	public: 

		ReportIndex();
		void PrintReportClient(string, string, string);	
		void PrintReportDate(string, string, string);
		double* getCallTime(string,string,string);
		void close();
		void open();
		~ReportIndex();
	};


#endif /* defined(__Sistema_Gestor_de_Cobros__Report__) */