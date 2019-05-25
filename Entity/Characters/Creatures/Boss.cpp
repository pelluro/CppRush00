#include "Boss.class.hpp"



Boss::Boss( void ): Creature(100, "boss", "Cthulu")
{
}

Boss::Boss( Boss & const src )
{
	*this = rhs;
}

virtual Boss::~Boss( void )
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

void					Boss::onEntityHit ( void )
{
	
}