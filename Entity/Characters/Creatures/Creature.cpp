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
	}
	return *this;
}

void					Creature::hit( AEntity const & entity )
{
	if (entity.getType() == "player")
	{
		this->takeDamage(COLLISION_DAMAGE);
	}
}
