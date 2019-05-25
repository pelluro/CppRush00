
#ifndef BOSS_CLASS_H

# define BOSS_CLASS_H

# include <string>
# include <iostream>

#include "../../AEntity.class.hpp"
#include "../Character.class.hpp"

#include "Creature.hpp"


class Boss:public Creature
{
    public:
    	Boss( void );
    	Boss( Boss const & src );
    	virtual ~Boss( void );

    	Boss const &		operator=( Boss const & rhs );

        virtual void            move( void ) {}

        virtual Boss * 			clone( void );

    protected:

};

#endif

