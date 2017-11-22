/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletEn.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:32:34 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/05 15:32:36 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BulletEn.class.hpp"

BulletEn::BulletEn() : Bullet() {
}

BulletEn::BulletEn(char dsp, int x, int y) : 
					Bullet(dsp, x, y) {
}

BulletEn::BulletEn(BulletEn const & src){
	*this = src;
}

BulletEn::~BulletEn(){

}

void	BulletEn::setXY(int x, int y){
	Bullet::setXY(x, y);
}

void	BulletEn::moveXY(int changeX, int changeY){
	Bullet::moveXY(changeX, changeY);
}

void	BulletEn::takeDamage(int	amount) {
	Bullet::takeDamage(amount);
}

// ------------------ for Enemy Bullets functions ________________________//

BulletsEn::BulletsEn(){
	k = 0;
}

BulletsEn::BulletsEn(BulletsEn const & src) { *this = src; }

BulletsEn::~BulletsEn() {

}

BulletsEn & BulletsEn::operator=(BulletsEn const & src) {
	if (this != &src)
		*this = src;
	return *this;
}

void	BulletsEn::createBulletEn(int x, int y){
		if (k >= BULLET)
			k = 0;           
		bullets[k].setCHAR('!');
       	bullets[k].setXY(x, y);
    	mvaddch(bullets[k].getPosY(), bullets[k].getPosX(), bullets[k].getDispChar() + COLOR_PAIR(2));
    	k++;
}

void 	BulletsEn::update(){
	for(int i = 0; i < BULLET; i++)
	{
		mvaddch(bullets[i].getPosY(), bullets[i].getPosX(), ' ');
		if (bullets[i].getDispChar() == '!' && bullets[i].getPosY() + 1 >= 0)
		{
			bullets[i].setXY(bullets[i].getPosX(), bullets[i].getPosY() + 1);
			mvaddch(bullets[i].getPosY(), bullets[i].getPosX(), bullets[i].getDispChar() + COLOR_PAIR(2));
		}
	}
}

bool	BulletsEn::colision(Star & obj){
	for (int i = 0; i < BULLET; i++)
		if (bullets[i].getPosX() == obj.getPosX() && bullets[i].getPosY() == obj.getPosY() && (bullets[i].getDispChar() == '!'))
			return 1;
	return 0;
}

bool	BulletsEn::colision(Player & player){
	for (int i = 0; i < BULLET; i++) {
		if (player.getPosX() == bullets[i].getPosX() && player.getPosY() == bullets[i].getPosY() && (player.getDispChar() == 'A'))
		{
			bullets[i].setXY(0, 0);
			bullets[i].setCHAR(' ');
			mvaddch(bullets[i].getPosY(), bullets[i].getPosX(), ' ');
			return 1;
		}
	}
	return 0;
}

