#include "Missile.hpp"


Missile::Missile( void ):
AEntity("missile", "missile", 1, PLUS_Y)
{
	this->_deal_damage = 1;
}

Missile::Missile( int damage, int direction, int speed ):_deal_damage(damage)
AEntity("missile", "missile", speed, direction)
{
	this->_deal_damage = damage;
}

Missile::Missile( Missile const & src );
{
	*this = src;
}

Missile::~Missile( void )
{

}

const &		Missile::operator=( Missile const & rhs )
{
	if (this != &rhs)
	{
		AEntity::operator=(rhs);
		this->_deal_damage;
	}
	return *this
}



int		Missile::getDealDamage( void ) const
{
	return this->_deal_damage;
}

Missile *	Missile::clone( void )
{
	return new Missile(this);
}

Missile *	Missile::clone( int direction )
{
	Missile * missile = new Missile(this);
	missile->setDirection(direction);
}