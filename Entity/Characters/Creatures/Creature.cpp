#include "Creature.class.hpp"



Creature::Creature( void ): Character(1, "creature")
{

}

Creature::Creature( std::string type, int hp ): Character(hp, type)
{

}

Creature::Creature( std::string type std::string name, int hp ): Character(hp, type, name)
{

}

Creature::Creature( Creature & const src )
{
	*this = rhs;
}

virtual Creature::~Creature( void )
{

}


Creature const &		Creature::operator=( Creature const & rhs )
{
	Character::operator=(rhs);
	return *this;
}

void					Creature::onEntityHit ( void )
{

}


bool	Creature::onAction( void )
{
	if (--this->_turn_before_action <= 0 )
	{
		this->_turn_before_action = this->_action_frequency;
		return true;
	}
	return false;

}


void	Creature::setActionFrequency( int frequency )
{
	this->_action_frequency = frequency;
	this->_turn_before_action = frequency;
}

void	Creature::addToActionFrequency( int frequency )
{
	this->_action_frequency += frequency;
}

