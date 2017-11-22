/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 19:58:35 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/04 19:58:37 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_H
# define PLAYER_CLASS_H

#include "AObjects.class.hpp"

class Player : public AObject
{

public:
	Player();
	Player(char dsp, int x, int y);
	Player(Player const & src);
	virtual ~Player();
	
	using AObject::operator=;

	virtual void	moveXY(int changeX, int changeY);

	virtual void	takeDamage(int	amount);

};

#endif
