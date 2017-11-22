/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AObjects.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 20:45:35 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/04 20:46:06 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AObjects.class.hpp"

AObject::AObject() : _disp_char(' '), _damage(0), _hitPoints(30), _maxHitPoints(30) { _pos.x = 10; _pos.y = 10; }

AObject::AObject(char dsp, int x, int y) :  _disp_char(dsp), _damage(0), _hitPoints(30), _maxHitPoints(30) {_pos.x = x; _pos.y = y;}

AObject::AObject(AObject const & src) { *this = src; }

AObject::~AObject() {}
	
AObject & AObject::operator=(AObject const & rhs) {
	if (this != &rhs)
		*this = rhs;
	return *this;
}

char 	AObject::getDispChar() const { return this->_disp_char; }
int		AObject::getPosX() const { return this->_pos.x; }
int		AObject::getPosY() const { return this->_pos.y; }
int		AObject::getHP() const { return this->_hitPoints; }
int		AObject::getDamage() const { return this->_damage; }

void	AObject::takeDamage(int	amount){
	if ((_hitPoints - amount) < 0)
		_hitPoints = 0;
	else
		_hitPoints -= amount;

}

void	AObject::setCHAR(char c){
	_disp_char = c;
}

// void	AObject::attack(){
// 	if ()
// }


bool	AObject::colision(AObject & obj) {
	return (_pos.x == obj.getPosX() && _pos.y == obj.getPosY());
}
