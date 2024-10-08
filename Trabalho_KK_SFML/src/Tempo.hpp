#ifndef TEMPO_HPP_
#define TEMPO_HPP_

#include "Includes.hpp"

class FonteTexto {
public:
	sf::Font fonte;
	sf::Text texto1, texto2, gameOver;
	sf::Clock clock;
	bool temporizador = false;
	int contador = 990;

	FonteTexto(){
		if (!fonte.loadFromFile("AtariSmall.ttf")) {
			std::cout << "Erro ao carregar a fonte!" << std::endl;
		}

		texto1.setFont(fonte);
		texto1.setString("990");
		texto1.setCharacterSize(80);
		texto1.setFillColor(sf::Color::Yellow);
		texto1.setPosition(sf::Vector2f(650, 5));

		gameOver.setFont(fonte);
		gameOver.setString("Game Over!");
		gameOver.setCharacterSize(100);
		gameOver.setFillColor(sf::Color::Yellow);
		gameOver.setPosition(sf::Vector2f(250, 300));

	}

	void fasePersonagem(sf::RenderWindow &window) {
		if (!fonte.loadFromFile("AtariSmall.ttf")) {
			std::cout << "Erro ao carregar a fonte!" << std::endl;
		}

		texto2.setFont(fonte);
		texto2.setString("0000");
		texto2.setCharacterSize(80);
		texto2.setFillColor(sf::Color::Yellow);
		texto2.setPosition(sf::Vector2f(200, 5));

		window.draw(texto2);
	}

	void atualizaContador(sf::RenderWindow &window, bool &temporizador) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			temporizador = true;  // Inicia o timer
		}

		if (temporizador) {
			float variacaoTempo = clock.getElapsedTime().asSeconds(); // ObtÃ©m o tempo decorrido em segundos
			if (variacaoTempo >= 1.0f) { // Atualiza o contador a cada 1 segundo
				contador -= 10; // Diminui de 10 em 10
				clock.restart(); // Reinicia o relÃ³gio
			}

			// Atualiza o texto do contador
			std::ostringstream oss;
			oss << contador;
			texto1.setString(oss.str());
		}

		    if (contador > 0) {
		    window.draw(texto1);
		    } else {
		    window.draw(gameOver);

		    }
	}
};

#endif /* TEMPO_HPP_ */
