#include "dGUI.h"

dGui::dGui(uint16_t width, uint16_t height) {	
	window.create(sf::VideoMode(width, height), "SFML works!");	
	window.setFramerateLimit(100);
	window.setVerticalSyncEnabled(true);

	// Set all element object is zero
	labels_num = 0;
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
		free(labels);

		labels = (label**)calloc(labels_num, sizeof(label*));
		labels[labels_num - 1] = &label_;
	}
	else {
		//// Create label list temp to recalloc label list pointer
		//label** labels_t = (label**)calloc(labels_num, sizeof(label*));
		//// memccpy(labels_t, labels, NULL, labels_num * sizeof(label*));
		//// Copy pointer label list to temp
		//memcpy(labels_t, labels, labels_num * sizeof(label*));
		///*uint16_t i;
		//for (i = 0; i < labels_num; i++) {
		//	labels_t[i] = labels[i];
		//}*/
		//// Deallocates of labels list pointer
		//free(labels);
		//// Increase labels num
		//labels_num++;		
		//// Create new list of label
		//labels = (label**)calloc(labels_num, sizeof(label*));
		//// Copy labels temp to label
		//memcpy(labels, labels_t, labels_num * sizeof(label*));
		///*for (i = 0; i < (labels_num - 1); i++) {
		//	labels[i] = labels_t[i];
		//}*/
		//// Import new label pointer to labels list
		//labels[labels_num - 1] = &label_;
		//// Deallocates temp pointer list
		//free(labels_t);
		

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