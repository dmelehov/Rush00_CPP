/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:10:18 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/04 16:10:19 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_CLASS_H
# define WINDOW_CLASS_H

#include "Player.class.hpp"

class Window
{

WINDOW* _wnd;
	
public:
	int		maxX;
	int		maxY;
	clock_t	start;
	clock_t	reload_enemies;
	clock_t	reload_bullets;
	
	Window();
	Window(Window const & src);
	~Window();
	
	Window & operator=(Window const & rhs);

	void	runCircle();

};

#endif

