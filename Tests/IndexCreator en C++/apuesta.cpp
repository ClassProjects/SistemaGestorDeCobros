
#include <iostream>
#include <string>
//#include <stdlib>

using namespace std;


int main(){

	string rrn = "12";


	while(rrn.length() <= 5){
        	//rrn = "0" + rrn;
			rrn += "0" + rrn;
        	cout << rrn << endl;
    }

    
}