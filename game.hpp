/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 20:16:19 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/04 20:42:56 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include <unistd.h>
#include <ncurses.h>
#include <ctime>
#include <cstdint>
#include <string>
#include <iostream>

#define STARS 50


typedef struct	s_pos {
	int	x;
	int	y;
}				t_pos;

// simple integer rectangle type
typedef struct  s_rect {
    t_pos offset;
    t_pos bounds;

    int top() { return offset.y; }
    int bot() { return offset.y + bounds.y; }
    int left() { return offset.x; }
    int right() { return offset.x + bounds.x; }

    int width() { return bounds.x; }
    int height() { return bounds.y; }

    bool contains(t_pos a) { return (a.x >= offset.x && a.x < right()) && 
                                    (a.y >= offset.y && a.y < bot()); }
} 				t_rect;


#endif
