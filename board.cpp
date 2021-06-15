#include "board.h"

Board::Board(RenderWindow* okno, int a) {
	rozmiar = a;
	window = okno;
	int liczba_pol = rozmiar * rozmiar;
	tab = new RectangleShape[liczba_pol];
	tab_score = new int[liczba_pol] {};
	 x_poczatek = 440 - rozmiar * 80 / 2;    //poczatek od ktorego zaczyna sie plansza
	 y_poczatek = 325 - rozmiar * 80 / 2;
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
	Texts shapeo = Texts(L"O", "fonts/PressStart2P-Regular.ttf", 20, 300, 100);
	Texts shapex = Texts(L"x", "fonts/PressStart2P-Regular.ttf", 20, 300, 100);

	int x_koniec = x_poczatek + 80 * rozmiar;
	int y_koniec = y_poczatek + 80 * rozmiar;

	if (x > x_poczatek && x<x_koniec && y>y_poczatek && y < y_koniec)
	{
		int x_aktualny = x_poczatek;
		int y_aktualny = y_poczatek;
		int licznik = 0;
		cout << "petla uruchomiona\n";
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++)
			{
				
				if (x > x_aktualny && x<(x_aktualny + 80) && y>y_aktualny && y < (y_aktualny + 80)) {
					cout << tab_score[licznik];
					if (tab_score[licznik] == 0)
					{
						cout << "kliknieto na " << licznik << " kwadrat";
						
						if (kto == 1) {
							tab_score[licznik] = kto;
						}
						if (kto == 2) {
							tab_score[licznik] = kto;
						}
					

					}
					break;
				}
				x_aktualny += 80;
				licznik++;
			}
			x_aktualny = x_poczatek;
			y_aktualny += 80;
		}
	}
}


void Board::rysuj_x_o() {
	int x_aktualny = x_poczatek+23;
	int y_aktualny = y_poczatek+23;
	int licznik = 0;

	for (int i = 0; i < rozmiar; i++)
	{
		for (int j = 0; j < rozmiar; j++)
		{
			if (tab_score[licznik] == 1) {
				Texts shapeo = Texts(L"O", "fonts/PressStart2P-Regular.ttf", 40, x_aktualny, y_aktualny);
				window->draw(shapeo.text);
			}
			if (tab_score[licznik] == 2) {
				Texts shapex = Texts(L"x", "fonts/PressStart2P-Regular.ttf", 40, x_aktualny, y_aktualny);
				window->draw(shapex.text);
			}
			x_aktualny += 80;
			licznik++;
		}
		x_aktualny = x_poczatek+23;
		y_aktualny += 80;
	}
	
	


}



int Board::checkIfWin()
{
	/*W zależności od rozmiaru musza zostac spełnione odpowiednie warunki.
	result=0; brak dotychczasowej wygranej
	result =1; wygrana
	result=2 ; remis
	
	*/
	if (rozmiar == 3)
	{
		/*Sprawdza elementy w kolejnych wierszach czy są takie same.*/

		for (int i = 0; i < rozmiar * rozmiar; i += 3)
		{
			if (tab_score[i] == tab_score[i + 1] && tab_score[i] == tab_score[i + 2])
				return 1;
		}
		for (int i = 0; i < rozmiar; i++)
		{

			/*Sprawdza elementy w kolejnych kolumnach czy s� takie same.*/
			if (tab_score[i] == tab_score[i + 3] && tab_score[i] == tab_score[i + 6])
				return 1;
			if (i == 0)
			{	/*Sprawdza po ukosie czy elementy s� takie same.*/
				if (tab_score[i] == tab_score[i + 4] && tab_score[i] == tab_score[i + 8])
					return 1;
			}
			else if (i == 2)
					if (tab_score[i] == tab_score[i + 2] && tab_score[i] == tab_score[i + 4])
						return 1;
		}
	}

	else if (rozmiar == 5)
	{
		/*Sprawdza elementy w kolejnych wierszach czy s� takie same.*/
		for (int i = 0; i < rozmiar * rozmiar; i += 5)
		{
			if (tab_score[i] == tab_score[i + 1] && tab_score[i] == tab_score[i + 2] && tab_score[i] == tab_score[i + 3] && tab_score[i] == tab_score[i + 4])
				return 1;
		}

		/*Sprawdza elementy w kolejnych kolumnach czy s� takie same.*/
		for (int i = 0; i < rozmiar; i++)
		{
			if (tab_score[i] == tab_score[i + 5] && tab_score[i] == tab_score[i + 10] && tab_score[i] == tab_score[i + 15] && tab_score[i] == tab_score[i + 20])
				return 1;
		}

		/*Sprawdza po ukosie czy elementy s� takie same.*/
		for(int i=0;i<rozmiar;i+=4) 
		{
			if (i == 0)
			{
				if (tab_score[i] == tab_score[i + 6] && tab_score[i] == tab_score[i + 12] && tab_score[i] == tab_score[i + 18] && tab_score[i] == tab_score[i + 24])
					return 1;
			}
			else if (i == 4)
					if (tab_score[i] == tab_score[i + 4] && tab_score[i] == tab_score[i + 8] && tab_score[i] == tab_score[i + 12] && tab_score[i] == tab_score[i + 16])
						return 1;
		}
	}
	/*Rozwi�zanie do remisu.*/
	for (int i = 0; i < rozmiar * rozmiar; i++)
	{
		if (tab_score[i] != 0)
			return 2;
		else
			return 0;
	}
}
Board::~Board() {
	delete[] tab;
	delete[] tab_score;
}
