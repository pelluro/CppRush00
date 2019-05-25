
#ifndef HEALTHPACK_CLASS_H

# define HEALTHPACK_CLASS_H

# include <string>
# include <iostream>

#include "../AEntity.class.hpp"
#include "Bonus.class.hpp"

class HealthPack:public Bonus
{
    public:

    virtual void	onEntityHit ( void );

    protected:

};

#endif