#include"Update.h"

void updateString(string &str, sf::Event event) {
	if (event.text.unicode == 8) {
		if (str.length() > 0)
			str.erase(str.length() - 1);
		return;
	}
	str += event.text.unicode;
}