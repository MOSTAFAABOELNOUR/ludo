#include <SFML/Graphics.hpp>
#include <iostream>
#include "Animation.h"

using namespace std;
int main()
{


	sf::RenderWindow window(sf::VideoMode(712, 712), "sfml-test", sf::Style::Close | sf::Style::Resize);
	sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f));
	player.setPosition(206.0f, 206.f);
	sf::Texture playertexture;
	playertexture.loadFromFile("dice-faces.Png");
	player.setTexture(&playertexture);

	Animation animation(&playertexture, sf::Vector2u(6, 1), 0.2f);

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		srand(time(0));
		int n = (rand() % 6 + 0);

		deltaTime = clock.restart().asSeconds();

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type) {
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:


				int l;
				if (evnt.key.code == sf::Keyboard::Space) {
					for (long long x = 0; x < 3000; x++) {
						srand(time(0));
						int n = (rand() % 6 + 0);
						deltaTime = clock.restart().asSeconds();
						 l = n;
						animation.random(n);
						player.setTextureRect(animation.uvRect);
						window.clear();
						window.draw(player);
						window.display();

					}
					cout << l << endl;
				}
			}
		}

		//animation.Update(0, deltaTime);

		player.setTextureRect(animation.uvRect);
		window.clear();
		window.draw(player);
		window.display();


	}



	return 0;
}