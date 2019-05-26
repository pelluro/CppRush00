#include "Creature.hpp"
#include "../../../Constants.hpp"
#include <ncurses.h>

Creature::Creature( void ):
 Character('@', "creature", 1, NULL)
{
	this->_x = WIDTH / 2;
	this->_oldX = WIDTH / 2;
	this->_y = 0;
	this->_oldY = 0;
	this->_speed = 1;
	this->_direction = PLUS_Y;
}

Creature::Creature( char type, std::string name, int speed, int direction, int hp, Weapon * weapon ):
Character(type, name, hp, weapon)
{
	this->_x = WIDTH / 2;
	this->_oldX = WIDTH / 2;
	this->_y = 0;
	this->_oldY = 0;
	this->_speed = speed;
	this->_direction = direction;
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
	}
	return *this;
}

void					Creature::hit( AEntity const & entity )
{
	if (entity.getType() == 'X')
	{
		this->takeDamage(COLLISION_DAMAGE);
	}
	else if (entity.getType() == '|')
		this->takeDamage(entity.getDealDamage());
}

void    		Creature::move( void ){
	AEntity::move();
}
void    		Creature::move( int dx, int dy  ){
	AEntity::move(dx,dy);
}
bool			Creature::onMove( void ){
	return AEntity::onMove();
}


