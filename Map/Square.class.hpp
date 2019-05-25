
#ifndef SQUARE_CLASS_H

# define SQUARE_CLASS_H

# include <string>
# include <iostream>
#include "AEntity.class.hpp";
class Square 
{
    public:
    Square( void );
	Square( Square const & src );

	virtual ~Square( void );

	Square const &		operator=( Square const & rhs );

    private:

    int         x;
    int         y;
    AEntity *   entity;



};

#endif