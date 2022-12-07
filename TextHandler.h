#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class TextHandler 
{
private:
	sf::Text text;
	sf::Font font;
	sf::Color color;
	float posX {};
	float posY {};

public:
	//TextHandler();
	TextHandler(const sf::Font& font, float posX, float posY,
		sf::Color color, int fontSize, sf::String stringText = "");

	sf::Text getsfText();
	void updateString(sf::String newString);
};
