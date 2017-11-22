# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skholodn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/04 14:31:01 by skholodn          #+#    #+#              #
#    Updated: 2017/11/04 14:31:41 by skholodn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

CC = clang++

CPPFLAGS = -Wall -Wextra -Werror

NCURCESFLAGS = -lncurses

SRC = main.cpp Window.class.cpp Player.class.cpp \
		Stars.class.cpp AObjects.class.cpp \
		Enemy.class.cpp Bullet.class.cpp \
		BulletEn.class.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $(NCURCESFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
