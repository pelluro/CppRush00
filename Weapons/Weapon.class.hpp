
#ifndef WEAPON_CLASS_H

# define WEAPON_CLASS_H

# include <string>
# include <iostream>

# include "../Entity/Missiles/Missile.class.hpp"
//weapon that's give missile

class Missile;

class Weapon 
{
    public:
        Weapon( void );
        Weapon( int action_frequency );
        Weapon( Weapon const & src );
        virtual ~Weapon( void );

        Weapon const &          operator=( Weapon const & rhs );

        virtual Weapon *        clone( void );

        bool                    onAction( void );

        Missile *               fire( void );

        void                    setActionFrequency( int frequency );

        void                    reload( void );

        int                     getTurnBeforeAction( void ) const;

    protected:
        int     _action_frequency;
        int     _turn_before_action;
        Missile m;


};

#endif

