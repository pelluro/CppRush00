#include "Basic.hpp"



Basic::Basic( void ): Creature("Basic", "monster", 1, 1, new )
{
	
}

Basic::Basic( Basic const & src )
{
	*this = src;
}

Basic::~Basic( void )
{

}


Basic const &		Basic::operator=( Basic const & rhs )
{
	if (this != &rhs)
	{
		Creature::operator=(rhs);
	}
	return *this;
}

Basic *		 			Basic::clone( void )
{
	return new Basic(*this);
}


