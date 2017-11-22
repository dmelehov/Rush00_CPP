/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 22:52:00 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/04 22:52:02 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Stars.class.hpp"

Star::Star() {this->pos.x = 0; this->pos.y = 0;}

Star::Star(int x, int y) {this->pos.x = x; this->pos.y = y;}

Star::~Star() {}

Star::Star(Star const & src) { *this = src;}

void Star::update() { this->pos.y += 1; }

Star & Star::operator=(Star const & src) { 
	if (this != &src)
		*this = src;
	return *this; }

int Star::getPosX() const { return this->pos.x; }

int Star::getPosY() const  { return this->pos.y; }

void Star::setPos(int x, int y) {this->pos.x = x; this->pos.y = y;}

//--------------------- For star field -------------------------------//

StarField::StarField(Window & win){
	k = 0;
	this->createField(win);
}

StarField::StarField(StarField const & src){
	*this = src;
}

StarField::~StarField() {}

StarField & StarField::operator=(StarField const & src)
{
	if (this != &src)
		*this = src;
	return *this;
}

void StarField::createStar(Window & win, int i){
	if (rand() % 10 == 0)
    {
      	if (k >= STARS)
       		k = 0;
       	starSet[i].setPos(rand() % win.maxX, 0);
    	mvaddch(starSet[i].getPosY(), starSet[i].getPosX(), '.');
    }
    k++;
}

void StarField::createField(Window & win){
for(int i = 0; i < STARS; i++){
	createStar(win, i);
	}
}

void StarField::update(Window & win, EnemySquard & en){
	for(int i = 0; i < STARS; i++)
	{
		if (!en.colision(starSet[i]))
			mvaddch(starSet[i].getPosY(), starSet[i].getPosX(), ' ');
		if (starSet[i].getPosY() + 1 <= win.maxY)
		{
			starSet[i].setPos(starSet[i].getPosX(), starSet[i].getPosY() + 1);
		}
		else
		{
			this->createStar(win, i);
		}
		if (!en.colision(starSet[i]))
			mvaddch(starSet[i].getPosY(), starSet[i].getPosX(), '.');

	}
}
