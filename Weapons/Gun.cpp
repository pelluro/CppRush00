
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

MasterRiffle::MasterRiffle( void ):Weapon(400)
{
	this->m.setSpeed(50);
}

MasterRiffle::~MasterRiffle( void )
{

}
