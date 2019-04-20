#pragma once
#ifndef __LABEL_H
#define __LABEL_H

#include <stdint.h>
#include <SFML/Graphics.hpp>

class label {
	public:
		char *text;
		uint16_t x, y;		

		label();
		label(char *text, uint16_t posX, uint16_t posY);
		void update(sf::RenderWindow *window);		
	private:		
		sf::Font font;
		sf::Text textView;
	protected:
		uint16_t labels_num;
};

#endif