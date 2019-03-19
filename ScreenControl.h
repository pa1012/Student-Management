#pragma once

#include"LoadData.h"
#include"Constant.h"
#include "ArrayOfAccount.h"
#include"Update.h"

class Screen {
private:
	sf::Sprite logoutButton, menu, changePassword;
	sf::Texture logoutButtonText, menuText, changePasswordTexture;
	sf::Text  name, id, gender, date,username, password,inform;
	Account account;
	sf::Text nameOfUser;
	sf::Font font;
	string passForChange;
public:
	void initGraphic();
	void render(sf::RenderWindow &window,string now);
	string handleEvent(sf::Event event, string now,ArrOfAccount &Acc);
	void logic(string now, float screenY, sf::Sprite &rect);
	void updateAccount(Account a);
};