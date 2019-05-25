
#ifndef GUN_H

# define GUN_H

# include <string>
# include <iostream>

# include "Weapon.class.hpp"
//weapon that's give missile
class Weapon;

class Gun : public Weapon
{
    public:
        Gun( void );
        virtual ~Gun( void );


};

#endif

