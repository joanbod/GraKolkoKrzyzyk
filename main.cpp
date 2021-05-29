#include<iostream>
#include <SFML/Window.hpp>
#include "menu.h"
#include "board.h"

using namespace std;
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(800, 600), "okno");   //rozdielczos okna			
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();		//event zamykajacy okno
			}
		}
		window.clear();

		board* plansza = new board(&window, 5);
		plansza->rysuj();

		window.display();
	}

	Menu m1;
	m1.how_to_play();

	system("pause");
	return 0;
}