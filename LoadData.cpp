#include"LoadData.h"

void loadTexture(std::string file, sf::Texture &texture) {
	if (texture.loadFromFile(path(file)) == -1) return;
}

void loadFont(string file, sf::Font &font) {
	if (font.loadFromFile(path(file)) == 0) return;
}

string path(string file) {
	return "Data/graphic/" + file;
}

