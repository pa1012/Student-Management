#pragma once

#include"Base.h"
#include"ArrayOfAccount.h"
#include"ArrayOfClass.h"
#include"ArrayOfCourse.h"

struct AccountGraphic
{
	sf::Text no, userName, password,lastName, firstName,doB,gender,inClass;
};

/*void renderTableClass(sf::RenderWindow &window, string className, vector<AccountGraphic> A);
void initTableClass(vector<AccountGraphic> &A,string className, ArrOfAccount Acc);
*/