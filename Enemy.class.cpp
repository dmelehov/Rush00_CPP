/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 10:33:51 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/05 10:33:53 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"

Enemy::Enemy() : AObject() {
//	char 	disp[2] = {'T', 'X'};
//	this->_disp_char = ' '/*disp[rand() % 2]*/;
	_pos.x = 0;
	_pos.y = 0;
	_damage = 15;
	_hitPoints = 30;
	_maxHitPoints = 30;
}

Enemy::Enemy(char dsp, int x, int y) : 
					AObject(dsp, x, y) {
//	char 	disp[2] = {'T', 'X'};
//	this->_disp_char = disp[rand() % 2];
	_pos.x = 0;
	_pos.y = 0;
	_damage = 15;
	_hitPoints = 30;
	_maxHitPoints = 30;						
}

Enemy::Enemy(Enemy const & src){
	*this = src;
}

Enemy::~Enemy(){

}

void	Enemy::setXY(int x, int y){
	this->_pos.x = x;
	this->_pos.y = y;
}

void	Enemy::moveXY(int changeX, int changeY){
	this->_pos.x += changeX;
	this->_pos.y += changeY;
}

void	Enemy::takeDamage(int	amount) { 
	AObject::takeDamage(amount);
	if (this->_hitPoints == 0) {
		mvaddch(_pos.y, _pos.x, ' ');
		_pos.y = 0;
		_pos.x = 0;
		_disp_char = ' ';
	}
}

// ------------------ for squard functions _________________________________//

EnemySquard::EnemySquard(Window & win){
	k = 0;
	this->createSquard(win);
}

EnemySquard::EnemySquard (EnemySquard const & src) { *this = src; }

EnemySquard::~EnemySquard() {

}

EnemySquard & EnemySquard::operator=(EnemySquard const & src) {
	if (this != &src)
		*this = src;
	return *this;
}

void	EnemySquard::createEnemy(Window & win, int i){
	if (rand() % 15 == 0)
    {
      	if (k >= ENEMY)
       		k = 0;
       	char 	disp[2] = {'T', 'X'};
		enemySquard[i].setCHAR(disp[rand() % 2]);
       	enemySquard[i].setXY(rand() % win.maxX, 0);
       	if (enemySquard[i].getDispChar() == 'T')
    		mvaddch(enemySquard[i].getPosY(), enemySquard[i].getPosX(), enemySquard[i].getDispChar() + COLOR_PAIR(3));
    	else
    		mvaddch(enemySquard[i].getPosY(), enemySquard[i].getPosX(), enemySquard[i].getDispChar() + COLOR_PAIR(4));
    }
    k++;
}
void 	EnemySquard::createSquard(Window & win){
	for (int i = 0; i < ENEMY; i++){
		createEnemy(win, i);
	}
}

void 	EnemySquard::update(Window & win){
	for(int i = 0; i < ENEMY; i++)
	{
		mvaddch(enemySquard[i].getPosY(), enemySquard[i].getPosX(), ' ');
		if (enemySquard[i].getPosY() + 1 <= win.maxY)
		{
			enemySquard[i].setXY(enemySquard[i].getPosX(), enemySquard[i].getPosY() + 1);
			if (enemySquard[i].getDispChar() == 'T')
    			mvaddch(enemySquard[i].getPosY(), enemySquard[i].getPosX(), enemySquard[i].getDispChar() + COLOR_PAIR(3));
    		else
    			mvaddch(enemySquard[i].getPosY(), enemySquard[i].getPosX(), enemySquard[i].getDispChar() + COLOR_PAIR(4));
		}
		else
		{
			this->createEnemy(win, i);
			if (enemySquard[i].getDispChar() == 'T')
    			mvaddch(enemySquard[i].getPosY(), enemySquard[i].getPosX(), enemySquard[i].getDispChar() + COLOR_PAIR(3));
    		else
    			mvaddch(enemySquard[i].getPosY(), enemySquard[i].getPosX(), enemySquard[i].getDispChar() + COLOR_PAIR(4));
		}
	}
}

bool	EnemySquard::colision(Star & obj){
	for (int i = 0; i < ENEMY; i++)
		if (enemySquard[i].getPosX() == obj.getPosX() && enemySquard[i].getPosY() == obj.getPosY() && (enemySquard[i].getDispChar() == 'T' || enemySquard[i].getDispChar() == 'X'))
			return 1;
	return 0;
}
