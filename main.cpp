#include<iostream>
#include <SFML/Window.hpp>
#include "menu.h"
#include"board.h"
#include<vector>
#include <SFML/Graphics.hpp>



using namespace std;


int main()
{


	//element mod odpowiada za wyswietlenie odpowiedniego okna mozna by to wlozyc do enum?
	int mod = 0;
	int gracz = 1;
	int choiceMode = 1;
	vector<int> vecChoices;	//do zapisania trybow gry
	enum class GameBoard {threexthree=1,fivexfive=2};
	enum class GameMode{easy=1,medium=2,advanced=3,withAFriend=4};
	
	//m1.how_to_play();


	//Elementy w menu g��wnym
	Sprites amountButtonsUp = Sprites("images/buttonsAmountUp.png", 400, 230, true/*rozmiar 50X100*/);
	Sprites amountButtonsDown = Sprites("images/buttonsAmountDown.png", 400, 340, true/*rozmiar 50X100*/);
	

	//�aduje czcionki
	Texts o_x = Texts(L"O_X", "fonts/PressStart2P-Regular.ttf", 60,315,100);	//O_X na ka�dej stronie
	Texts startButton = Texts(L"Start", "fonts/PressStart2P-Regular.ttf", 42, 300, 240);
	Texts instructionButton = Texts(L"Instrukcja", "fonts/PressStart2P-Regular.ttf", 42, 220, 330);
	wstring instruction = L"ZASADY GRY\nGracze obejmuj� pola na przemian d���c do obj�cia trzech p�l w jednej linii,\nprzy jednoczesnym uniemo�liwieniu tego samego przeciwnikowi.\nPole mo�e by� obj�te przez jednego gracza i\nnie zmienia swego w�a�ciciela przez ca�y przebieg gry.\n\nJAK GRA�?\n Po pierwsze wybierz plansz�:\n\n3x3\n5x5\n\n nast�pnie wybierz swojego przeciwnika:\n\n-�atwy\n-�redni\n-Zaawansowany\n-Ze znajomym\n\nKo�cowo wybierz ilo�� rozgrywek wybieraj�c odpowiedni� liczb�.\n\nI najwa�niejsze pami�taj o dobrej zabawie.";
	Texts instructionText = Texts(instruction, "fonts/Quicksand-VariableFont_wght.ttf", 16, 100, 160);
	Texts chooseGameBoard = Texts(L"PLANSZA", "fonts/PressStart2P-Regular.ttf", 40, 310, 150);
	Texts threeXthree = Texts(L"3 x 3", "fonts/PressStart2P-Regular.ttf", 32, 360, 250);
	Texts fiveXfive = Texts(L"5 x 5", "fonts/PressStart2P-Regular.ttf", 32, 360, 310);

	Texts chooseGameMode = Texts(L"TRYB GRY", "fonts/PressStart2P-Regular.ttf", 40, 280, 150);
	Texts easy = Texts(L"�atwy", "fonts/PressStart2P-Regular.ttf", 32, 340, 220);
	Texts medium = Texts(L"�redni", "fonts/PressStart2P-Regular.ttf", 32, 335, 270);
	Texts advanced = Texts(L"trudny", "fonts/PressStart2P-Regular.ttf", 32, 335, 320);
	Texts withAFriend = Texts(L"Ze znajomym", "fonts/PressStart2P-Regular.ttf", 32, 280, 370);

	Texts chooseAmountOfGames = Texts(L"LICZBA ROZGRYWEK", "fonts/PressStart2P-Regular.ttf", 40, 80, 150);
	int i_amount = 1;
	wstring w_amount = to_wstring(i_amount);
	Texts amountOfGames = Texts(w_amount, "fonts/PressStart2P-Regular.ttf", 38, 405, 295);

	Texts o_sign = Texts(L"O", "fonts/PressStart2P-Regular.ttf", 40, 310, 150);
	Texts x_sign = Texts(L"x", "fonts/PressStart2P-Regular.ttf", 40, 310, 150);

	


	Texts goBackButton = Texts(L"BACK", "fonts/PressStart2P-Regular.ttf", 14, 740, 20);

	sf::RenderWindow window(sf::VideoMode(800, 650, 32), "Pierwsze okno"/*, sf::Style::Fullscreen*/);
	
	window.setVerticalSyncEnabled(true);


	Board* plansza_5 = new Board(&window, 5);		//tworzenie plansz 3 na 3 i 5 na 5
	Board* plansza_3= new Board(&window, 3);

	while (window.isOpen())
	{
		for (int i = 0; i < vecChoices.size(); i++)
		{
			cout << vecChoices[i] << endl;
		}
		sf::Uint32 unicode = 0;
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

		if (mod == 2 && choiceMode == 1)
		{
			mod = 0;
			vecChoices.clear();
		}
		//TODO:Nie chce powraca� do pola choice mode 2 z choice mode 3
		//else if (mod == 2 && choiceMode == 2)
		//{
		//	choiceMode = 1;
		//	vecChoices.pop_back();
		//}
		//else if (mod == 2 && choiceMode == 3)
		//{
		//	//TODO:nIE CHCE TUTAJ WR�CI� DO POPRZEDNIEGO OKNA 
		//	choiceMode = 2;
		//	mod = 2;
		//	vecChoices.pop_back();
		//}
		else if (mod == 3)
		{
			mod--;
			vecChoices.pop_back();
		}
		else
			mod--;
	}
					


			if (mod == 0 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 640 && e.mouseButton.x > 210 && e.mouseButton.y > 320 && e.mouseButton.y < 364)
			{
				//Przejście do instrukcji.
				mod = 1;
			}
			else if (mod == 0 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 510 && e.mouseButton.x > 290 && e.mouseButton.y < 300 && e.mouseButton.y > 230)
			{
				//Przejście do wyboru trybu gry.
				mod = 2;
			}

			//wyb�r trybu gr 3x3 albo 5x5
			else if (mod == 2 && choiceMode == 1 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 560 && e.mouseButton.x > 360 && e.mouseButton.y > 248 && e.mouseButton.y < 285)
			{
				vecChoices.push_back(static_cast<int>(GameBoard::threexthree));
				choiceMode = 2;
			}

			else if (mod == 2 && choiceMode == 1 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 550 && e.mouseButton.x > 350 && e.mouseButton.y > 300 && e.mouseButton.y < 340)
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
			else if (i_amount != 15 && mod == 2 && choiceMode == 3 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 455 && e.mouseButton.x > 395 && e.mouseButton.y < 285 && e.mouseButton.y > 225)
			{
				i_amount++;
				
			}
			else if (i_amount != 1 && mod == 2 && choiceMode == 3 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 455 && e.mouseButton.x > 395 && e.mouseButton.y < 395 && e.mouseButton.y > 335)
			{
				i_amount--;

			}
			else if (mod == 2 && choiceMode == 3 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x < 515 && e.mouseButton.x > 320 && e.mouseButton.y < 500 && e.mouseButton.y > 460)
			{
				//tutaj chhyba inputem jakims bedzie trzeba to zrobic
				vecChoices.push_back(i_amount);
				mod = 3;
			}

			else if (mod == 3 && vecChoices[0] == 1 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left) {
				plansza_3->wstaw(e.mouseButton.x, e.mouseButton.y, gracz);
			}
			else if (mod == 3 && vecChoices[0] == 2 && e.type == sf::Event::MouseButtonReleased && e.mouseButton.button == sf::Mouse::Left) {
				plansza_5->wstaw(e.mouseButton.x, e.mouseButton.y, gracz);

			}



			//TODO: przycisk powrotu, mo¿e ma³e menu po najechaniu siê wysietla? przyciski wyboru gry bo rozpierdala to powoli.
		}



		window.clear(sf::Color(0, 0, 0));
		//TODO: Do osobnej funkjci to strzeli� by trzeba by�o.
		//Ustawia Start napis dla r�znych ekran�w.
		if (mod == 2)
		{
			startButton.text.setScale(sf::Vector2f(0.85f, 0.85f));
			startButton.text.setPosition(sf::Vector2f(340, 460));
		}
		else 
		{
			startButton.text.setScale(sf::Vector2f(1.15f, 1.15f));
			startButton.text.setPosition(sf::Vector2f(300, 240));
		}

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
			window.draw(goBackButton.text);

			break;
			//Wybór trybu gry
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
				window.draw(easy.text);
				window.draw(medium.text);
				window.draw(advanced.text);
				window.draw(withAFriend.text);

				
				window.draw(goBackButton.text);
				break;
			case 3:
				window.draw(chooseAmountOfGames.text);

				w_amount = to_wstring(i_amount);
				amountOfGames.text.setString(w_amount);
				if (i_amount > 9)
					amountOfGames.text.setPosition(sf::Vector2f(390,295));
				else
					amountOfGames.text.setPosition(sf::Vector2f(405, 295));
				window.draw(amountOfGames.text);
				if(i_amount == 1)
					window.draw(amountButtonsUp.sprite);
				else if(i_amount == 15)
					window.draw(amountButtonsDown.sprite);
				else
				{
					window.draw(amountButtonsUp.sprite);
					window.draw(amountButtonsDown.sprite);
				}
				
				window.draw(startButton.text);
				window.draw(goBackButton.text);
				//tu beda strza�ki w g�re lub w d� do 15 �eby wybrac ilo�� rozgrywek
				break;

			}
		}
			break;
			//Gra
		case 3:

			if (vecChoices[0] == 1) {
				plansza_3->rysuj();
			}
			if (vecChoices[0] == 2) {
				plansza_5->rysuj();
			}
			break;
		default:
			break;
		}
	
		

		window.display();
	}




	system("pause");
	return 0;
}
