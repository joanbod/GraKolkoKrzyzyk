#include"bot.h"
#include"board.h"



int losowa_liczba(int a, int b)
{
	random_device device;
	mt19937 generator(device());
	uniform_int_distribution<int> distribution(a, b);

	return distribution(generator);
}


Easy::Easy(Board* p)
{
	
}

Easy::~Easy()
{
	delete plansza;
}


bool Easy::czy_pole_puste(int i)
{
	if (plansza->tab_score[i] == 0)
		return true;
	return false;
}

void Easy::dodaj_losowo_wartosc()
{
	
	int i{};

	do {
		i = losowa_liczba(0, (plansza->rozmiar * plansza->rozmiar - 1));
	} while (!czy_pole_puste(i));

	plansza->tab_score[i] = 2;
	

}

Medium::Medium(Board* plansza)
{
	
}

Medium::~Medium()
{
	delete plansza;
}


bool Medium::czy_pole_puste(int i)
{
	if (plansza->tab_score[i] == 0)
		return true;
	return false;
}

int Medium::sprawdz_czy_wygram()
{
	
	//Sprawdza czy pododaniu danego elementu wygra jeśli tak to go dodaje jeśli nie to blokuje ruchy przeciwnika
	for (int i = 0; i < plansza->rozmiar * plansza->rozmiar; i++)
	{
		if (czy_pole_puste(i))
		{
			plansza->tab_score[i] = 2;

			if (plansza->checkIfWin() == 2)
			{
				return i;
			}
			else
			{
				plansza->tab_score[i] = 0;

			}
		}
	}

	return dodaj_losowo_wartosc_optymalniej();
	//TODO: czy takie zwrócenie elementu  jest poprawne?



}

int Medium::dodaj_losowo_wartosc_optymalniej()
{
	int i{};
	if (plansza->rozmiar == 3)
	{
		//TODO: możliwe że jak parzyste elementy będą wypełnione to wystąpi błąd, że nie ma co wypełnić??
		do {
			i = losowa_liczba(0, (plansza->rozmiar * plansza->rozmiar - 1));
		} while (i % 2 != 0 || !czy_pole_puste(i));

		return i;
		
	}
	else if (plansza->rozmiar == 5)
	{
		do {
			i = losowa_liczba(0, (plansza->rozmiar * plansza->rozmiar - 1));
		} while (!czy_pole_puste(i));

		return i;
		
	}
}
	
void Medium::wykonaj_ruch()
{
	bool checkIfNew = 1;
	for (int i = 0; i < plansza->rozmiar * plansza->rozmiar; i++)
	{
		if (plansza->tab_score[i] != 0)
		{
			checkIfNew = false;
		}
	}

	if (checkIfNew)
		plansza->tab_score[dodaj_losowo_wartosc_optymalniej()] = 2;
	else
		plansza->tab_score[sprawdz_czy_wygram()] = 2;
	//TODO:Czy w przypadku dodania wartości 2 z rzędu on będzie próbowaał blokować?
	//TODO: CHYBA WYSTARCZY SAMO plansza->tab_score[sprawdz_czy_wygram()] =2;
}
Advanced::Advanced(Board* plansza)
{
	
}

Advanced::~Advanced()
{
	delete plansza;
}

bool Advanced::czy_pole_puste(int i)
{
	if (plansza->tab_score[i] == 0)
		return true;
	return false;
}

//Zwraca indeks w tabeli, który mamy wypełnić.
int Advanced::sprawdz_czy_wygram()
{

	//Sprawdza czy pododaniu danego elementu wygra jeśli tak to go dodaje jeśli nie to blokuje ruchy przeciwnika
	for (int i = 0; i < plansza->rozmiar * plansza->rozmiar; i++)
	{
		if (czy_pole_puste(i))
		{
			plansza->tab_score[i] = 2;
				
			if (plansza->checkIfWin() == 2)
			{
				return i;
			}
			else
			{
				plansza->tab_score[i] = 0;
					
			}
		}
	}

	return sprawdz_czy_zablokuje();
}

int Advanced::sprawdz_czy_zablokuje()
{
	//Sprawdza elementy przeciwnika czy sa obok siebie jeśli tak dodaje własną wartość, aby uniemożliwić wygraną przeciwnika.
	for (int i = 0; i < plansza->rozmiar * plansza->rozmiar; i++)
	{
		if (czy_pole_puste(i))
		{
			plansza->tab_score[i] = 1;

			if (plansza->checkIfWin() == 1)
			{
				return i;
			}
			else
			{
				plansza->tab_score[i] = 0;
			}
		}
	}

	return dodaj_losowo_wartosc_optymalniej();
}

int Advanced::dodaj_losowo_wartosc_optymalniej()
{
	int i{};
	if(plansza->rozmiar == 3)
	{
		
		do {
			i = losowa_liczba(0, (plansza->rozmiar * plansza->rozmiar-1));
		} while (i % 2 != 0 || !czy_pole_puste(i));

		return i;
	}
	else if (plansza->rozmiar == 5)
	{
		do {
			i = losowa_liczba(0, (plansza->rozmiar * plansza->rozmiar-1));
		} while (!czy_pole_puste(i));

		return i;
	}
}

void Advanced::wykonaj_ruch()
{
	plansza->tab_score[sprawdz_czy_wygram()] = 2;

}
