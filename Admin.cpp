#include"Admin.h"

void Admin::inputAAdmin(string id, string last, string first, int gen, string d) {
	ID = id;

	lastName = last;
	firstName = first;

	gender = gen;

	date = d;
}

void Admin::clear() {

}

int Admin::getRole() {
	return role;
}