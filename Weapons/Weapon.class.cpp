

#include "Weapon.class.hpp"

Weapon::Weapon( void )
{
	this->setActionFrequency(1);
}
Weapon::Weapon( int action_frequency )
{
	this->setActionFrequency(action_frequency);
}

Weapon::~Weapon( void )
{

}

Weapon const &          operator=( Weapon const & rhs )
{
	if (this != &rhs)
	{
		this->_action_frequency = rhs._action_frequency;
		this->_turn_before_action = rhs._turn_before_action;
		this->m = rhs.m;
	}
}

virtual Weapon *        clone( void )
{
	return new Weapon(*this);
}


void	Weapon::setActionFrequency( int frequency )
{
	this->_action_frequency = frequency;
	this->_turn_before_action = frequency;
}

bool    Weapon::onAction( void )
{
	if (--this->_turn_before_action <= 0 )
	{
		this->_turn_before_action = this->_action_frequency;
		return true;
	}
	return false;
}