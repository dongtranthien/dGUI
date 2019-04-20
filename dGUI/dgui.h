#pragma once
#ifndef __DGUI_H
#define __DGUI_H

#include <SFML/Graphics.hpp>

#include "label.h"
#include <vector> 
#include <iostream> 

using namespace std;
class dGui: public sf::Window, label{
	public:
		dGui(uint16_t width, uint16_t height);
		void update();		
		void add(label &label_);
		bool isOpen();
	private:
		sf::RenderWindow window;		
		label** labels;
		

};

#endif
