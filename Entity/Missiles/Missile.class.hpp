
#ifndef MISSILE_CLASS_H

# define MISSILE_CLASS_H

# include <string>
# include <iostream>
# include "Weapon.class.hpp"
//weapon that's give missile

class Missile : public Weapon 
{
    public:
    Missile( void );
	Missile( Missile const & src );

	virtual ~Missile( void );

	Missile const &		operator=( Missile const & rhs );
<<<<<<< HEAD
=======
    virtual void	onEntityHit ( void );
>>>>>>> minh


    protected:




};

#endif