
#ifndef BONU_CLASS_H

# define BONUS_CLASS_H

# include <string>
# include <iostream>

#include "../AEntity.class.hpp"

class Bonus:public AEntity
{
    public:

    virtual void	onEntityHit ( void );

    protected:

};

#endif