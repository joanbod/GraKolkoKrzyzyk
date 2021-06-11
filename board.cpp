#include "board.h"

Board::Board(RenderWindow* okno, int a) {
	rozmiar = a;
	window = okno;
	int liczba_pol = rozmiar * rozmiar;
	tab = new RectangleShape[liczba_pol];
	tab_score = new int[liczba_pol];

	for (int i = 0; i < rozmiar; i++)
	{
		tab_score[i] = 0;
	}

}

void Board::rysuj() {
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

void Board::wstaw(int x, int y, int kto) 
{

}
//mp¿e jako int aby zwraca³ co wygra³o?

bool Board::checkIfWin()
{
	//TODO:Dodaæ warunek kiedy jest kompromis, ¿e ca³a tablica wype³niona a ¿aden z pni¿szych warunków nie jest spe³niony.
	/*W zale¿noœci od rozmiaru musza zostac spe³nione odpowiednie warunki.*/
	if (rozmiar == 3)
	{
		/*Sprawdza elementy w kolejnych wierszach czy s¹ takie same.*/
		for (int i = 0; i < rozmiar * rozmiar; i += 3)
		{
			if (tab_score[i] == tab_score[i + 1] && tab_score[i] == tab_score[i + 2])
				return true;
		}
		for (int i = 0; i < rozmiar; i++)
		{
			/*Sprawdza elementy w kolejnych kolumnach czy s¹ takie same.*/
			if (tab_score[i] == tab_score[i + 3] && tab_score[i] == tab_score[i + 6])
				return true;
			if (i == 0)
			{	/*Sprawdza po ukosie czy elementy s¹ takie same.*/
				if (tab_score[i] == tab_score[i + 4] && tab_score[i] == tab_score[i + 8])
					return true;
			}
			else if (i == 2)
					if (tab_score[i] == tab_score[i + 2] && tab_score[i] == tab_score[i + 4])
						return true;
		}
	}

	else if (rozmiar == 5)
	{
		/*Sprawdza elementy w kolejnych wierszach czy s¹ takie same.*/
		for (int i = 0; i < rozmiar * rozmiar; i += 5)
		{
			if (tab_score[i] == tab_score[i + 1] && tab_score[i] == tab_score[i + 2] && tab_score[i] == tab_score[i + 3] && tab_score[i] == tab_score[i + 4])
				return true;
		}
		/*Sprawdza elementy w kolejnych kolumnach czy s¹ takie same.*/
		for (int i = 0; i < rozmiar; i++)
		{
			if (tab_score[i] == tab_score[i + 5] && tab_score[i] == tab_score[i + 10] && tab_score[i] == tab_score[i + 15] && tab_score[i] == tab_score[i + 20])
				return true;
		}
		/*Sprawdza po ukosie czy elementy s¹ takie same.*/
		for(int i=0;i<rozmiar;i+=4) 
		{
			if (i == 0)
			{
				if (tab_score[i] == tab_score[i + 6] && tab_score[i] == tab_score[i + 12] && tab_score[i] == tab_score[i + 18] && tab_score[i] == tab_score[i + 24])
					return true;
			}
			else if (i == 4)
					if (tab_score[i] == tab_score[i + 4] && tab_score[i] == tab_score[i + 8] && tab_score[i] == tab_score[i + 12] && tab_score[i] == tab_score[i + 16])
						return true;
		}
	}
	return false;
}
Board::~Board() {
	delete[] tab;
}