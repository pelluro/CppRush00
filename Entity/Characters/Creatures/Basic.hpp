
#ifndef BASIC_CLASS_H

# define BASIC_CLASS_H

# include <string>
# include <iostream>

#include "../../AEntity.class.hpp"
#include "../Character.class.hpp"
#include "Creature.hpp"
#include "../../../Weapons/Gun.hpp"

class Basic:public Creature
{
    public:
    	Basic( void );
    	Basic( Basic const & src );
    	virtual ~Basic( void );

    	Basic const &		operator=( Basic const & rhs );
		virtual void			move( int dx, int dy );

        virtual Basic * 			clone( void );
		virtual bool    		move( void );
		virtual bool			onMove( void );

    protected:

};

class Tier2:public Creature
{
    public:
        Tier2( void );
        Tier2( Tier2 const & src );
        virtual ~Tier2( void );

        Tier2 const &       operator=( Tier2 const & rhs );
        virtual void            move( int dx, int dy );

        virtual Tier2 *             clone( void );
        virtual bool            move( void );
        virtual bool            onMove( void );

    protected:

};

#endif
