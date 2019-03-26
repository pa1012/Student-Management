#include"ScreenControl.h"

void Screen::initGraphic() {

	loadTexture("logoutButton.png", logoutButtonText);
	loadTexture("menu.png", menuText);
	loadFont("VNI-Avo.TTF", font);
	loadTexture("changePassword.png", changePasswordTexture);

	changePassword.setTexture(changePasswordTexture);
	changePassword.setPosition(408, 538);

	logoutButton.setTexture(logoutButtonText);
	logoutButton.setPosition(1582.65, 0);

	menu.setTexture(menuText);
	menu.setPosition(0, 0);

	nameOfUser.setFont(font);
	nameOfUser.setPosition(96, 24);
	nameOfUser.setCharacterSize(30);
	nameOfUser.setFillColor(sf::Color::White);

	name.setFont(font);
	name.setPosition(430, 144);
	name.setCharacterSize(30);
	name.setFillColor(sf::Color::White);
	name.setString("Name: " + account.getLastName() + " " + account.getFirstName());

	id.setString("ID: " + account.getID());
	id.setCharacterSize(30);
	id.setPosition(430, name.getPosition().y + 60); //
	id.setFillColor(sf::Color::White);
	id.setFont(font);

	int gen = account.getGender();
	if (gen == 0)
		gender.setString("Gender: Male");
	else
		gender.setString("Gender: Female");
	gender.setCharacterSize(30);
	gender.setPosition(430, id.getPosition().y + 60); 
	gender.setFillColor(sf::Color::White);
	gender.setFont(font);


	date.setString("Date of birth: " + account.getDate());
	date.setCharacterSize(30);
	date.setPosition(430, gender.getPosition().y + 60); //
	date.setFillColor(sf::Color::White);
	date.setFont(font);

	username.setString("Username: "+ account.getUsername());
	username.setCharacterSize(30);
	username.setPosition(430, date.getPosition().y +60); //
	username.setFillColor(sf::Color::White);
	username.setFont(font);

	password.setString("Password: " + account.getPassword());
	password.setCharacterSize(30);
	password.setPosition(430, username.getPosition().y + 60);
	password.setFillColor(sf::Color::White);
	password.setFont(font);

	inform.setFillColor(sf::Color::White);
	inform.setPosition(408, 600);
	inform.setCharacterSize(20);
	inform.setFont(font);
	inform.setString("");

	passForChange = account.getPassword();
}

void Screen::render(sf::RenderWindow &window, string now) {

	window.draw(menu);
	window.draw(logoutButton);
	window.draw(nameOfUser);
	if (now == "view profile" || now == "change password" ) {
		window.draw(name);
		window.draw(id);
		window.draw(gender);
		window.draw(date);
		window.draw(username);
		window.draw(password);
		window.draw(changePassword);
		window.draw(inform);
	}
}

string Screen::handleEvent(sf::Event event, string now, ArrOfAccount &Acc, string nowAdmin) {
	
	if (nowAdmin == "anywhere" && now != "change password" && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (logoutButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			return "logout";
		}
		if (nameOfUser.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			 if (now != "view profile") return "view profile";
			 else return "anywhere";
			
		}
		if (password.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			inform.setString("");
			password.setString("Password: " + passForChange + "|");
			return "change password";
		}
	}
	if (now == "change password" && nowAdmin == "anywhere") {
		if (event.type == sf::Event::TextEntered) {
			updateString(passForChange, event);
			cout << passForChange << endl;
			password.setString("Password: " + passForChange + "|");
			return "change password";
		}
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			if (changePassword.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
				if (passForChange.length() >= 8) {
					account.updatePassword(passForChange);
					Acc.updatePassword(account.getID(), passForChange);
				}
				else {
					inform.setString("Password must have more than 7 characters");
					passForChange = account.getPassword();
				}
				password.setString("Password: " + account.getPassword());
				return "view profile";
			}
		}
	}
	return "anywhere";
}


void Screen::updateAccount(Account a) {
	account = a;
	nameOfUser.setString(account.getLastName() + " " + account.getFirstName());
}