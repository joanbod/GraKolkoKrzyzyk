#include"bot.h"
#include"board.h"



int losowa_liczba(int a, int b)
{
	random_device device;
	mt19937 generator(device());
	uniform_int_distribution<int> distribution(a, b);

	return distribution(generator);
}

Bot::Bot(Board& p, int tryb)
{
	tryb_gry = tryb;
	plansza = &p;
}

Bot::~Bot()
{
	
	plansza = nullptr;
}

bool Bot::czy_pole_puste(int i)
{
	if (plansza->tab_score[i] == 0)
		return true;
	return false;
}

int Bot::dodaj_losowo_wartosc()
{

	int i{};

	do {
		i = losowa_liczba(0, (plansza->rozmiar * plansza->rozmiar - 1));
	} while (!czy_pole_puste(i));

	return i;

}
//TODO:Zaprzyjaźnić funkcję z vecchoices??

int Bot::sprawdz_czy_wygram()
{
	if (tryb_gry == 2)
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

		return dodaj_losowo_wartosc();
		
	}
	else if (tryb_gry == 3)
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



}

int Bot::dodaj_losowo_wartosc_optymalniej()
{
	//Dodaje na srodek nastepnie na rogi nastepnie losowo
	int i{};
	if (plansza->rozmiar == 3)
	{
		
		if (czy_pole_puste(4))
		{
			return 4;
		}
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
	
void Bot::wykonaj_ruch()
{
	bool checkIfNew = 1;
	for (int i = 0; i < plansza->rozmiar * plansza->rozmiar; i++)
	{
		if (plansza->tab_score[i] != 0)
		{
			checkIfNew = false;
		}
	}
	if (tryb_gry == 1)
	{

		if (checkIfNew)
			plansza->tab_score[dodaj_losowo_wartosc_optymalniej()] = 2;
		else
			plansza->tab_score[dodaj_losowo_wartosc()] = 2;
	}
	else if (tryb_gry == 2)
	{
		
		if (checkIfNew)
			plansza->tab_score[dodaj_losowo_wartosc_optymalniej()] = 2;
		else
			plansza->tab_score[sprawdz_czy_wygram()] = 2;
		
	}
	else if (tryb_gry == 3)
	{
		if (checkIfNew)
			plansza->tab_score[dodaj_losowo_wartosc_optymalniej()] = 2;
		else
			plansza->tab_score[sprawdz_czy_wygram()] = 2;
	}
}

int Bot::sprawdz_czy_zablokuje()
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

	return dodaj_losowo_wartosc();
}
