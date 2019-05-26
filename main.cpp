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


#include "Game.class.hpp"


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
	initscr();
	initColor();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);

	Game* g = new Game();
	g->start();
	delete g;

	endwin();
	return (0);
}
