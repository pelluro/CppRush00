
#ifndef MISSILE_CLASS_H

# define MISSILE_CLASS_H

# include <string>
# include <iostream>
# include "../AEntity.class.hpp"

class Missile : public AEntity
{
    public:
    Missile( void );
	Missile( Missile const & src );

	virtual ~Missile( void );

	Missile const &		operator=( Missile const & rhs );

    virtual void	onEntityHit ( const AEntity &s );



    protected:




};

#endif

