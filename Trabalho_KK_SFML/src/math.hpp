/*
 * header.hpp
 *
 *  Created on: 30 de ago. de 2024
 *      Author: campos
 */

#ifndef MATH_HPP_
#define MATH_HPP_

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

template <typename coord>
class coordenada {
public:
	coord x;
	coord y;
public:

	void operator=(coordenada<coord> other);
	void operator+=(coordenada<coord> other);
	void operator-=(coordenada<coord> other);
	void operator*=(coordenada<coord> other);
	void operator/=(coordenada<coord> other);

};

template <typename coord>
	coordenada<coord>:: coordenada(coord x ,coord y){
			x(x),
			y(y);
}

template <typename coord>
	coordenada<coord>:: coordenada(){
		this-> x = 0;
		this-> y = 0;
	}
template <typename coord>
	void coordenada<coord>:: operator=(coordenada<coord> other){

		this->x = other.x;
		this->y = other.y;

	}


#endif /* MATH_HPP_ */
