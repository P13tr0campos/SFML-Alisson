#ifndef PRINCESA_HPP_
#define PRINCESA_HPP_

#include "Includes.hpp"

class Princesa {
public:
	sf::Texture texturaPrincesa[2];
	sf::Sprite spritePrincesa;
	int textura_correntePrincesa = 0;
	int contadorPrincesa = 0; // Contador para troca de animação
	float velocidadePrincesa = 200.0f;
	bool MovimentoDireitaPrincesa = true;
	sf::Clock TempoMovimentoPrincesa;
	sf::Clock TempoAnimacaoPrincesa;

	// Limites da faixa onde a bomba pode se mover
	float DistanciaEsquerda = 400.f;
	float DistanciaDireita = 600.f;

	//Construtor
	Princesa() {
		texturaPrincesa[0].loadFromFile("mulher-sfml-TP.png",
				sf::IntRect(0, 0, 16, 17));
		texturaPrincesa[1].loadFromFile("mulher-sfml-TP.png",
				sf::IntRect(16, 0, 32, 17));
		spritePrincesa.setTexture(texturaPrincesa[textura_correntePrincesa]);
		spritePrincesa.setPosition(400, 65);
		spritePrincesa.setScale(2, 2);
	}

	// Atualiza a animação da bomba
	void updatePrincesa() {
		if (TempoAnimacaoPrincesa.getElapsedTime().asMilliseconds() >= 100) { // Troca a textura a cada 100ms
			contadorPrincesa++;
			if (contadorPrincesa >= 10) { // Após 10 iterações, reinicia o contador
				contadorPrincesa = 0;
				textura_correntePrincesa = (textura_correntePrincesa + 1) % 2;
				spritePrincesa.setTexture(
						texturaPrincesa[textura_correntePrincesa]);
			}
			TempoAnimacaoPrincesa.restart(); // Reinicia o relógio de animação
		}
	}

	void movimentacaoPrincesa(sf::RenderWindow &window) {
		sf::Time TempoPrincesa = TempoMovimentoPrincesa.restart();

		// Move a bomba para a direita ou esquerda e verifica colisão com as bordas da faixa verde
		if (MovimentoDireitaPrincesa) {
			spritePrincesa.move(velocidadePrincesa * TempoPrincesa.asSeconds(),
					0);
			if (spritePrincesa.getPosition().x
					+ spritePrincesa.getGlobalBounds().width
					>= DistanciaDireita) {
				MovimentoDireitaPrincesa = false; // Inverte a direção ao atingir o limite direito
			}
		} else {
			spritePrincesa.move(-velocidadePrincesa * TempoPrincesa.asSeconds(),
					0);
			if (spritePrincesa.getPosition().x <= DistanciaEsquerda) {
				MovimentoDireitaPrincesa = true; // Inverte a direção ao atingir o limite esquerdo
			}
		}
	}

	void colisaoPrincesa(sf::RenderWindow &window) {
		movimentacaoPrincesa(window);
		updatePrincesa();
	}
};


#endif /* PRINCESA_HPP_ */
