#include "Basic.hpp"



Basic::Basic( void ): Creature('v', "monster", 400, PLUS_X , 1, NULL)
{
	this->equipWeapon(new Gun);
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
		this->Creature::operator=(rhs);
	}
	return *this;
}

Basic *		 			Basic::clone( void )
{
	return new Basic(*this);
}

bool    		Basic::move( void ){
	return this->AEntity::move();
}
void    		Basic::move( int dx, int dy  ){
	this->AEntity::move(dx,dy);
}
bool			Basic::onMove( void ){
	return this->AEntity::onMove();
}

Tier2::Tier2( void ): Creature('#', "monster2", 1000, PLUS_X , 5, NULL)
{
	this->equipWeapon(new Gun);
}

Tier2::Tier2( Tier2 const & src )
{
	*this = src;
}

Tier2::~Tier2( void )
{

}


Tier2 const &		Tier2::operator=( Tier2 const & rhs )
{
	if (this != &rhs)
	{
		this->Creature::operator=(rhs);
	}
	return *this;
}

Tier2 *		 			Tier2::clone( void )
{
	return new Tier2(*this);
}

bool    		Tier2::move( void ){
	return this->AEntity::move();
}
void    		Tier2::move( int dx, int dy  ){
	this->AEntity::move(dx,dy);
}
bool			Tier2::onMove( void ){
	return this->AEntity::onMove();
}
