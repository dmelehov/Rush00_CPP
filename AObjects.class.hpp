/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AObjects.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 20:43:31 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/04 20:45:22 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AOBJECTS_CLASS_H
# define AOBJECTS_CLASS_H

#include "game.hpp"

class	AObject{

protected:
	char	_disp_char;
	t_pos	_pos;
	int		_damage;
	int		_hitPoints;
	int		_maxHitPoints;


public:
	AObject();
	AObject(char dsp, int x, int y);
	AObject(AObject const & src);
	virtual ~AObject();
	
	AObject & operator=(AObject const & rhs);

	char 	getDispChar() const;
	int		getPosX() const;
	int		getPosY() const;
	int		getHP() const;
	int		getDamage() const;

	void	setCHAR(char);

	virtual void	takeDamage(int	amount);
//	void	attack();

	virtual void	moveXY(int changeX, int changeY) = 0;

	bool	colision(AObject & obj);

};

#endif
