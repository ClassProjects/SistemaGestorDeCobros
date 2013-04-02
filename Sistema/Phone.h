#ifndef __Sistema_Gestor_de_Cobros__Phone__
#define __Sistema_Gestor_de_Cobros__Phone__

#include <iostream>
#include <string>

using namespace std;

class Phone {

private:
	char PhoneNumber[9];
	char PhoneType[3];
	char ClientID[14];

public:

	Phone();
	Phone(string,string,string); 	

	void setPhoneNumber(string);
	void setPhoneType(string);

	string getPhoneNumber();
	string getPhoneType();
	string getClientID();
	string toString();
	};	

#endif /* defined(__Sistema_Gestor_de_Cobros__Phone__) */
