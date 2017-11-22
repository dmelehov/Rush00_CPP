/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 10:34:01 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/05 10:34:03 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_H
# define ENEMY_CLASS_H

#include "AObjects.class.hpp"
#include "Window.class.hpp"
#include "Stars.class.hpp"

#define ENEMY 50

class Star;

class Enemy : public AObject
{

public:
	Enemy();
	Enemy(char disp, int x, int y);
	Enemy(Enemy const & src);
	virtual ~Enemy();
	
	using AObject::operator=;

	//virtual void	move(int	timeCount);
	void	setXY(int x, int y);
	virtual void	moveXY(int changeX, int changeY);

	virtual void	takeDamage(int	amount);
};

class EnemySquard {

public:
	Enemy 		enemySquard[ENEMY];

	EnemySquard();
	EnemySquard(Window & win);
	EnemySquard (EnemySquard const & src);
	EnemySquard & operator=(EnemySquard const & src);
	~EnemySquard();

	void	createEnemy(Window & win, int i);
	void 	createSquard(Window & win);
    void 	update(Window & win);
    bool	colision(Star & obj);

private:
	int			k;

};

#endif
