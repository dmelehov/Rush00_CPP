/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skholodn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 16:10:10 by skholodn          #+#    #+#             */
/*   Updated: 2017/11/04 16:10:12 by skholodn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Player.class.hpp"
//#include "Window.class.hpp"
#include "Stars.class.hpp"
#include "Enemy.class.hpp"
#include "Bullet.class.hpp"
#include "BulletEn.class.hpp"

Window::Window()
{
    this->_wnd = initscr();
    cbreak();
    noecho();
    clear();
    refresh();

    // enable function keys
    keypad(this->_wnd, true);

    // disable input blocking
    nodelay(this->_wnd, true);

    // hide cursor
    curs_set(0);

    if (!has_colors()) {
        endwin();
        std::cout << "ERROR: Terminal does not support color." << std::endl;
        exit(1);
    }

    // enable color modification
    start_color();


    // get windows size
    getmaxyx(_wnd, maxY, maxX);

  	start = clock();
}

Window::Window(Window const & src)
{
	*this = src;
}

Window::~Window(){
    endwin();
    std::cout << "<< GAME OVER >>" << std::endl;
}

Window & Window::operator=(Window const & rhs){
	if (this != &rhs)
		*this = rhs;
	return *this;
}


void	Window::runCircle(){
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    unsigned long score = 0;
	int a = 0;
    int seconds = 0;
    float secondsPassed = 0.0;
    Player player = Player('A', 10, 5);
	StarField	starField(*this);
	EnemySquard	enemySq(*this);
	Bullets bullet = Bullets();
    BulletsEn bulleten = BulletsEn();
    int in_char;
    int  bullets_time = 0;
    bool exit_requested = false;

//	starField.createField(*this);
    reload_bullets = clock();
	reload_enemies = clock();
    while(1) {
        in_char = wgetch(this->_wnd);
        mvaddch(player.getPosY(), player.getPosX(), ' ');
    	starField.update(*this, enemySq);
		if ((float)((float)(clock() - reload_bullets ) / CLOCKS_PER_SEC * 10000) > 45)
    	{
    		bullet.update();
    		reload_bullets = clock();
            bulleten.update();
    	}
    	if ((float)((float)(clock() - reload_enemies ) / CLOCKS_PER_SEC * 10000) > 900)
    	{
    		enemySq.update(*this);
    		reload_enemies = clock();
            bullets_time++;
    	}
    	for (int i = 0; i < ENEMY; i++){
    		if (player.colision(enemySq.enemySquard[i])){
    			player.takeDamage(enemySq.enemySquard[i].getDamage());
    			enemySq.enemySquard[i].takeDamage(30);
    		}
			if (bullet.colision(enemySq.enemySquard[i])){
                if (++a && a == 2 && !(a = 0)){
                    score += 5;
                }
    			enemySq.enemySquard[i].takeDamage(15);
    		}
            if (bulleten.colision(player)){
                player.takeDamage(15);
            }
            if (enemySq.enemySquard[i].getDispChar() == 'T' && bullets_time % 10 == 0){
                bulleten.createBulletEn(enemySq.enemySquard[i].getPosX(), enemySq.enemySquard[i].getPosY() + 1);
            }
    	}
        mvprintw(4, 103, "%d", player.getHP());
    	mvprintw(4, 97, "LIFE");
        mvprintw(6, 103, "%d", score);
        mvprintw(6, 97, "SCORE");
        secondsPassed = (int)(clock() - start) / CLOCKS_PER_SEC;
        if ((int)secondsPassed > seconds)
            seconds++;
        mvprintw(8, 107, "%d", seconds);
        mvprintw(8, 97, "GAME TIME");
        switch(in_char) {
            case 'q':
                exit_requested = true;
                break;
            case KEY_UP:
            case 'w':
                player.moveXY(0, -1);
                break;
            case KEY_RESIZE:
                clear();
    			refresh();
    			getmaxyx(_wnd, maxY, maxX);
                break;
            case ' ':
            	bullet.createBullet(player.getPosX(), player.getPosY());
            	break;
            case KEY_DOWN:
            case 's':
                player.moveXY(0, 1);
                break;
            case KEY_LEFT:
            case 'a':
                player.moveXY(-1, 0);
                break;
            case KEY_RIGHT:
            case 'd':
                player.moveXY(1, 0);
                break;
            default:
                break;
        }
        mvaddch(player.getPosY(), player.getPosX(), player.getDispChar() + COLOR_PAIR(1));

        if(exit_requested)
        	break;

        usleep(10000); // 10 ms

        refresh();
    }
}