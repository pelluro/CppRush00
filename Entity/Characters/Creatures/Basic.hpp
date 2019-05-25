
#ifndef BASIC_CLASS_H

# define BASIC_CLASS_H

# include <string>
# include <iostream>

#include "../../AEntity.class.hpp"
#include "../Character.class.hpp"
#include "../../Weapons/Weapon.class.hpp"
#include "Creature.hpp"

class Basic:public Creature
{
    public:
    	Basic( void );
    	Basic( Basic const & src );
    	virtual ~Basic( void );

    	Basic const &		operator=( Basic const & rhs );

        virtual Basic * 			clone( void );

    protected:

};

#endif