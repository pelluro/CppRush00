
#include "Gun.hpp"

Gun::Gun( void ):Weapon(5000)
{
	this->m.setSpeed(50);
}

Gun::~Gun( void )
{

}

Riffle::Riffle( void ):Weapon(800)
{
	this->m.setSpeed(50);
}

Riffle::~Riffle( void )
{

}
