#include"Convert.h"

void convertStringToInt(char c[], int & a) {
	a = 0;
	if (c[0] > '9' || c[0] < '0') {
		a = -1;
		return;
	}

	for (int i = 0; i < strlen(c); i++)
		a = a * 10 + (c[i] - '0');

}

void convertDateToPass(char date[], char pass[]) {
	string tmp = "";
	string res = "";
	int n = 0;
	for (int i = 0; i < strlen(date); i++) {
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
	for (int i = 0; i < res.length(); i++)
		pass[i] = res[i];
	pass[res.length()] = '\0';
}