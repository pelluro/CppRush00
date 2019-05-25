#include "Character.class.hpp"



Character::Character( void ): AEntity()
{
	this->setHP(1);
}

Character::Character( int hp ):AEntity()
{
	this->setHP(hp);
}
Character::Character( std::string type, int hp ):AEntity(type)
{
	this->setHP(hp);
}

Character::Character( std::string name, std::string type, int hp ):AEntity(name, type)
{
	this->setHP(hp);
}

Character::Character( Character & const src ): AEntity(src)
{
	*this = rhs;
}

virtual Character::~Character( void )
{

}


Character const &		Character::operator=( Character const & rhs )
{
	if (this != &rhs)
	{
		AEntity::operator=( rhs );
		this->setHP(rhs.getHP());
		this->equipWeapon(rhs.getWeapon().clone());
	}
	return *this;
}
int						Character::getHP( void ) const
{
	return this->_hp;
}

void					Character::setHP( int hp )
{
	this->_hp = hp;
}

void					Character::equipWeapon( Weapon* weapon )
{
	this->unequipWeapon();
	return this->_weapon = weapon;
}

void					Character::unequipWeapon( void )
{
	if (this->getWeapon())
		delete this->getWeapon();
}

Weapon*					Character::getWeapon( void ) const
{
	return this->_weapon;
}

void					Character::setMoveFrequency( int frequency )
{
	this->_move_frequency = frequency;
	this->_turn_before_move = frequency;
}

void					Character::addToMoveFrequency( int frequency )
{
	this->_move_frequency += frequency;
}

