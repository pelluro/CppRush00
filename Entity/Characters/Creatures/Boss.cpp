#include "Boss.hpp"



Boss::Boss( void ): Creature("boss", "Cthulu", 100)
{
}

Boss::Boss( Boss const & src )
{
	*this = src;
}

Boss::~Boss( void )
{

}


Boss const &		Boss::operator=( Boss const & rhs )
{
	if (this != &rhs)
	{
		Creature::operator=(rhs);
	}
	return *this;
}

void					Boss::hit( AEntity const & entity )
{
	(void)entity;
}

Boss *		 			Boss::clone( void )
{
	return new Boss(*this);
}


