#include "label.h"

label::label() {

}

label::label(char *text, uint16_t posX, uint16_t posY) {
	this->text = text;	
	this->x = posX;
	this->y = posY;
		
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}
}

void label::update(sf::RenderWindow *window) {
	textView.setString(this->text);
	textView.setFont(this->font);
	textView.setPosition(sf::Vector2f(this->x, this->y));

	window->draw(textView);
}
