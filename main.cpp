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

#define WIN_MAX_X 120
#define WIN_MAX_Y 400

int		main( void )
{
	initscr();
	noecho();
	int i = 0;
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_GREEN);

	WINDOW *	window = newwin(WIN_MAX_X, WIN_MAX_Y, 0, 0);
	attron(COLOR_PAIR(1));
	wprintw(window, "      ");
	attroff(COLOR_PAIR(1));
	refresh();
	while(i < 2000000000)
		i++;
	return (0);
}
