
#ifndef PLAYER_CLASS_H

# define PLAYER_CLASS_H

# include <string>
# include <iostream>

#include "../AEntity.class.hpp"
#include "Character.class.hpp"

class Player:public Character
{
    public:
    	Player( void );
    	Player( Player const & src );
    	virtual ~Player( void );

    	Player const &		operator=( Player const & rhs );

        virtual void            hit( AEntity const & entity );
		virtual void    		move( void );
		virtual bool			onMove( void );
		void        move( int dx, int dy);

    protected:

};

#endif
