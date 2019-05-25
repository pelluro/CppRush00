
#ifndef BOSS_CLASS_H

# define BOSS_CLASS_H

# include <string>
# include <iostream>

#include "../../AEntity.class.hpp"
#include "../Character.class.hpp"
#include "../../Weapons/Weapon.class.hpp"
#include "Creature.hpp"

class Boss:public Creature
{
    public:

    virtual void	onEntityHit ( void );

    protected:

};

#endif