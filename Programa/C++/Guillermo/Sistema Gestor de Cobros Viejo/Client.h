#ifdef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <string.h>

	using namespace std;

	class Client {

	private:
	int CLIEID;
	char* CLIEFN = new char[20];
	char* CLIELN = new char[20];
	char* CLIEEM = new char[30];
	char* CLIEAD = new char[40];

	public:
	Client();
	Client(int,string,string,string,string);

	void setCLIEID();
	void setCLIEFN();
	void setCLIELN();
	void setCLIEEM();
	void setCLIEAD();

	int getCLIEID();
	char* getCLIEFN();	
	char* getCLIELN();
	char* getCLIEEM();
	char* getCLIEAD()
	};


#endif 