
#ifndef CREATURE_CLASS_H

# define CREATURE_CLASS_H

# include <string>
# include <iostream>

#include "../../AEntity.class.hpp"
#include "../Character.class.hpp"

class Creature: public Character
{
    public:
    	Creature( void );
    	Creature( std::string type, int hp );
    	Creature( std::string type, std::string name, int hp );
		Creature( Creature const & src );
    	virtual ~Creature( void );

    	Creature const &		operator=( Creature const & rhs );

		virtual void	        onEntityHit ( const AEntity & entity );

        virtual bool            onAction( void ) = 0;

        void                    setActionFrequency( int frequency );
        void                    addToActionFrequency( int frequency );

    protected:
        int             _action_frequency;
        int             _turn_before_action;
};

#endif

