
#ifndef BOSS_CLASS_H

# define BOSS_CLASS_H

# include <string>
# include <iostream>

#include "../../AEntity.class.hpp"
#include "../Character.class.hpp"

#include "Creature.hpp"
#include "../../../Weapons/Gun.hpp"

class Boss:public Creature
{
    public:
    	Boss( void );
    	Boss( Boss const & src );
    	virtual ~Boss( void );

    	Boss const &		operator=( Boss const & rhs );

		virtual bool    		move( void );
		virtual bool			onMove( void );
		virtual void			move( int dx, int dy );

        virtual Boss * 			clone( void );

    protected:

};

#endif

