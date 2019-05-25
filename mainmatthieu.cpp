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

int		main( void )
{
	Map	map;
	int x, y = -1;

	while (++y < MAX_Y && (x = -1))
		while(++x < MAX_X)
			map.getEntity(y, x);

	return (0);
}
