
#ifndef WEAPONUPGRADE_CLASS_H

# define WEAPONUPGRADE_CLASS_H

# include <string>
# include <iostream>

#include "../AEntity.class.hpp"
#include "Bonus.class.hpp"

class WeaponUpgrade:public Bonus
{
    public:

    virtual void	onEntityHit ( void );

    protected:

};

#endif