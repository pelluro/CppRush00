
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

    	virtual void		hit( const AEntity &s );
		virtual void        move( void );

		virtual Missile *	clone( void );

    protected:
    	int					_deal_damage;



};

#endif

