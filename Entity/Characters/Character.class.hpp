
#ifndef CHARACTER_CLASS_H

# define CHARACTER_CLASS_H

# include <string>
# include <iostream>

#include "../AEntity.class.hpp"
#include "../Weapons/Weapon.class.hpp"

class Character: public AEntity
{
    public:
    Character( void );
    Character( int hp );
    Character( std::string type, int hp );
    Character( Character const & src );
    virtual ~Character( void );

    Character const &     operator=( Character const & rhs );


    int     getHP( void ) const;
    void    setHP( int hp );

    void    equipWeapon( Weapon* weapon );
    void    unequipWeapon( void );
    Weapon* getWeapon( void ) const;

    virtual void	onEntityHit ( void ) = 0;

    virtual bool    onAction( void ) = 0;

    void            setMoveFrequency( int frequency );
    void            addToMoveFrequency( int frequency );

    protected:
    //health point
    int _hp;
    Weapon* weapon;

    int			_move_frequency;		// if < 1 would be to do each turn
	int			_turn_before_move;		// initiayze at _action_frequency



};

#endif