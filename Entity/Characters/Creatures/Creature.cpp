#include "Creature.hpp"



Creature::Creature( void ): Character("creature", 1)
{

}

Creature::Creature( std::string type, int hp ): Character(type, hp)
{

}

Creature::Creature( std::string type, std::string name, int hp ): Character(type, name, hp)
{

}

Creature::Creature( Creature const & src )
{
	*this = src;
}

Creature::~Creature( void )
{

}


Creature const &		Creature::operator=( Creature const & rhs )
{
	if (this != &rhs)
	{
		Character::operator=(rhs);
		this->_action_frequency = rhs._action_frequency;
		this->_turn_before_action = rhs._turn_before_action;
		return *this;
	}
}

void					Creature::onEntityHit ( const AEntity & entity )
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

