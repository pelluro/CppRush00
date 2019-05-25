
#ifndef CHARACTER_CLASS_H

# define CHARACTER_CLASS_H

# include <string>
# include <iostream>

#include "../AEntity.class.hpp"
#include "../../Weapons/Weapon.class.hpp"

# define COLLISION_DAMAGE 1

class Character: public AEntity
{
    public:
        Character( void );
        Character( int hp );
        Character( std::string type, int hp );
        Character( std::string name, std::string type, int hp );
        Character( Character const & src );
        virtual ~Character( void );

        Character const &     operator=( Character const & rhs );


        int                   getHP( void ) const;
        void                  setHP( int hp );
        void                  takeDamage( int damage );

        void                  equipWeapon( Weapon* weapon );
        void                  unequipWeapon( void );
        Weapon*               getWeapon( void ) const;

    protected:
    //health point
    int         _hp;
    Weapon*     _weapon;





};

#endif

