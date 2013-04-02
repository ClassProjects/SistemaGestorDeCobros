tp:	main.o Client.o ClientFile.o Phone.o PhoneFile.o PhoneType.o PhoneTypeFile.o Rates.o RatesFile.o Call.o ClientListIndex.o PhoneListIndex.o Report.o CallFile.o ReportIndex.o
	g++ main.o Client.o ClientFile.o Phone.o PhoneFile.o PhoneType.o PhoneTypeFile.o Rates.o RatesFile.o Call.o ClientListIndex.o PhoneListIndex.o Report.o CallFile.o ReportIndex.o -o tp
main.o:	main.cpp Client.h ClientFile.h Phone.h PhoneFile.h PhoneType.h PhoneTypeFile.h Rates.h RatesFile.h Call.h ClientListIndex.h PhoneListIndex.h Report.h CallFile.h ReportIndex.h
	g++ -c main.cpp -Wno-deprecated
ClientListIndex.o:	ClientListIndex.cpp ClientListIndex.h ClientFile.h Client.h
	g++ -c ClientListIndex.cpp -o ClientListIndex.o -pedantic -std=c++0x
Client.o:	Client.cpp Client.h
	g++ -c Client.cpp -o Client.o
ClientFile.o:	ClientFile.cpp ClientFile.h Client.h
	g++ -c ClientFile.cpp -o ClientFile.o
Phone.o:	Phone.cpp Phone.h
	g++ -c Phone.cpp -o Phone.o
PhoneFile.o:	PhoneFile.cpp PhoneFile.h
	g++ -c PhoneFile.cpp -o PhoneFile.o
PhoneType.o:	PhoneType.cpp	PhoneType.h
	g++ -c PhoneType.cpp -o PhoneType.o
PhoneTypeFile.o: PhoneTypeFile.cpp PhoneTypeFile.h
	g++ -c PhoneTypeFile.cpp -o PhoneTypeFile.o
Rates.o:	Rates.cpp Rates.h
	g++ -c Rates.cpp -o Rates.o
RatesFile.o:	RatesFile.cpp RatesFile.h
	g++ -c RatesFile.cpp -o RatesFile.o
Call.o:	Call.cpp Call.h
	g++ -c Call.cpp -o Call.o
CallFile.o: CallFile.cpp CallFile.h Call.h
	g++ -c CallFile.cpp -o CallFile.o
PhoneListIndex.o:	PhoneListIndex.cpp PhoneListIndex.h PhoneFile.h Phone.h
	g++ -c PhoneListIndex.cpp -o PhoneListIndex.o -pedantic -std=c++0x
Report.o:	Report.cpp Report.h Client.h ClientFile.h Phone.h PhoneFile.h Call.h CallFile.h Rates.h RatesFile.h PhoneType.h PhoneTypeFile.h
	g++ -c Report.cpp -o Report.o -pedantic -std=c++0x
ReportIndex.o:	ReportIndex.cpp ReportIndex.h Client.h ClientListIndex.h Phone.h PhoneFile.h PhoneListIndex.h Call.h CallFile.h Rates.h RatesFile.h PhoneType.h PhoneTypeFile.h
	g++ -c ReportIndex.cpp -o ReportIndex.o -pedantic -std=c++0x
Tree.o: Tree.cpp Phone.h Client.h PhoneListIndex.h PhoneFile.h
	g++ -c Tree.cpp -o Tree.o -Wno-deprecated
clean:
	rm *.o
