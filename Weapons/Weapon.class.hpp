
#ifndef WEAPON_CLASS_H

# define WEAPON_CLASS_H

# include <string>
# include <iostream>

# include "../Entity/Missiles/Missile.class.hpp"
//weapon that's give missile

class Weapon 
{
    public:
        Weapon( void );
        Weapon( std::string type, int x, int y );
        Weapon( Weapon const & src );
        virtual ~Weapon( void );

        Weapon const &          operator=( Weapon const & rhs );

        virtual Weapon *        clone( void );

        virtual bool            onAction( void );

        void                    setActionFrequency( int frequency );
        void                    addToActionFrequency( int frequency );


        // Copy de l'instance de missile enregistre dans weapon pour envoyer sur la carte
        void        fire( int x, int y );

    protected:
        int     _action_frequency;
        int     _turn_before_action;
        Missile m;


};

#endif

