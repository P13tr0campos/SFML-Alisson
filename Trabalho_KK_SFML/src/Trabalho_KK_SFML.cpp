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
				"        B   OOOOO                                                                 OOOOO   B        ",
				"      BBBsss     ssssssssssssss    ssssssssssss     ssssssssssss   sssssssssssssss        BBB      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B     sssssssssssssssssssssssssssssssssss     sssssssssssssssssssssssssssssssssss     B      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
			    "      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      B     ssssssssssss   ssssssssssssssssssss     sssssssssssssssssss    ssssssssssss     B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B     sssssssssssssssssssssssssssssssssss     sssssssssssssssssssssssssssssssssss     B      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      BOOOOO                                                                           OOOOOB      ",
				"      B     ssssssssssssssssssssss   ssssssssss     ssssssssss   ssssssssssssssssssssss     B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
			    "      B                                        OOOOO                                        B      ",
				"      B                                        OOOOO                                        B      ",
				"      B     sssssssssssssssssssssssssssssssssss     sssssssssssssssssssssssssssssssssss     B      ",
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
				"                                                                                                   " };

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
				rectangle.setFillColor(sf::Color::Transparent);
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

sf::FloatRect rect;
	float dx = 0.f, dy = 0.f;
	bool sobreChao = false;

int main() {
	// CriaÃ§Ã£o da janela
	sf::RenderWindow window { sf::VideoMode(990, 740), "King Kong" };
	window.setVerticalSyncEnabled(true);

	//DeclaraÃ§Ã£o de objetos das classes
	Fundo fundo;
	Bomba bomba;
	Personagem player;
	Princesa princesa;
	FonteTexto tempo, fase, fimDeJogo;
	sf::Clock clock;
	std::vector<sf::RectangleShape> rectangles = retangles();

	bool temporizador = false; // VariÃ¡vel para controlar se o temporizador comeÃ§ou

	//Loop da janela
	while (window.isOpen()) {
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent)) {
			if (windowEvent.type == sf::Event::Closed)
				window.close();
		}

		// AtualizaÃ§Ãµes

		bomba.colisaoBomba(window);
		princesa.colisaoPrincesa(window);
		player.updatePlayer();
		player.mover();
		//player.colisao(tilemap, h, l);

		//Desenhar
		window.clear(sf::Color::White);
		window.draw(fundo.spriteFundo);

		for (unsigned int i = 0; i < rectangles.size(); ++i) {
			if (rectangles.at(i).getGlobalBounds().intersects(player.spriteJogador.getGlobalBounds()) and rectangles.at(i).getSize() == sf::Vector2f(10, 10)) {
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
		fimDeJogo.atualizaContador(window, temporizador);
		window.display();
	}
}
