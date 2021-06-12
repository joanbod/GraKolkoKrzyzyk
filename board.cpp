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

	int x{}, y{};
	x = 400 - (rozmiar * 80 / 2);
	y = 245 - (rozmiar * 80 / 2);

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

void Board::wstaw(int x, int y, int kto) {// 1-kolko    2-krzyzyk
	int x_poczatek = 440 - rozmiar * 80 / 2;
	int y_poczatek = 325 - rozmiar * 80 / 2;

	int x_koniec = x_poczatek + 80 * rozmiar;
	int y_koniec = y_poczatek + 80 * rozmiar;

	if (x > x_poczatek && x<x_koniec && y>y_poczatek && y < y_koniec)
	{
		int x_pocz_kwadrat = x_poczatek;
		int y_pocz_kwadrat = y_poczatek;
		int licznik = 0;
		cout << "petla uruchomiona\n";
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++)
			{
				if (x > x_pocz_kwadrat && x<(x_pocz_kwadrat + 80) && y>y_pocz_kwadrat && y < (y_pocz_kwadrat + 80)) {
					if (tab_score[licznik] == 0)
					{
						tab_score[licznik] = kto;
						cout << "kliknieto na " << licznik << " kwadrat";
					}
					break;
				}
				x_pocz_kwadrat += 80;
				licznik++;
			}
			x_pocz_kwadrat = x_poczatek;
			y_pocz_kwadrat += 80;
		}
	}

}



bool Board::checkIfWin()
{
	/*W zaleÅ¼noÅ›ci od rozmiaru musza zostac speÅ‚nione odpowiednie warunki.*/
	if (rozmiar == 3)
	{
		/*Sprawdza elementy w kolejnych wierszach czy sÄ… takie same.*/

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
	delete[] tab_score;
}
