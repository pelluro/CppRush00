#include "Boss.hpp"


Boss::Boss( void ):
Creature('&', "Cthulu", 10000, PLUS_Y , 100, NULL)
{
	this->equipWeapon(new Gun);
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
		this->Creature::operator=(rhs);
	}
	return *this;
}

Boss *		 			Boss::clone( void )
{
	return new Boss(*this);
}

bool    		Boss::move( void ){
	return this->AEntity::move();
}
bool			Boss::onMove( void ){
	return this->AEntity::onMove();
}
void    		Boss::move( int dx, int dy  ){
	this->AEntity::move(dx,dy);
}


