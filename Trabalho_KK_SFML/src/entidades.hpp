/*
 * entidades.hpp
 *
 *  Created on: 30 de ago. de 2024
 *      Author: campo
 */
#include <iostream>

#include "includes/math.hpp"

#ifndef ENTIDADES_HPP_
#define ENTIDADES_HPP_

enum ID{
	vazio =0,
	player,
	projeteis,
	inimigo,
	plataformas
};

class entidade{
protected:
	ID id;

public:
	entidade(math::coordenada<float> position = math::coordenada(0.f, 0.f),math::coordenada<float> tamnaho = math::coordenada(0.f, 0.f), ID id = vazio);

	~entidade();

	void setaPosicao(math::coordenada pos);

	math::coordenada pegaPosicao() const;

	ID getId() const;


};



#endif /* ENTIDADES_HPP_ */
