#ifndef JOGADOR_HPP_
#define JOGADOR_HPP_

#include "Includes.hpp"

class Personagem {
public:
	sf::Texture TexturaJogador[3];
	sf::Sprite spriteJogador;
	int textura_corrente = 0;
	int contador = 0;
	float gravidade = 0.2f;
	bool ColisaoChao = true;
	float puloForca = -4.6f;
	float alturaChao = 655;
	float velocidadeMovimento = 2.0f;

	Personagem() {
		TexturaJogador[0].loadFromFile("player-sfml-TP_Andando.png",// @suppress("Invalid arguments")
				sf::IntRect(0, 0, 16, 48));
		TexturaJogador[1].loadFromFile("player-sfml-TP_Andando.png", // @suppress("Invalid arguments")
				sf::IntRect(16, 0, 32, 48));
		TexturaJogador[2].loadFromFile("player-sfml-TP_Andando.png", // @suppress("Invalid arguments")
				sf::IntRect(32, 0, 48, 48));
		spriteJogador.setTexture(TexturaJogador[textura_corrente]);
		spriteJogador.setPosition(130, alturaChao);
		spriteJogador.setScale(2, 2);
	}

	void updatePlayer() {
		contador++;
		if (contador >= 10) {
			contador = 0;
			textura_corrente = (textura_corrente + 1) % 3;
			spriteJogador.setTexture(TexturaJogador[textura_corrente]);
		}
	}

	void mover() {

		sf::Vector2f posicao = spriteJogador.getPosition();

		// Movimentação horizontal
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (posicao.x < 870) {
				spriteJogador.move(velocidadeMovimento, 0);
				spriteJogador.setScale(2, 2);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (posicao.x > 115) {
				spriteJogador.move(-velocidadeMovimento, 0);
				spriteJogador.setScale(-2, 2); // inverte escala
			}
		}

		// Pulo
		if (ColisaoChao && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			gravidade = -4;
			spriteJogador.move(0, puloForca);
			ColisaoChao = false;
		}

	}

	void colisao(const sf::String tilemap[], int h, int l) {
		sf::Vector2f posicao(sf::Vector2f(spriteJogador.getPosition().x ,spriteJogador.getPosition().y + 25));
		int tileX = posicao.x / 10;
		int tileY = posicao.y / 10;

		bool colidindoComEscada = false;

		if (tileX >= 0 && tileX < l && tileY >= 0 && tileY < h) {
			colidindoComEscada = (tilemap[tileY][tileX] == 'O');

			// Permite movimento vertical se o personagem estiver em uma escada
			if (colidindoComEscada) {
				std::cout << "Colidiu" << std::endl;
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					gravidade = 0;
					spriteJogador.move(0, -5); // Sobe
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
					gravidade = 0;
					spriteJogador.move(0, 5.0f); // Desce
				}

			}else{
				if(gravidade > 10.0){
					gravidade = 0;
				}else{
					gravidade += 0.2;
				}
				this->spriteJogador.move(0,gravidade);

			}
			// Verifica colisão com o chão
			if (spriteJogador.getPosition().y >= alturaChao) {
				spriteJogador.setPosition(spriteJogador.getPosition().x,alturaChao);
				ColisaoChao = true;
				//velocidadeY = 0;
			}
		}
	}

};

#endif /* JOGADOR_HPP_ */

