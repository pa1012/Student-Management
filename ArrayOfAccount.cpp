#include "ArrayOfAccount.h"


void ArrOfAccount::loadAccount(ArrayOfCourse C) {
	stringstream str;
	str << "Data/Account.csv";
	string fileName = str.str();

	ifstream fin;

	fin.open(fileName.c_str());
	string name, pass, role,id,last,first,date,gender,courses,clas;
	int gen;
	n = 0;
	A.clear();
	
	while (!fin.eof())
	{
		getline(fin, name, ',');
		getline(fin, pass, ',');
		getline(fin, role, ',');
		getline(fin, id, ',');
		getline(fin, last, ',');
		getline(fin, first, ',');
		getline(fin, date, ',');
		getline(fin, gender, ',');
		getline(fin, courses, ',');
		getline(fin, clas, '\n');
	
		Account a;
		gen = gender[0] - '0';
		if (name != "Username" && name != "") {
			a.createAccount(name, pass, role[0] - '0',id,last,first,date,gen,clas,courses,C);
			a.printCourse();
			A.push_back(a);
			n++;
		}
		a.clear();
	}
}

bool ArrOfAccount::isValid(string id) {
	for (int i = 0; i < A.size(); i++)
		if (A[i].checkUsername(id)) return true;
	return false;
}

void ArrOfAccount::input(string name, string pass, int role, string ID, string last, string first, string date, int gen,string clas,string course, ArrayOfCourse C) {
	Account a;
	a.createAccount(name, pass, role,ID,last,first,date,gen,clas,course,C);
	A.push_back(a);
	n++;
	a.clear();
}

void ArrOfAccount::saveAccount() {
	ofstream fout;
	fout.open("Data/Account.csv");
	fout.clear();
	fout << "Username, Password, Role, ID, Last Name, First Name, DoB, Gender, Course, Class" << endl;
	fout.close();
	for (int i = 0; i < A.size(); i++) {
		A[i].output(); 
	}
	fout.close();
}

ArrOfAccount::ArrOfAccount() {
	n = 0;
	A.clear();
}

int ArrOfAccount::findUsername(string c) {
	for (int i = 0; i < A.size(); i++)
		if (A[i].isMatchName(c)) return i;
	return -1;
}

bool ArrOfAccount::checkPassword(string c, int k) {
	return A[k].isMatchPass(c);
}

Account ArrOfAccount::getAccount(int k) {
	return A[k];
}

void ArrOfAccount::clear() {
	for (int i = 0; i < A.size(); i++)
		A[i].clear();
	A.clear();
}

void ArrOfAccount::updatePassword(string ID, string pass){
	int i = findUsername(ID);
	A[i].updatePassword(pass);
}

vector<Account> ArrOfAccount::returnClass(string name) {
	vector<Account> a;
	for (int i = 0; i < A.size(); i++)
		if (A[i].isMatchClass(name)) a.push_back(A[i]);
	return a;
}

vector<Account> ArrOfAccount::returnRole(int role) {
	vector<Account> a;
	for (int i = 0; i < A.size(); i++)
		if (A[i].isMatchRole(role)) a.push_back(A[i]);
	return a;
}

vector<Account> ArrOfAccount::returnStudent(string courseName)
{
	vector<Account> a;
	for (int i = 0; i < A.size(); i++)
		if (A[i].isMatchCourse(courseName) && A[i].getRole() == 1) a.push_back(A[i]);
	return a;
}

void ArrOfAccount::pushAccount(Account a) {
	A.push_back(a);
}

Account ArrOfAccount::getAccount(string ID) {
	for (int i = 0 ; i < A.size();i++)
		if (A[i].isMatchName(ID)) {
			return A[i];
		}
}

void ArrOfAccount::removeAccount(string ID) {
	for (int i = 0 ; i < A.size();i++)
		if (A[i].isMatchName(ID)) {
			A.erase(A.begin() + i);
			return;
		}
}

void ArrOfAccount::updateCourse(ArrayOfCourse course, string year, int term) {
	vector<Course> c;
	c.clear();
	c = course.returnCourses(year, term);
	for (int i = 0; i < A.size(); i++) {
		if (A[i].getRole() == 2) {
			string name = A[i].getLastName() + " " + A[i].getFirstName();
			for (int j = 0 ; j < c.size() ; j++)
				if (c[j].getLecture() == name) {
					A[i].addCourse(c[j]);
				}
		}
	}
}

string ArrOfAccount::returnCourse(string className) {
	Account a;
	for (int i = 0; i < A.size(); i++) {
		if (A[i].isMatchClass(className)) {
			a = A[i];
			break;
		}
	}
	string cou;
	return a.mergeCourses();
}

void ArrOfAccount::removeCourseInAccount(string courseID) {
	for (int i = 0; i < A.size(); i++)
	{
		A[i].removeCourse(courseID);
	}
}

void ArrOfAccount::addCourse(string ID, string courseName, ArrayOfCourse course) {
	for (int i = 0 ; i < A.size() ;i++)
		if (A[i].isMatchName(ID)) {
			A[i].addCourse(courseName,course);
			break;
		}
}

void ArrOfAccount::removeCourseInAccount(string ID, string courseID) {
	for (int i = 0 ; i < A.size() ; i++)
		if (A[i].isMatchName(ID)) {
			A[i].removeCourse(courseID);
			break;
		}
}

void ArrOfAccount::addCourseToClass(string cl, string courseID, ArrayOfCourse course) {
	Course C = course.findACourse(courseID);
	for (int i =0 ; i < A.size() ; i++)
		if (A[i].isMatchClass(cl)) {
			A[i].addCourse(C);
		}
}