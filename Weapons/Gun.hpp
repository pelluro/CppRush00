
#ifndef GUN_H

# define GUN_H

# include <string>
# include <iostream>

# include "Weapon.hpp"
//weapon that's give missile

class Gun : public Weapon
{
    public:
        Gun( void );
        virtual ~Gun( void );


};

#endif

