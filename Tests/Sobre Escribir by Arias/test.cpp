#include <iostream>
#include <fstream>
using namespace std;

int main(){
	fstream 2("data.txt");
	char d[100];
	data >> d;
	cout << d << endl;
	data >> d;
	cout << d << endl;
	data << "xxxxxxxxxxxxxxxxxx" << endl;
	data.close();
	return 0;
}
