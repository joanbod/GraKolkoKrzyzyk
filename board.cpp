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

void Board::rysuj(int punkty_gracz_1, int punkty_gracz_2) {
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

	//wyswietlanie napisow pod plansza

	y += 100;
	String napis_punkt1 = to_string(punkty_gracz_1);
	String napis_punkt2 = to_string(punkty_gracz_2);
	napis_punkt1 =  napis_punkt1 + " : " + napis_punkt2;
	Texts napis1 = Texts(napis_punkt1, "fonts/PressStart2P-Regular.ttf", 50, 320, y);

	window->draw(napis1.text);
}

void Board::wstaw(int x, int y, int kto) {// 1-kolko    2-krzyzyk

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
							tab_score[licznik] = kto;
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
		for (int j = 0; j < rozmiar; j++)																		//rysuje kolko lub krzyzyk dla miejsc tablicy nie bedacych zerami
		{
			if (tab_score[licznik] == 1) {
				Texts shapeo = Texts(L"O", "fonts/PressStart2P-Regular.ttf", 40, x_aktualny, y_aktualny);
				window->draw(shapeo.text);
			}
			if (tab_score[licznik] == 2) {
				Texts shapex = Texts(L"x", "fonts/PressStart2P-Regular.ttf", 50, x_aktualny-5, y_aktualny-10);
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
	/*W zale≈ºno≈õci od rozmiaru musza zostac spe≈Çnione odpowiednie warunki.
	result=0; brak dotychczasowej wygranej
	result =1; wygrana
	result=2 ; remis
	
	*/
	if (rozmiar == 3)
	{
		/*Sprawdza elementy w kolejnych wierszach czy sƒÖ takie same.*/

		for (int i = 0; i < rozmiar * rozmiar; i += 3)
		{
			if (tab_score[i] == tab_score[i + 1] && tab_score[i] == tab_score[i + 2] && tab_score[i]!=0)
				return tab_score[i];
		}
		for (int i = 0; i < rozmiar; i++)
		{

			/*Sprawdza elementy w kolejnych kolumnach czy sπ takie same.*/
			if (tab_score[i] == tab_score[i + 3] && tab_score[i] == tab_score[i + 6] && tab_score[i] != 0)
				return 1;
			if (i == 0)
			{	/*Sprawdza po ukosie czy elementy sπ takie same.*/
				if (tab_score[i] == tab_score[i + 4] && tab_score[i] == tab_score[i + 8] && tab_score[i] != 0)
					return tab_score[i];
			}
			else if (i == 2)
				if (tab_score[i] == tab_score[i + 2] && tab_score[i] == tab_score[i + 4] && tab_score[i] != 0)
					return tab_score[i];
		}
	}

	else if (rozmiar == 5)
	{
		/*Sprawdza elementy w kolejnych wierszach czy sπ takie same.*/
		for (int i = 0; i < rozmiar * rozmiar; i += 5)
		{
			if (tab_score[i] == tab_score[i + 1] && tab_score[i] == tab_score[i + 2] && tab_score[i] == tab_score[i + 3] && tab_score[i] != 0)
				return tab_score[i];
			i++;
			/*if (tab_score[i+1] == tab_score[i + 2] && tab_score[i+1] == tab_score[i + 3] && tab_score[i+1] == tab_score[i + 4] && tab_score[i+1] != 0)
				return tab_score[i];*/
			if (tab_score[i] == tab_score[i + 1] && tab_score[i] == tab_score[i + 2] && tab_score[i] == tab_score[i + 3] && tab_score[i] != 0)
				return tab_score[i];
			i--;
		}

		/*Sprawdza elementy w kolejnych kolumnach czy sπ takie same.*/
		for (int i = 0; i < rozmiar; i++)
		{
			if (tab_score[i] == tab_score[i + 5] && tab_score[i] == tab_score[i + 10] && tab_score[i] == tab_score[i + 15] && tab_score[i] != 0)
				return tab_score[i];

			i+=5;
			if (tab_score[i] == tab_score[i + 5] && tab_score[i] == tab_score[i + 10] && tab_score[i] == tab_score[i + 15] && tab_score[i] != 0)
				return tab_score[i];
			i -= 5;
		/*	if (tab_score[i+5] == tab_score[i + 10] && tab_score[i+5] == tab_score[i + 15] && tab_score[i+5] == tab_score[i + 20] &&  tab_score[i+5] != 0)
				return tab_score[i];*/
		}

		/*Sprawdza po ukosie czy elementy sπ takie same.*/
		int i = 0;
		while (i<8)
		{
			if (tab_score[i] == tab_score[i + 6] && tab_score[i]==tab_score[i + 12] && tab_score[i] == tab_score[i+18] && tab_score[i] != 0)return tab_score[i];
			i++;
			if (tab_score[i] == tab_score[i + 6] && tab_score[i] == tab_score[i + 12] && tab_score[i] == tab_score[i+18] && tab_score[i] != 0)return tab_score[i];
			i = i + 4;
		}
		i = 3;
		while (i<11)
		{
			if (tab_score[i] == tab_score[i + 4] && tab_score[i] == tab_score[i + 8] && tab_score[i] == tab_score[i+ 12] && tab_score[i] != 0){
				cout << "wygrana przez ukos";
				return tab_score[i];
			}
			i++;
			if (tab_score[i] == tab_score[i + 4] && tab_score[i] == tab_score[i + 8] && tab_score[i] == tab_score[i +12] && tab_score[i] != 0){
				cout << "wygrana przez ukos";
				return tab_score[i];
			}
			i = i + 3;
		}
	}
	/*Rozwizanie do remisu.*/
	bool checkRemis = 1;
	for (int j = 0; j < rozmiar*rozmiar; j++)
	{
		if (tab_score[j] == 0)
		{
			checkRemis = false;
		}
	}
	if (checkRemis) {
		return 3;
	}
	else {
		return 0;
	}
}
void Board::newGame() {
	for (int i = 0; i < rozmiar*rozmiar; i++)
	{
		tab_score[i] = 0;							//czyszczenie planszy po kazdej rozgrywce
	}
}


Board::~Board() {
	delete[] tab;
	delete[] tab_score;
}
