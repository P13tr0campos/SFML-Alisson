#include "Includes.hpp"
#include "Fundo.hpp"
#include "Princesa.hpp"
#include "Bomba.hpp"
#include "Jogador.hpp"
#include "Tempo.hpp"

const int h = 74, l = 99;
sf::String tilemap[h] =


			  { "                                                                                                   ",
				"                                                                                                   ",
				"                                                                                                   ",
				"                                                                                                   ",
				"                                                                                                   ",
				"                                                                                                   ",
				"                                                                                                   ",
				"                                                                                                   ",
				"                                                                                                   ",
				"                                                                                                   ",
				"           BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB           ",
				"           B                                   OOOOO                                   B           ",
				"           B                                   OOOOO                                   B           ",
				"           B                                   OOOOO                                   B           ",
				"           B                                   OOOOO                                   B           ",
				"           B                                   OOOOO                                   B           ",
				"        BBBB     sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss     BBBB        ",
				"        B   OOOOO                                                                 OOOOO   B        ",
				"        B   OOOOO                                                                 OOOOO   B        ",
				"        B   OOOOO                                                                 OOOOO   B        ",
				"        B   OOOOO                                                                 OOOOO   B        ",
				"        B   OOOOO                                                                 OOOOO   B        ",
				"        B   OOOOO                                                                 OOOOO   B        ",
				"        B   OOOOO                              OOOOO                              OOOOO   B        ",
				"      BBBssssssssssssssssssssss    ssssssssssssOOOOOssssssssssss   sssssssssssssssssssssssBBB      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B     sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss     B      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
			    "      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                   OOOOO                                   OOOOOB      ",
				"      Bsssssssssssssssss   ssssssssssssssssssssOOOOOsssssssssssssssssss    sssssssssssssssssB      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B     sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss     B      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                   OOOOO                                   OOOOOB      ",
				"      Bsssssssssssssssssssssssssss   ssssssssssOOOOOssssssssss   sssssssssssssssssssssssssssB      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
			    "      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B     sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss     B      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB      ",
				"                                                                                                   ",
				"                                                                                                   ",
				"                                                                                                   ",
				"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB" };



std::vector<sf::RectangleShape> retangles() {
	std::vector<sf::RectangleShape> retangles;
	sf::RectangleShape rectangle(sf::Vector2f(10, 10));
	for (unsigned int i = 0; i < h; ++i) {
		for (int j { }; j < l; ++j) {
			if (tilemap[i][j] == 'B') {
				rectangle.setSize(sf::Vector2f(10, 10));
				rectangle.setFillColor(sf::Color::Transparent);
			}
			if (tilemap[i][j] == 'O') {
				rectangle.setSize(sf::Vector2f(10, 10));
				rectangle.setFillColor(sf::Color::Transparent);
			}
			if (tilemap[i][j] == 's') {
				rectangle.setSize(sf::Vector2f(10, 10));
				rectangle.setFillColor(sf::Color {0,0,0,1});

			}
			if (tilemap[i][j] == ' ') {
				continue;
			}
			rectangle.setPosition(j * 10, i * 10);
			retangles.push_back(rectangle);
		}

	}

	return retangles;
}

int main() {
	// Criação da janela
	sf::RenderWindow window { sf::VideoMode(990, 750), "King Kong" };
	window.setVerticalSyncEnabled(true);

	//Declaração de objetos das classes
	Fundo fundo;
	Bomba bomba;
	Personagem player;
	Princesa princesa;
	FonteTexto tempo, fase;
	sf::Clock clock;
	std::vector<sf::RectangleShape> rectangles = retangles();

	bool temporizador = false; // Variável para controlar se o temporizador começou

	//Loop da janela
	while (window.isOpen()) {
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent)) {
			if (windowEvent.type == sf::Event::Closed)
				window.close();
		}

		// Atualizações

		bomba.colisaoBomba(window);
		princesa.colisaoPrincesa(window);
		player.updatePlayer();
		player.mover();
		player.colisao(tilemap, h, l);


		//Desenhar
		window.clear(sf::Color::White);
		window.draw(fundo.spriteFundo);

		for (unsigned int i = 0; i < rectangles.size(); ++i) {
			if (rectangles.at(i).getGlobalBounds().intersects(player.spriteJogador.getGlobalBounds()) and rectangles.at(i).getFillColor() == sf::Color {0,0,0,1}) {
					player.spriteJogador.move(0, -player.gravidade);
					player.ColisaoChao = true;
			}

			window.draw(rectangles.at(i));
		}

		window.draw(bomba.spriteBomba);
		window.draw(princesa.spritePrincesa);
		window.draw(player.spriteJogador);
		tempo.atualizaContador(window, temporizador);
		fase.fasePersonagem(window);
		window.display();
	}
}
