#include "Basic.hpp"



Basic::Basic( void ): Creature('^', "monster", 1000, PLUS_X , 1, NULL)
{
//	this->equipWeapon(new Gun);
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
	this->AEntity::move();
}
void    		Basic::move( int dx, int dy  ){
	this->AEntity::move(dx,dy);
}
bool			Basic::onMove( void ){
	return this->AEntity::onMove();
}
