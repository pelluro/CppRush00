#ifndef MAP_CLASS_H

# define MAP_CLASS_H

# include <string>
# include <iostream>
# include <ncurses.h>
# include "Square.class.hpp"
# include "../Entity/AEntity.class.hpp"
# include "../Constants.hpp"

class Map
{
public:
	Map( void );
	Map( Map const & src );

	virtual ~Map( void );

	Map const &		operator=( Map const & rhs );

	AEntity *		getEntity( int x, int y ) const;
	//void			setEntity( int y, int x, AEntity * entity );
	void			addEntity(AEntity* entity);
	void			updateEntity(AEntity* entity);
	void			removeEntity( int x, int y );

	void 			print(WINDOW * w);
	std::string		toString();

	Square* const &	getSquare( int x, int y ) const;

    private:

    Square*			_tab[999][999];
};

#endif

