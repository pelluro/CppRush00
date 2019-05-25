
#ifndef MAP_CLASS_H

# define MAP_CLASS_H

# include <string>
# include <iostream>
#include "Square.class.hpp"

class Map 
{
    public:
    Map( void );
	Map( Map const & src );

	virtual ~Map( void );

	Map const &		operator=( Map const & rhs );



    private:

    Square * tab[];

};

#endif