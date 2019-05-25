
#ifndef CREATURE_CLASS_H

# define CREATURE_CLASS_H

# include <string>
# include <iostream>

#include "../../AEntity.class.hpp"
#include "../Character.class.hpp"
#include "../../Weapons/Weapon.class.hpp"

class Creature:public Character
{
    public:

    virtual void	onEntityHit ( void );

    protected:

};

#endif