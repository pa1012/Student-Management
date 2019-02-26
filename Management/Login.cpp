#include"Login.h"

Account Login::checkAccount(ArrOfAccount Acc) {
	int x = -1;
	Account wrongUsername,wrongPassword;
	wrongUsername.createAccount("0", "0", -1);
	wrongPassword.createAccount("0", "0", -2);

	int k = Acc.findUsername(name);
	if (k == -1) {
		return wrongUsername;
	}
	else 
		if (!Acc.checkPassword(pass,k)) return wrongPassword;
		else
			return Acc.getAccount(k);
}

void Login::tryInput() {
	cin >> name;
	cin >> pass;
}

void Login::initGraphic() {
	
	loadTexture("login.png", functionNameTexture);
	loadTexture("username.png", usernameTexture);
	loadTexture("password.png", passwordTexture);
	loadTexture("loginButton.png", loginButtonTexture);
	loadTexture("cancelButton.png", cancelButtonTexture);
	loadFont("VNI-Avo.TTF", font);

	functionName.setTexture(functionNameTexture);
	functionName.setPosition(0, 0);

	usernameBox.setTexture(usernameTexture);
	usernameBox.setPosition(170, 231);

	passwordBox.setTexture(passwordTexture);
	passwordBox.setPosition(170, 428);

	loginButton.setTexture(loginButtonTexture);
	loginButton.setPosition(273, 632);

	cancelButton.setTexture(cancelButtonTexture);
	cancelButton.setPosition(593, 632);

	username.setCharacterSize(30);
	username.setPosition(444, 264); //444,264
	username.setFillColor(sf::Color::Black);
	username.setFont(font);

	password.setCharacterSize(30);
	password.setPosition(444, 465);
	password.setFillColor(sf::Color::Black);
	password.setFont(font);

	inform.setCharacterSize(30);
	inform.setPosition(216, 570);
	inform.setFillColor(sf::Color::White);
	inform.setFont(font);
}

void Login::render(sf::RenderWindow &window) {
	window.draw(functionName);
	window.draw(usernameBox);
	window.draw(passwordBox);
	window.draw(loginButton);
	window.draw(cancelButton);
	window.draw(username);
	window.draw(password);
	window.draw(inform);
	
	//cout << name << endl;
}

Login::Login() {
	state = "START";
	name = "";
	pass = "";
}

int Login::handleEvent(const sf::Event &event, ArrOfAccount Acc) {
	if (state == "START") {
		string c = "";
		for (int i = 0; i < pass.length(); i++)
			c = c + "*";
		password.setString(c);
		username.setString(name);
	}
	if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
		if (usernameBox.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			username.setString(name + "|");
			if (state == "Enter pass") {
				string c = "";
				for (int i = 0; i < pass.length(); i++)
					c = c + "*";
				password.setString(c);
			}
			state = "Enter name";
			return 0;
		}
		if (passwordBox.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			string c = "";
			for (int i = 0; i < pass.length(); i++)
				c = c + "*";
			password.setString(c + "|");
			if (state == "Enter name") {
				username.setString(name);
			}
			state = "Enter pass";
			return 0;
		}
		if (loginButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			Account a = checkAccount(Acc);
			if (a.getRole() == -1) {
				inform.setString("Login failed. Username is invalid");
				state = "START";
			}
			else
			if	(a.getRole() == -2) {
				inform.setString("Login failed. Wrong password");
				state = "START";
			}
			else
			return 1;
		}
		if (cancelButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
			return -1;
		}
	}
	if (event.type == sf::Event::TextEntered) {
		if (state == "Enter name") {
			updateString(name, event);
			username.setString(name + "|");
		}
		if (state == "Enter pass") {
			updateString(pass, event);
			string c = "";
			for (int i = 0; i < pass.length(); i++)
				c = c + "*";
			password.setString(c + "|");
		}
		return 0;
	}
	return 0;
}