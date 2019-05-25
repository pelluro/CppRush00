/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconti <mconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:19:33 by mconti            #+#    #+#             */
/*   Updated: 2019/05/25 10:19:34 by mconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Entity/AEntity.class.hpp"
# include <ncurses.h>
# include "Map/Map.class.hpp"
#include "Ncurses.hpp"
#include <iostream>
#define WIDTH COLS
#define HEIGHT (LINES - 9)


void	initColor(void)
{
	start_color();
	init_color(COLOR_BLUE, 300, 300, 300);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
}

int		main( void )
{
<<<<<<< HEAD:mainmatthieu.cpp
	Map	map;
	int x, y = -1;

	while (++y < MAX_Y && (x = -1))
		while(++x < MAX_X)
			map.getEntity(y, x);
=======
	initscr();
	initColor();
	WINDOW *winGame, *winInfo;

	winGame = subwin(stdscr, HEIGHT, WIDTH, 0, 0);
	winInfo = subwin(stdscr, 8, WIDTH / 3, HEIGHT, 0);

	noecho();
	timeout(1);
	curs_set(FALSE);
	keypad(stdscr, TRUE);
	getch();

	std::cout << "test Ncurses" << std::endl;

	delwin(winGame);
	delwin(winInfo);
	endwin();
>>>>>>> origin/start-minh:main.cpp

	return (0);

}
