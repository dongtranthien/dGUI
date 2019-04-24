#include "dGUI.h"

dGui::dGui(uint16_t width, uint16_t height) {	
	window.create(sf::VideoMode(width, height), "SFML works!");	
	window.setFramerateLimit(100);
	window.setVerticalSyncEnabled(true);

	// Set all element object is zero
	labels_num = 0;
}

dGui::~dGui(){
	uint16_t i;
	for(i = 0; i < labels_num; i++){
		free(label[i]);
	}
	free(label);
}

void dGui::update() {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	// Clear window to redraw
	window.clear();
	uint16_t i;	
	for (i = 0; i < labels_num; i++) {
		labels[i]->update(&window);
	}	
	window.display();
	sf::sleep(sf::milliseconds(20));
}

void dGui::add(label &label_) {
	if (labels_num == 0) {
		labels_num++;

		labels = (label**)calloc(labels_num, sizeof(label*));
		labels[labels_num - 1] = &label_;
	}
	else {
		// Increase labels num
		labels_num++;

		labels = (label**)realloc(labels, labels_num*sizeof(label*));		
		
		// Import new label pointer to labels list
		labels[labels_num - 1] = &label_;
		
	}
}

bool dGui::isOpen() {
	// Get window status
	return window.isOpen();
}
