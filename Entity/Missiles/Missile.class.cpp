#include "Missile.class.hpp"


Missile::Missile( void ):
AEntity("missile", '|')
{
	this->_deal_damage = 1;
	this->_is_destroy = false;
}

Missile::Missile( int damage, int direction, int speed ):
AEntity("missile", '|', speed, direction)
{
	this->_deal_damage = damage;
	this->_is_destroy = false;
}

Missile::Missile( Missile const & src )
{
	*this = src;
}

Missile::~Missile( void )
{

}

Missile const &	Missile::operator=( Missile const & rhs )
{
	if (this != &rhs)
	{
		AEntity::operator=(rhs);
		this->_deal_damage = rhs.getDealDamage();
	}
	return *this;
}

void	Missile::hit( const AEntity &s )
{
	(void)s;
	this->_is_destroy = true;
}

int		Missile::getDealDamage( void ) const
{
	return this->_deal_damage;
}

Missile *	Missile::clone( void )
{
	return new Missile(*this);
}

Missile *	Missile::clone( int direction )
{
	Missile * missile = new Missile(*this);
	missile->setDirection(direction);
	return missile;
}
