#ifndef BOMBA_HPP_
#define BOMBA_HPP_

#include "Includes.hpp"

class Bomba {
public:
	sf::Texture texturaBomba[3];
	sf::Sprite spriteBomba;
	int textura_corrente = 0;
	int contador = 0; // Contador para troca de animação
	float velocidade = 200.0f; // Velocidade de movimento da bomba
	bool MovimentoDireita = true; // Direção do movimento da bomba
	sf::Clock TempoMovimento; // Relógio para calcular o tempo de movimento
	sf::Clock TempoAnimacao; // Relógio para calcular o tempo de animação

	// Limites da faixa onde a bomba pode se mover
	float DistanciaEsquerda = 150.f;   // Distância da borda esquerda da janela
	float DistanciaDireita = 830.f; // Distância da borda direita da janela (986 - largura da bomba)

	//Construtor
	Bomba() {
		texturaBomba[0].loadFromFile("bombC.png", sf::IntRect(0, 0, 32, 96));
		texturaBomba[1].loadFromFile("bombC.png", sf::IntRect(32, 0, 64, 96));
		texturaBomba[2].loadFromFile("bombC.png", sf::IntRect(64, 0, 96, 96));
		spriteBomba.setTexture(texturaBomba[textura_corrente]);
		spriteBomba.setPosition (220, 220);
		spriteBomba.setScale(0.6 ,0.6);
	}

	// Atualiza a animação da bomba
	void update() {
		if (TempoAnimacao.getElapsedTime().asMilliseconds() >= 100) { // Troca a textura a cada 100ms
			contador++;
			if (contador >= 10) { // Após 10 iterações, reinicia o contador
				contador = 0;
				textura_corrente = (textura_corrente + 1) % 3;
				spriteBomba.setTexture(texturaBomba[textura_corrente]);
			}
			TempoAnimacao.restart(); // Reinicia o relógio de animação
		}
	}

	void movimentacao(sf::RenderWindow &window) {
		sf::Time Tempo = TempoMovimento.restart();

		// Move a bomba para a direita ou esquerda e verifica colisão com as bordas da faixa verde
		if (MovimentoDireita) {
			spriteBomba.move(velocidade * Tempo.asSeconds(), 0); // Move a bomba para a direita
			if (spriteBomba.getPosition().x
					+ spriteBomba.getGlobalBounds().width >= DistanciaDireita) {
				MovimentoDireita = false; // Inverte a direção ao atingir o limite direito
			}
		} else {
			spriteBomba.move(-velocidade * Tempo.asSeconds(), 0); // Move a bomba para a esquerda
			if (spriteBomba.getPosition().x <= DistanciaEsquerda) {
				MovimentoDireita = true; // Inverte a direção ao atingir o limite esquerdo
			}
		}
	}

	void colisaoBomba(sf::RenderWindow &window) {
		movimentacao(window); // Atualiza a movimentação da bomba
		update(); // Atualiza a animação da bomba
	}
};


#endif /* BOMBA_HPP_ */
