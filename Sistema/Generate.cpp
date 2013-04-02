#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>     
#include <stdlib.h>     
#include <ctime> 
#include "PhoneFile.h"
#include "Phone.h"
#include <cstdlib>


	using namespace std;

	int main (){
		int randi;
		fstream CallMaster ("./lib/indexes/CALLS.txt");
		fstream PhoneMaster ("./lib/indexes/PHONES.txt");
		fstream IniEnd ("./lib/files/Intial_End_Calls.txt");
		PhoneFile* pManage = new PhoneFile();
		
		srand(time(0));
	

		for (int i = 1; i <= 207058; ++i){

			string Call_R = "", Temp;
			cout << i << endl;
			Call_R+= pManage->read(1+ (rand() % 50000))->getPhoneNumber() + pManage->read(1+ (rand() % 50000))->getPhoneNumber();

			IniEnd >> Temp;
			Call_R+= Temp;

			CallMaster << Call_R;

		}

		CallMaster.close();
		PhoneMaster.close();
		IniEnd.close();

		return 0;
	}