#include "Basic.hpp"



Basic::Basic( void ): Creature('^', "monster", 1, PLUS_Y ,1 , NULL)
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

void    		Basic::move( void ){
	AEntity::move();
}
void    		Basic::move( int dx, int dy  ){
	AEntity::move(dx,dy);
}
bool			Basic::onMove( void ){
	return AEntity::onMove();
}
