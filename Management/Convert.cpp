#include"Convert.h"

void convertStringToInt(string c, int & a) {
	a = 0;
	if (c[0] > '9' || c[0] < '0') {
		a = -1;
		return;
	}

	for (int i = 0; i < c.length(); i++)
		a = a * 10 + (c[i] - '0');

}

void convertDateToPass(string date, string &pass) {
	string tmp = "";
	string res = "";
	int n = 0;
	for (int i = 0; i < date.length(); i++) {
		if (date[i] != '/') {
			tmp = tmp + date[i];
		}
		else {
			if (tmp.length() == 1) {
				tmp = '0' + tmp;
			}
			res = res + tmp;
			tmp = "";
		}
	}
	res = res + tmp;
	pass = res;

}

