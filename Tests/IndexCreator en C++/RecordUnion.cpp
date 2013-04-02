#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;

int main(){
	fstream inp("./Phone_2.csv");
	fstream outp("./PhoneIndex_2.txt");
	
	string buffer = "";

	while(inp >> buffer){

		
		string rrn = "", data = "";
		bool Flag = true;
		//cout << buffer << endl;

		for (int i = 0; i < buffer.length(); ++i){

			if(Flag == true){

				if(buffer[i] != ','){
					rrn += buffer[i];
				}else{
					Flag = false;
					
				}

			}else{
				data += buffer[i];

			}
		}

	while(rrn.length() <= 5){
		rrn = "0" + rrn;
		}
		cout << rrn + data << endl;
		string s = rrn + data;
		outp << s;
	}

	outp.close();
  }
	
	
