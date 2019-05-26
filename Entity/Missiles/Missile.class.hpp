
#ifndef MISSILE_CLASS_H

# define MISSILE_CLASS_H

# include <string>
# include <iostream>
# include "../AEntity.class.hpp"

class Missile : public AEntity
{
    public:
    	Missile( void );
        Missile( int damage, int speed );
    	Missile( int damage, int direction, int speed );
		Missile( Missile const & src );

		virtual ~Missile( void );

		Missile const &		operator=( Missile const & rhs );

    	virtual void		hit( const AEntity &s );

		virtual Missile *	clone( void );
		virtual Missile *	clone( int direction );

        virtual bool        onAction( void );
        virtual void        fire( void );

        virtual bool        toDelete( void );

		virtual int			getDealDamage( void ) const;

    protected:
    	int					_deal_damage;
    	bool				_is_destroy;



};

#endif

