#include "Student.h"
#include<vector>
#include"Convert.h"


using namespace std;

class Class {
private:
	int numberOfStudent;
	vector <Student> students;
	string name;
public:
	void inputAClass(int n, string c, ArrOfAccount &Acc);
	void outputAClass();
	void inputStudents(ArrOfAccount &Acc);
	void clear();
};