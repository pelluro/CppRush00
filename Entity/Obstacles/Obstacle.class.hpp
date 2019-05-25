
#ifndef OBSTACLE_CLASS_H

# define OBSTACLE_CLASS_H

# include <string>
# include <iostream>
# include "../AEntity.class.hpp"
//weapon that's give missile

class Obstacle : public AEntity 
{
    public:
    Obstacle( void );
	Obstacle( Obstacle const & src );

	virtual ~Obstacle( void );

	Obstacle const &		operator=( Obstacle const & rhs );

    virtual void	onEntityHit ( void );


    protected:




};

#endif