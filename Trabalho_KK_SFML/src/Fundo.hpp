#ifndef FUNDO_HPP_
#define FUNDO_HPP_

#include "Includes.hpp"

class Fundo {
private:
	sf::Texture texturaFundo;

public:
	sf::Sprite spriteFundo;

	Fundo() {
		if (!texturaFundo.loadFromFile("NovoFundo.png")) {
			std::cout << "Erro ao carregar a textura do arquivo" << std::endl;
		}
		spriteFundo.setTexture(texturaFundo);
		spriteFundo.setPosition(0, 0);
	}
};



#endif /* FUNDO_HPP_ */
