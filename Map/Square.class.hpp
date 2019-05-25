
#ifndef SQUARE_CLASS_H

# define SQUARE_CLASS_H

# include <string>
# include <iostream>
# include "../Entity/AEntity.class.hpp"

class Square 
{
    public:
    Square( void );
	Square( Square const & src );

	virtual ~Square( void );

	Square const &		operator=( Square const & rhs );

	AEntity *	getEntity( void );

    private:

    AEntity *   _entity;



};

#endif
