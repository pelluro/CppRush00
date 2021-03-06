

#include "Weapon.class.hpp"

Weapon::Weapon( void )
{
	this->setActionFrequency(1);
}
Weapon::Weapon( int action_frequency )
{
	this->setActionFrequency(action_frequency);
}

Weapon::Weapon( Weapon const & src )
{
	*this = src;
}

Weapon::~Weapon( void )
{

}

Weapon const &          Weapon::operator=( Weapon const & rhs )
{
	if (this != &rhs)
	{
		this->_action_frequency = rhs._action_frequency;
		this->_turn_before_action = rhs._turn_before_action;
		this->m = rhs.m;
	}
	return *this;
}

Weapon *        		Weapon::clone( void )
{
	return new Weapon(*this);
}


void	Weapon::setActionFrequency( int frequency )
{
	this->_action_frequency = frequency;
	this->_turn_before_action = frequency;
}

int		Weapon::getTurnBeforeAction( void ) const
{
	return this->_turn_before_action;
}

void	Weapon::reload( void )
{
	--this->_turn_before_action;
}

bool    Weapon::onAction( void )
{
	if (--this->_turn_before_action <= 0 )
	{
		return true;
	}
	return false;
}

Missile *	Weapon::fire( void )
{
	this->_turn_before_action = this->_action_frequency;
	return this->m.clone();
}
