#include "board.h"

board::board(RenderWindow* okno, int a) {
	rozmiar = a;
	window = okno;
	int liczba_pol = rozmiar * rozmiar;
	tab = new RectangleShape[liczba_pol];
	tab_sore = new int[liczba_pol];

}

void board::rysuj() {
	int x = 400 - (rozmiar * 80), y = 3;
	for (int i = 0; i < rozmiar * rozmiar; i++)
	{
		RectangleShape square(Vector2f(80.f, 80.f));
		tab[i] = square;
		tab[i].setFillColor(Color(0, 0, 0));
		if (i % rozmiar == 0) {
			y += 80;
			x = 400 - (rozmiar / 2 * 80);
		}
		tab[i].move(x, y);
		x += 80;
		tab[i].setOutlineThickness(1.f);
		tab[i].setOutlineColor(Color(255, 255, 255));
		window->draw(tab[i]);
	}

}

void board::wstaw() {

}

board::~board() {
	delete[] tab;
}