#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

class Account {
private:
	char* username;
	char* password;
	int role;
public:
	
	void createAccount(char name[], char pass[], int r);
	void createAcountLecturer();
	bool checkUsername(char id[]);
	void output();
};