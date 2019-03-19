#pragma once

#include"ArrayOfClass.h"
#include"Convert.h"
#include"LoadData.h"
#include"Update.h"
#include"ArrayOfCourse.h"

using namespace std;

class Login {
private:
	sf::Texture functionNameTexture, usernameTexture, passwordTexture, loginButtonTexture, cancelButtonTexture;
	sf::Sprite functionName, usernameBox, passwordBox, loginButton,cancelButton;
	sf::Text username, password, inform;
	sf::Font font;
	string name, pass;
	string state;
public:
	void render(sf::RenderWindow &window);
	Account checkAccount(ArrOfAccount Acc,ArrayOfCourse C);
	void initGraphic();
	int handleEvent(const sf::Event &event,ArrOfAccount Acc,Account &A,ArrayOfCourse C);
	void tryInput();
	Login();
	void initData();
};