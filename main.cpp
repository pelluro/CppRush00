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

int		main( void )
{
	Ncurses e;
	env(&e);
	std::cout << "test Ncurses" << std::endl;
	return (0);

}
