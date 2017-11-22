/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:32:43 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/05 15:32:45 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_CLASS_H
# define BULLET_CLASS_H

#include "AObjects.class.hpp"
#include "Window.class.hpp"
#include "Stars.class.hpp"
#include "Enemy.class.hpp"

#define BULLET 9999

class Star;

class Bullet : virtual public AObject
{

public:
	Bullet();
	Bullet(char disp, int x, int y);
	Bullet(Bullet const & src);
	virtual ~Bullet();
	
	using AObject::operator=;

	//virtual void	move(int	timeCount);
	void	setXY(int x, int y);
	virtual void	moveXY(int changeX, int changeY);

	virtual void	takeDamage(int	amount);
};

class Bullets {

public:
	int		k;
	Bullet 		bullets[BULLET];

	Bullets();
	Bullets(Bullets const & src);
	Bullets & operator=(Bullets const & src);
	~Bullets();

	void	createBullet(int x, int y);
    void 	update();
    bool	colision(Star & obj);
    bool	colision(Enemy & obj);

};

#endif
