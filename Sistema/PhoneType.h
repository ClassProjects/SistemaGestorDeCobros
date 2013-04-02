#ifndef __Sistema_Gestor_de_Cobros__PhoneType__
#define __Sistema_Gestor_de_Cobros__PhoneType__

#include <iostream>
#include <string>
#include <cstring>


using namespace std;

class PhoneType {
private:

	char PhoneTypeID[3];
	char PhoneDescription[21];
	char BaseRate[4];

public:
	PhoneType();
	PhoneType(string,string,string);

	void setPhoneTypeID(string);
	void setPhoneDescription(string);
	void setBaseRate(string);

	string getPhoneTypeID();
	string getPhoneDescription();
	string getBaseRate();

	string toString();
};

#endif /* defined(__Sistema_Gestor_de_Cobros__PhoneType__) */
