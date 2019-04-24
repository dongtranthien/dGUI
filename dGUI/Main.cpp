#include <SFML/Graphics.hpp>
#include "dGUI.h"
#include <chrono>
#include <thread>
#include <stdio.h>
#include <string.h>

int main()
{
	char** list = (char**)calloc(10, sizeof(char*));
	char i;
	list[0] = &i;

	dGui gui(1000,800);
	label label1("Hi You", 10, 50);
	gui.add(label1);
	label label2("Hi 1", 100, 100);
	gui.add(label2);


	uint16_t index = 0;
	char str[10];
	while (gui.isOpen())
	{
		i++;
		#ifdef _WIN32
			sprintf_s(str, "%d", index);
		#else
			sprintf(str, "%d", index);
		#endif
		index++;

		label1.text = str;
		gui.update();

		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
		
	}

	return 0;
}
