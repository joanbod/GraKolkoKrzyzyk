#include<iostream>
#include "menu.h"
#include<vector>
#include <SFML/Graphics.hpp>
#include "board.h"


using namespace std;
using namespace sf;

int main()
{


	//element mod odpowiada za wyswietlenie odpowiedniego okna mozna by to wlozyc do enum?
	int mod = 0;
	int choiceMode = 1;
	vector<int> vecChoices;	//do zapisania trybow gry
	enum class GameBoard {threexthree=1,fivexfive=2};
	enum class GameMode{easy =1,medium=2,advanced=3,withAFriend=4};
	
	//m1.how_to_play();

	//Elementy w menu g³ównym
	Sprites goBackButton = Sprites("images/start.png", 750, 50, true/*rozmiar 50X50*/);
	//Sprites m2 = Sprites("images/start.png", 350, 200, true);
	//Sprites m3 = Sprites("images/start.png", 350, 300, true);

	//£aduje czcionki
	Texts o_x = Texts(L"O_X", "fonts/PressStart2P-Regular.ttf", 40,350,100);	//O_X na ka¿dej stronie
	Texts startButton = Texts(L"Start", "fonts/PressStart2P-Regular.ttf", 32, 350, 160);
	Texts instructionButton = Texts(L"Instrukcja", "fonts/PressStart2P-Regular.ttf", 32, 350, 202);
	wstring instruction = L"ZASADY GRY\nGracze obejmuj¹ pola na przemian d¹¿¹c do objêcia trzech pól w jednej linii,\nprzy jednoczesnym uniemo¿liwieniu tego samego przeciwnikowi.\nPole mo¿e byæ objête przez jednego gracza i\nnie zmienia swego w³aœciciela przez ca³y przebieg gry.\n\nJAK GRAÆ?\n Po pierwsze wybierz planszê:\n\n3x3\n5x5\n\n nastêpnie wybierz swojego przeciwnika:\n\n-£atwy\n-Œredni\n-Zaawansowany\n-Ze znajomym\n\nKoñcowo wybierz iloœæ rozgrywek wybieraj¹c odpowiedni¹ liczbê.\n\nI najwa¿niejsze pamiêtaj o dobrej zabawie.";
	Texts instructionText = Texts(instruction, "fonts/Quicksand-VariableFont_wght.ttf", 16, 100, 160);
	Texts chooseGameBoard = Texts(L"PLANSZA", "fonts/PressStart2P-Regular.ttf", 22, 350, 160);
	Texts chooseGameMode = Texts(L"TRYB GRY", "fonts/PressStart2P-Regular.ttf", 22, 350, 192);
	Texts chooseAmountOfGames = Texts(L"LICZBA ROZGRYWEK", "fonts/PressStart2P-Regular.ttf", 22, 350, 234);
	
	sf::RenderWindow window(sf::VideoMode(800, 650, 32), "Pierwsze okno"/*, sf::Style::Fullscreen*/);
	window.setVerticalSyncEnabled(true);
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
			//Powrót do strony g³ównej
			if (!(mod == 0) && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Right && e.mouseButton.x < 800 && e.mouseButton.x > 0 && e.mouseButton.y > 0 && e.mouseButton.y < 650)
			{
				mod == 0;
			}
			if (mod == 0 && e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 450 && e.mouseButton.x > 350 && e.mouseButton.y > 202 && e.mouseButton.y < 234)
			{
				//Przejœcie do instrukcji.
				mod = 1;
			}
			if (mod == 0 && e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 450 && e.mouseButton.x > 350 && e.mouseButton.y > 160 && e.mouseButton.y < 192)
			{
				//Przejœcie do wyboru trybu gry.
				mod = 2;
			}
			//wybór trybu gr 3x3 albo 5x5
			if (mod == 2 && choiceMode == 1 && e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 400 && e.mouseButton.x > 0 && e.mouseButton.y > 0 && e.mouseButton.y < 650)
			{
				vecChoices.push_back(static_cast<int>(GameBoard::threexthree));
				choiceMode = 2;
			}
			if (mod == 2 && choiceMode == 1 && e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 800 && e.mouseButton.x > 400 && e.mouseButton.y > 0 && e.mouseButton.y < 650)
			{
				vecChoices.push_back(static_cast<int>(GameBoard::threexthree));
				choiceMode = 2;
			}
			//wybor poziomu trudnoœci lub czy z innym graczem 
			if (mod == 2 && choiceMode == 2 && e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 400 && e.mouseButton.x > 0 && e.mouseButton.y < 300 && e.mouseButton.y > 0)
			{
				vecChoices.push_back(static_cast<int>(GameMode::easy));
				choiceMode = 3;
			}
			if (mod == 2 && choiceMode == 2 && e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 400 && e.mouseButton.x > 0 && e.mouseButton.y < 650 && e.mouseButton.y > 300)
			{
				vecChoices.push_back(static_cast<int>(GameMode::advanced));
				choiceMode = 3;
			}
			if (mod == 2 && choiceMode == 2 && e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 800 && e.mouseButton.x > 400 && e.mouseButton.y < 300 && e.mouseButton.y > 0)
			{
				vecChoices.push_back(static_cast<int>(GameMode::medium));
				choiceMode = 3;
			}
			if (mod == 2 && choiceMode == 2 && e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 800 && e.mouseButton.x > 400 && e.mouseButton.y < 650 && e.mouseButton.y > 300)
			{
				vecChoices.push_back(static_cast<int>(GameMode::withAFriend));
				choiceMode = 3;
			}
			if (mod == 2 && choiceMode == 3 && e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
			{
				choiceMode = 1;
			}

			//TODO: przycisk powrotu, mo¿e ma³e menu po najechaniu siê wysietla? przyciski wyboru gry bo rozpierdala to powoli.
		}


		window.clear(sf::Color(0, 0, 0));
		//TODO: Do osobnej funkjci to strzeliæ by trzeba by³o.
	
		switch (mod)
		{
			//G³ówne menu gry
		case 0:
			window.draw(o_x.text);
			window.draw(startButton.text);
			window.draw(instructionButton.text);
			break;
			//Instrukcja gry
		case 1:
			window.draw(o_x.text);
			window.draw(instructionText.text);
			window.draw(goBackButton.sprite);

			break;
			//Wybór trybu gry
		case 2:
		{
			switch (choiceMode)
			{
			case 1:
				window.draw(chooseGameBoard.text);
				break;
			case 2:
				window.draw(chooseGameMode.text);
				break;
			case 3:
				window.draw(chooseAmountOfGames.text);
				break;

			}
		}
			break;
			//Gra
		case 4:
			board * plansza = new board(&window, 5);
			plansza->rysuj();
			break;

		default:
			break;
		}
	
		

		window.display();
	}

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



		window.display();
	}


	system("pause");
	return 0;
}