/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletEn.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:32:43 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/05 15:32:45 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLETEN_CLASS_H
# define BULLETEN_CLASS_H

#include "AObjects.class.hpp"
#include "Window.class.hpp"
#include "Stars.class.hpp"
#include "Enemy.class.hpp"
#include "Bullet.class.hpp"

class Star;

class BulletEn : public Bullet
{

public:
	BulletEn();
	BulletEn(char disp, int x, int y);
	BulletEn(BulletEn const & src);
	virtual ~BulletEn();
	
	using Bullet::operator=;

	//virtual void	move(int	timeCount);
	void	setXY(int x, int y);
	virtual void	moveXY(int changeX, int changeY);

	virtual void	takeDamage(int	amount);
};

class BulletsEn {

public:
	int		k;
	BulletEn 		bullets[BULLET];

	BulletsEn();
	BulletsEn(BulletsEn const & src);
	BulletsEn & operator=(BulletsEn const & src);
	~BulletsEn();

	void	createBulletEn(int x, int y);
    void 	update();
    bool	colision(Star & obj);
    bool	colision(Player & player);

};

#endif
