/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:32:34 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/05 15:32:36 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.class.hpp"

Bullet::Bullet() : AObject() {
	_pos.x = 0;
	_pos.y = 0;
	_damage = 15;
	_hitPoints = 15;
	_maxHitPoints = 15;
}

Bullet::Bullet(char dsp, int x, int y) : 
					AObject(dsp, x, y) {
	_pos.x = 0;
	_pos.y = 0;
	_damage = 15;
	_hitPoints = 15;
	_maxHitPoints = 15;						
}

Bullet::Bullet(Bullet const & src){
	*this = src;
}

Bullet::~Bullet(){

}

void	Bullet::setXY(int x, int y){
	this->_pos.x = x;
	this->_pos.y = y;
}

void	Bullet::moveXY(int changeX, int changeY){
	this->_pos.x += changeX;
	this->_pos.y += changeY;
}

void	Bullet::takeDamage(int	amount) {
	AObject::takeDamage(amount);
	if (this->_hitPoints == 0) {
		mvaddch(_pos.y, _pos.x, ' ');
		this->setCHAR(' ');
       	this->setXY( 0, 0 );
	}
}

// ------------------ for Bullets functions _________________________________//

Bullets::Bullets(){
	k = 0;
}

Bullets::Bullets (Bullets const & src) { *this = src; }

Bullets::~Bullets() {

}

Bullets & Bullets::operator=(Bullets const & src) {
	if (this != &src)
		*this = src;
	return *this;
}

void	Bullets::createBullet(int x, int y){
		if (k >= BULLET)
			return;
		bullets[k].setCHAR('^');
       	bullets[k].setXY(x, y);
    	mvaddch(bullets[k].getPosY(), bullets[k].getPosX(), bullets[k].getDispChar() + COLOR_PAIR(5));
    	k++;
}

void 	Bullets::update(){
	for(int i = 0; i < BULLET; i++)
	{
		mvaddch(bullets[i].getPosY(), bullets[i].getPosX(), ' ');
		if (bullets[i].getDispChar() == '^' && bullets[i].getPosY() - 1 >= 0)
		{
			bullets[i].setXY(bullets[i].getPosX(), bullets[i].getPosY() - 1);
			mvaddch(bullets[i].getPosY(), bullets[i].getPosX(), bullets[i].getDispChar() + COLOR_PAIR(5));
		}
	}
}

bool	Bullets::colision(Star & obj){
	for (int i = 0; i < BULLET; i++)
		if (bullets[i].getPosX() == obj.getPosX() && bullets[i].getPosY() == obj.getPosY() && (bullets[i].getDispChar() == '^'))
			return 1;
	return 0;
}

bool	Bullets::colision(Enemy & obj){
	for (int i = 0; i < BULLET; i++) {
		if (obj.getPosX() == bullets[i].getPosX() && obj.getPosY() == bullets[i].getPosY() && (obj.getDispChar() == 'T' || obj.getDispChar() == 'X'))
		{
			bullets[i].setXY(0, 0);
			bullets[i].setCHAR(' ');
			mvaddch(bullets[i].getPosY(), bullets[i].getPosX(), ' ');
			return 1;
		}
	}
	return 0;
}

