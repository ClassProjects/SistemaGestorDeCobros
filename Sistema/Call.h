#ifndef __Sistema_Gestor_de_Cobros__Call__
#define __Sistema_Gestor_de_Cobros__Call__

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Call{

private:

	char FromNumber[9];
	char DestinationNumber[9];
	char InitialTime[15];
	char EndTime[15];

public:

	Call();
	Call(string, string, string, string);

	void setFromNumber(string);
	void setDestinationNumber(string);
	void setInitialTime(string);
	void setEndTime(string);

	string getFromNumber();
	string getDestinationNumber();
	string getInitialTime();
	string getEndTime();
};



#endif /* defined(__Sistema_Gestor_de_Cobros__Call__) */
