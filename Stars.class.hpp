/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stars.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 22:52:07 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/04 22:52:12 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR_CLASS_H
#define STAR_CLASS_H

#include "game.hpp"
#include "Window.class.hpp"
#include "Enemy.class.hpp"

#define STARS 50

class EnemySquard;

class Star {

public:
	Star();
    Star(int x, int y);
    Star(Star const & src);
    ~Star();

    void update();

    Star & operator=(Star const & src);

    int getPosX() const;
    int getPosY() const;
    void setPos(int x, int y);
   
private:
    t_pos pos;
};



class StarField {

public:
	StarField();
	StarField(Window & win);
	StarField(StarField const & src);
	StarField & operator=(StarField const & src);
	~StarField();

	void	createStar(Window & win, int i);
	void 	createField(Window & win);
    void 	update(Window & win, EnemySquard & en);

private:
	int			k;
    Star 		starSet[STARS];

};

#endif