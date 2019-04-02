#include"Time.h"

void Time::input(string y, int t) {
	year = y;
	term = t;
}

void loadTime(vector<Time> &time) {
	ifstream fin;
	fin.open("Data/Time.txt");
	bool first = true;
	string year;
	int term;
	while (!fin.eof())
	{
		fin >> year;
		fin >> term;
		Time tmp;
		tmp.input(year, term);
		time.push_back(tmp);
	}
	fin.close();
}

void Time::printOut() {
	cout << year << " " << term << endl;
}

string Time::getYear() {
	return year;
}
int Time::getTerm() {
	return term;
}