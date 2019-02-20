#include"Account.h"
#include<vector>

using namespace std;

class ArrOfAccount {
private:
	int n;
	vector <Account> A;
public:
	void loadAccountStudent();
	void loadAccountLecturer();
	void loadAccountAdmin();
	bool isValid(char id[]);
	void input(char name[], char pass[], int role);
	void saveAccount();
	ArrOfAccount();
};