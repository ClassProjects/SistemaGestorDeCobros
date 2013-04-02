#ifndef __Sistema_Gestor_de_Cobros__Rates__
#define __Sistema_Gestor_de_Cobros__Rates__

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Rates {

private:

char RateCode[3];
char PhoneTypeID[3];
char RateInitial[7];
char RateEnd[7];
char RatePrice[4];

public:

	Rates();
	Rates(string,string,string,string,string);

	void setRateCode(string);
	void setPhoneTypeID(string);
	void setRateInitial(string);
	void setRateEnd(string);
	void setRatePrice(string);

	string getRateCode();
	string getPhoneTypeID();
	string getRateInitial();
	string getRateEnd();
	string getRatePrice();

	string toString();
	string toStringFormated();
};

#endif /* defined(__Sistema_Gestor_de_Cobros__Rates__) */
