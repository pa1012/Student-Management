#include"Time.h"

void Time::input(string y, int t, int w) {
	year = y;
	term = t;
	week = w;
}

void loadTime(vector<Time> &time) {
	ifstream fin;
	fin.open("Data/Time.txt");
	bool first = true;
	string year;
	int term,week;
	while (!fin.eof())
	{
		fin >> year;
		fin >> term;
		fin >> week;
		Time tmp;
		tmp.input(year, term,week);
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

int Time::getWeek() {
	return week;
}