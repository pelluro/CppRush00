
#ifndef MAP_CLASS_H

# define MAP_CLASS_H

# include <string>
# include <iostream>
# include "Square.class.hpp"
# include "../Entity/AEntity.class.hpp"

# define MAX_X	200
# define MAP_Y	400

class Map 
{
    public:
	Map( void );
	Map( Map const & src );

	virtual ~Map( void );

	Map const &		operator=( Map const & rhs );

	AEntity *		getEntity( int y, int x );
	Square const &	getSquare( int y, int x );


    private:

    Square			_tab[MAP_Y][MAX_X];

};

#endif
