
#ifndef CREATURE_CLASS_H

# define CREATURE_CLASS_H

# include <string>
# include <iostream>

#include "../../AEntity.class.hpp"
#include "../Character.class.hpp"

class Creature: public Character
{
    public:
        Creature( void );
        Creature( std::string type, std::string name, int speed, int hp, Weapon * weapon );
        Creature( Creature const & src );
        virtual ~Creature( void );



        Creature const &        operator=( Creature const & rhs );

        virtual void            hit( AEntity const & entity );



    protected:

};

#endif

