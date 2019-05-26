
#ifndef BONUS_CLASS_H

# define BONUS_CLASS_H

# include <string>
# include <iostream>

#include "../AEntity.class.hpp"

class Bonus:public AEntity
{
    public:

    virtual void	onEntityHit ( void );

    protected:

	int			_action_frequency;		// if < 1 would be to do each turn
	int			_turn_before_action;	// initiayze at _action_frequency

};

#endif