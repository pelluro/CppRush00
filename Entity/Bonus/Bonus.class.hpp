
#ifndef BONUS_CLASS_H

# define BONUS_CLASS_H

# include <string>
# include <iostream>

#include "../AEntity.class.hpp"
#include "../Characters/Player.class.hpp"
#include "../../Game.class.hpp"

class Bonus:public AEntity
{
	public:
    	Bonus( void );
		Bonus( Bonus const & src );

		virtual ~Bonus( void );

		Bonus const &		operator=( Bonus const & rhs );

    	virtual void		hit( const AEntity &s );

        virtual bool        onAction( void );
        virtual void        fire( void );

        virtual bool        toDelete( void );

		virtual int			getDealDamage( void ) const;

        bool         getIsDestroy( void ) const;
        void         setIsDestroy( bool b );

    protected:
    	int					_deal_damage;
    	bool				_is_destroy;
};


class WeaponUpgrade:public Bonus
{
    public:
    	WeaponUpgrade( void );
		WeaponUpgrade( WeaponUpgrade const & src );

		virtual ~WeaponUpgrade( void );

    	virtual void		hit( const AEntity &s );

    protected:

};



#endif

