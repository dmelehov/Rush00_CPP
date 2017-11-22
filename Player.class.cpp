/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:58:27 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/04 19:58:29 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player() : AObject() {
	_disp_char = 'A';
	_pos.x = 5;
	_pos.y = 5;
	_damage = 30;
	_hitPoints = 100;
	_maxHitPoints = 100;
}

Player::Player(char dsp, int x, int y) : 
					AObject(dsp, x, y){
	_pos.x = 5;
	_pos.y = 5;
	_damage = 30;
	_hitPoints = 100;
	_maxHitPoints = 100;

}

Player::Player(Player const & src){
	*this = src;
}

Player::~Player(){

}
	
void	Player::moveXY(int changeX, int changeY){
	this->_pos.x += changeX;
	this->_pos.y += changeY;
}

void	Player::takeDamage(int	amount) {
	AObject::takeDamage(amount);
	if (this->_hitPoints == 0){
		endwin();
		std::cout << "<< GAME  OVER >>" << std::endl;
		exit(1);
	}
}