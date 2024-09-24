#ifndef ENTIDADES_HPP_
#define ENTIDADES_HPP_

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "includes/math.hpp"

class Fundo {
public:
    sf::Texture texturaFundo;
    sf::Sprite spriteFundo;

//---------------------------------------FUNDO------------------------------------------------------
    Fundo() {
        if (!texturaFundo.loadFromFile("Fundo.png")) {
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
    sf::Clock TempoAnimacao;// Relógio para calcular o tempo de animação


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

    void movimentacao(sf::RenderWindow& window) {
            sf::Time Tempo = TempoMovimento.restart();

            // Move a bomba para a direita ou esquerda e verifica colisão com as bordas da faixa verde
            if (MovimentoDireita) {
                spriteBomba.move(velocidade * Tempo.asSeconds(), 0); // Move a bomba para a direita
                if (spriteBomba.getPosition().x + spriteBomba.getGlobalBounds().width >= DistanciaDireita) {
                	MovimentoDireita = false; // Inverte a direção ao atingir o limite direito
                }
            } else {
                spriteBomba.move(-velocidade * Tempo.asSeconds(), 0); // Move a bomba para a esquerda
                if (spriteBomba.getPosition().x <= DistanciaEsquerda) {
                	MovimentoDireita = true; // Inverte a direção ao atingir o limite esquerdo
                }
            }
        }

      void colisaoBomba(sf::RenderWindow& window) {
            movimentacao(window); // Atualiza a movimentação da bomba
            update(); // Atualiza a animação da bomba
        }
};

//--------------------------------------- JOGADOR----------------------------------------------------


class Personagem {
public:
    sf::Texture TexturaJogador[3];
    sf::Sprite spriteJogador;
    int textura_corrente = 0;
    int contador = 0;
    float velocidadeY = 0;
    bool ColisaoChao = true;
    float gravidade = 0.2f;
    float puloForca = -4.6f;
    float alturaChao = 630;

    Personagem() {
        TexturaJogador[0].loadFromFile("player-sfml-TP_Andando.png", sf::IntRect(0, 0, 16, 48));
        TexturaJogador[1].loadFromFile("player-sfml-TP_Andando.png", sf::IntRect(16, 0, 32, 48));
        TexturaJogador[2].loadFromFile("player-sfml-TP_Andando.png", sf::IntRect(32, 0, 48, 48));
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

    void mover() {
        sf::Vector2f posicao = spriteJogador.getPosition();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            spriteJogador.move(2, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            spriteJogador.move(-2, 0);
        }

        //Colisao
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
    	}

    	bool colisao(sf::FloatRect Objeto) {
    		return spriteJogador.getGlobalBounds().intersects(Objeto);
    	}
 };


#endif /* ENTIDADES_HPP_ */
