#include<iostream>
#include<fstream>

class Date {
private:
	int day, month, year;
public:
	long long convertToInt();
	void outputADate();
	void inputADate();
};