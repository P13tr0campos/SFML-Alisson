#ifndef ENTIDADES_HPP_
#define ENTIDADES_HPP_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "includes/math.hpp"

//---------------------------------------FUNDO------------------------------------------------------

class Fundo {
public:
	sf::Texture texturaFundo;
	sf::Sprite spriteFundo;

	Fundo() {
		if (!texturaFundo.loadFromFile("NovoFundo.png")) {
			std::cout << "Erro ao carregar a textura do arquivo" << std::endl;
		}
		spriteFundo.setTexture(texturaFundo);
		spriteFundo.setPosition(0, 0);
	}
};

//-----------------------------------------------BOMBA---------------------------------------------//
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
		spriteBomba.setPosition(130, 130);
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

//---------------------------------------PRINCESA----------------------------------------------------

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

//--------------------------------------- JOGADOR----------------------------------------------------
//Dica, procurar usar técnica de encapsulamento, sem variaveis Globais, apenas uma dica!!!
class Personagem {
public:
	sf::Texture TexturaJogador[3];
	sf::Sprite spriteJogador;
	int textura_corrente = 0;
	int contador = 0;
	float gravidade = 0.2f;
	bool ColisaoChao = true;
	float puloForca = -4.6f;
	float alturaChao = 640;
	float velocidadeMovimento = 2.0f;

	Personagem() {
		TexturaJogador[0].loadFromFile("player-sfml-TP_Andando.png",
				sf::IntRect(0, 0, 16, 48));
		TexturaJogador[1].loadFromFile("player-sfml-TP_Andando.png",
				sf::IntRect(16, 0, 32, 48));
		TexturaJogador[2].loadFromFile("player-sfml-TP_Andando.png",
				sf::IntRect(32, 0, 48, 48));
		spriteJogador.setTexture(TexturaJogador[textura_corrente]);
		spriteJogador.setPosition(130, alturaChao);
		spriteJogador.setScale(3, 3);
	}

	void updatePlayer() {
		contador++;
		if (contador >= 10) {
			contador = 0;
			textura_corrente = (textura_corrente + 1) % 3;
			spriteJogador.setTexture(TexturaJogador[textura_corrente]);
		}
	}

	/*void mover() {
	 sf::Vector2f posicao = spriteJogador.getPosition();

	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
	 if (posicao.x < 870) {
	 spriteJogador.move(velocidadeMovimento, 0);
	 spriteJogador.setScale(3, 3);
	 }
	 }
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
	 if (posicao.x > 115) {
	 spriteJogador.move(-velocidadeMovimento, 0);
	 spriteJogador.setScale(-3, 3); // inverte escala
	 }
	 }
	 if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
	 if (spriteJogador.getPosition().y >0 ) //adcionar limite
	 spriteJogador.setPosition(posicao + sf::Vector2f(0, -1));
	 //this->spriteJogador.move(0, -5);
	 }
	 if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
	 if (spriteJogador.getPosition().y < 0 ) //adcionar limite
	 spriteJogador.setPosition(posicao + sf::Vector2f(0, 1));
	 }



	 //Colisão
	 if (spriteJogador.getPosition().y >= alturaChao) {
	 spriteJogador.setPosition(spriteJogador.getPosition().x, alturaChao);
	 ColisaoChao = true;
	 velocidadeY = 0;
	 }

	 // Pulo
	 if (ColisaoChao && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
	 velocidadeY = puloForca;
	 ColisaoChao = false;
	 }

	 velocidadeY += gravidade;
	 spriteJogador.move(0, velocidadeY);



	 }*/

	void mover() {


		sf::Vector2f posicao = spriteJogador.getPosition();

		// Movimentação horizontal
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (posicao.x < 870) {
				spriteJogador.move(velocidadeMovimento, 0);
				spriteJogador.setScale(3, 3);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			if (posicao.x > 115) {
				spriteJogador.move(-velocidadeMovimento, 0);
				spriteJogador.setScale(-3, 3); // inverte escala
			}
		}

		// Pulo
		if (ColisaoChao && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			gravidade = -4;
			spriteJogador.move(0, puloForca);
			ColisaoChao = false;
		}

		// Aplica a gravidade apenas se não estiver em uma escada



		// Move o personagem verticalmente
		//spriteJogador.move(0, velocidadeY);


	}

	/*  bool colisao(sf::FloatRect Objeto) {
	 return spriteJogador.getGlobalBounds().intersects(Objeto);
	 }*/

	/*void colisao(const sf::String tilemap[], int h, int l) {
	 // Obtém a posição atual do personagem
	 sf::Vector2f posicao = spriteJogador.getPosition();
	 int tileX = posicao.x / 30;
	 int tileY = posicao.y / 30;

	 std::cout << "Posição X: " << posicao.x << " Posição Y: " << posicao.y << std::endl;
	 std::cout << "Tile X: " << tileX << " Tile Y: " << tileY << std::endl;

	 bool colidindoComEscada = false;

	 // Verifica se o personagem está dentro dos limites do mapa
	 if (tileX >= 0 && tileX < l && tileY >= 0 && tileY < h) {
	 bool colidindoComEscada = (tilemap[tileY][tileX] == 'O');

	 // Permite movimento vertical se o personagem estiver em uma escada
	 if (colidindoComEscada) {
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
	 spriteJogador.move(0, -5.0f);  // Sobe mais rápido para testar
	 }
	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
	 spriteJogador.move(0, 5.0f);   // Desce mais rápido para testar
	 }
	 }

	 // Verifica colisão com o chão
	 if (!colidindoComEscada) {
	 if (spriteJogador.getPosition().y >= alturaChao) {
	 spriteJogador.setPosition(spriteJogador.getPosition().x, alturaChao);
	 ColisaoChao = true;
	 velocidadeY = 0;
	 }
	 }
	 }

	 // Aplica a gravidade apenas se não estiver em uma escada
	 if (!colidindoComEscada) {
	 velocidadeY += gravidade;
	 spriteJogador.move(0, velocidadeY);
	 }
	 }*/

	void colisao(const sf::String tilemap[], int h, int l) {
		sf::Vector2f posicao = spriteJogador.getPosition();
		int tileX = posicao.x / 30;
		int tileY = posicao.y / 30;

		bool colidindoComEscada = false;

		if (tileX >= 0 && tileX < l && tileY >= 0 && tileY < h) {
			colidindoComEscada = (tilemap[tileY][tileX] == 'O');

			// Permite movimento vertical se o personagem estiver em uma escada
			if (colidindoComEscada) {
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

		// Aplica a gravidade apenas se não estiver em uma escada
		if (!colidindoComEscada) {
			//velocidadeY = gravidade;
			//spriteJogador.move(0, velocidadeY);
		}
	}

};

//------------------------------------------- TEMPO E FASE ---------------------------------------------

class FonteTexto {
public:
	sf::Font fonte;
	sf::Text texto1, texto2;
	sf::Clock clock;
	bool temporizador = false;
	int contador = 990;

	FonteTexto() {
		if (!fonte.loadFromFile("AtariSmall.ttf")) {
			std::cerr << "Erro ao carregar a fonte!" << std::endl;
		}

		texto1.setFont(fonte);
		texto1.setString("990");
		texto1.setCharacterSize(80);
		texto1.setFillColor(sf::Color::Yellow);
		texto1.setPosition(sf::Vector2f(650, 5));

	}

	void fasePersonagem(sf::RenderWindow &window) {
		if (!fonte.loadFromFile("AtariSmall.ttf")) {
			std::cerr << "Erro ao carregar a fonte!" << std::endl;
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
			float variacaoTempo = clock.getElapsedTime().asSeconds(); // Obtém o tempo decorrido em segundos
			if (variacaoTempo >= 1.0f) { // Atualiza o contador a cada 1 segundo
				contador -= 10; // Diminui de 10 em 10
				clock.restart(); // Reinicia o relógio
			}

			// Atualiza o texto do contador
			std::ostringstream oss;
			oss << contador;
			texto1.setString(oss.str());
		}

		window.draw(texto1);
	}
};

#endif /* ENTIDADES_HPP_ */
