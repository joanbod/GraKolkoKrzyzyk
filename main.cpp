#include<iostream>
#include "menu.h"
#include"board.h"
#include<vector>
#include <SFML/Graphics.hpp>



using namespace std;


int main()
{


	//element mod odpowiada za wyswietlenie odpowiedniego okna mozna by to wlozyc do enum?
	int mod = 0;
	int choiceMode = 1;
	vector<int> vecChoices;	//do zapisania trybow gry
	enum class GameBoard {threexthree=1,fivexfive=2};
	enum class GameMode{easy=1,medium=2,advanced=3,withAFriend=4};
	
	//m1.how_to_play();

	//Elementy w menu g��wnym
	//Sprites goBackButton = Sprites("images/backButtonWhite.png", 750, 50, true/*rozmiar 50X50*/);
	//Sprites m2 = Sprites("images/start.png", 350, 200, true);
	//Sprites m3 = Sprites("images/start.png", 350, 300, true);

	//�aduje czcionki
	Texts o_x = Texts(L"O_X", "fonts/PressStart2P-Regular.ttf", 60,305,50);	//O_X na ka�dej stronie
	Texts startButton = Texts(L"Start", "fonts/PressStart2P-Regular.ttf", 42, 300, 240);
	Texts instructionButton = Texts(L"Instrukcja", "fonts/PressStart2P-Regular.ttf", 42, 220, 330);
	wstring instruction = L"ZASADY GRY\nGracze obejmuj� pola na przemian d���c do obj�cia trzech p�l w jednej linii,\nprzy jednoczesnym uniemo�liwieniu tego samego przeciwnikowi.\nPole mo�e by� obj�te przez jednego gracza i\nnie zmienia swego w�a�ciciela przez ca�y przebieg gry.\n\nJAK GRA�?\n Po pierwsze wybierz plansz�:\n\n3x3\n5x5\n\n nast�pnie wybierz swojego przeciwnika:\n\n-�atwy\n-�redni\n-Zaawansowany\n-Ze znajomym\n\nKo�cowo wybierz ilo�� rozgrywek wybieraj�c odpowiedni� liczb�.\n\nI najwa�niejsze pami�taj o dobrej zabawie.";
	Texts instructionText = Texts(instruction, "fonts/Quicksand-VariableFont_wght.ttf", 16, 100, 160);
	Texts chooseGameBoard = Texts(L"PLANSZA", "fonts/PressStart2P-Regular.ttf", 40, 310, 150);
	Texts chooseGameMode = Texts(L"TRYB GRY", "fonts/PressStart2P-Regular.ttf", 40, 310, 150);
	Texts chooseAmountOfGames = Texts(L"LICZBA ROZGRYWEK", "fonts/PressStart2P-Regular.ttf", 40, 310, 150);
	Texts threeXthree = Texts(L"3 x 3", "fonts/PressStart2P-Regular.ttf", 32, 360, 250);
	Texts fiveXfive = Texts(L"5 x 5", "fonts/PressStart2P-Regular.ttf", 32, 360, 310);


	Texts goBackButton = Texts(L"BACK", "fonts/PressStart2P-Regular.ttf", 14, 740, 20);

	sf::RenderWindow window(sf::VideoMode(800, 650, 32), "Pierwsze okno"/*, sf::Style::Fullscreen*/);
	
	window.setVerticalSyncEnabled(true);
	board* plansza = new board(&window, 5);
	while (window.isOpen())
	{
		

		sf::Event e;
		while (window.pollEvent(e))
		{
			//obsluga zdarzenia
			if (e.type == sf::Event::Closed || (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape))
			{
				window.close();
			}
			//Powr�t do strony g��wnej
			if (!(mod == 0) && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 800 && e.mouseButton.x > 740 && e.mouseButton.y > 0 && e.mouseButton.y < 40)
			{
				mod = 0;
				choiceMode = 1;
				//TODO: mo�na tu zrobi� powr�t do poprzedniej storny mod--
			}
			if (mod == 0 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 640 && e.mouseButton.x > 210 && e.mouseButton.y > 320 && e.mouseButton.y < 364)
			{
				//Przej�cie do instrukcji.
				mod = 1;
			}
			else if (mod == 0 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 510 && e.mouseButton.x > 290 && e.mouseButton.y < 300 && e.mouseButton.y > 230)
			{
				//Przej�cie do wyboru trybu gry.
				mod = 2;
			}
			//wyb�r trybu gr 3x3 albo 5x5
			else if (mod == 2 && choiceMode == 1 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 440 && e.mouseButton.x > 360 && e.mouseButton.y > 248 && e.mouseButton.y < 285)
			{
				vecChoices.push_back(static_cast<int>(GameBoard::threexthree));
				choiceMode = 2;
			}
			else if (mod == 2 && choiceMode == 1 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 800 && e.mouseButton.x > 400 && e.mouseButton.y > 300 && e.mouseButton.y < 650)
			{
				vecChoices.push_back(static_cast<int>(GameBoard::fivexfive));
				choiceMode = 2;
			}
			//wybor poziomu trudno�ci lub czy z innym graczem 
			else if (mod == 2 && choiceMode == 2 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 400 && e.mouseButton.x > 0 && e.mouseButton.y < 300 && e.mouseButton.y > 0)
			{
				vecChoices.push_back(static_cast<int>(GameMode::easy));
				choiceMode = 3;
			}
			else if (mod == 2 && choiceMode == 2 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 400 && e.mouseButton.x > 0 && e.mouseButton.y < 650 && e.mouseButton.y > 300)
			{
				vecChoices.push_back(static_cast<int>(GameMode::advanced));
				choiceMode = 3;
			}
			else if (mod == 2 && choiceMode == 2 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 800 && e.mouseButton.x > 400 && e.mouseButton.y < 300 && e.mouseButton.y > 0)
			{
				vecChoices.push_back(static_cast<int>(GameMode::medium));
				choiceMode = 3;
			}
			else if (mod == 2 && choiceMode == 2 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 800 && e.mouseButton.x > 400 && e.mouseButton.y < 650 && e.mouseButton.y > 300)
			{
				vecChoices.push_back(static_cast<int>(GameMode::withAFriend));
				choiceMode = 3;
			}
			else if (mod == 2 && choiceMode == 3 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 800 && e.mouseButton.x > 400 && e.mouseButton.y < 650 && e.mouseButton.y > 300)
			{
				//tutaj chhyba inputem jakims bedzie trzeba to zrobic
				mod = 3;
			}

			//TODO: przycisk powrotu, mo�e ma�e menu po najechaniu si� wysietla? przyciski wyboru gry bo rozpierdala to powoli.
		}


		window.clear(sf::Color(10, 89, 93));
		//TODO: Do osobnej funkjci to strzeli� by trzeba by�o.
	
		switch (mod)
		{
			//G��wne menu gry
		case 0:
			window.draw(o_x.text);
			window.draw(startButton.text);
			window.draw(instructionButton.text);
			break;
			//Instrukcja gry
		case 1:
			window.draw(o_x.text);
			window.draw(instructionText.text);
			window.draw(goBackButton.text);

			break;
			//Wyb�r trybu gry
		case 2:
		{
			switch (choiceMode)
			{
			case 1:
				window.draw(chooseGameBoard.text);
				window.draw(threeXthree.text);
				window.draw(fiveXfive.text);
				window.draw(goBackButton.text);
				break;
			case 2:
				window.draw(chooseGameMode.text);
				
				window.draw(goBackButton.text);
				break;
			case 3:
				window.draw(chooseAmountOfGames.text);
				window.draw(goBackButton.text);
				//tu beda strza�ki w g�re lub w d� do 10 �eby wybrac ilo�� rozgrywek
				break;

			}
		}
			break;
			//Gra
		case 4:
			plansza->rysuj();

			break;
		default:
			break;
		}
	
		

		window.display();
	}




	system("pause");
	return 0;
}