#include "Character.class.hpp"
#include "../../Game.class.hpp"


Character::Character( void ): AEntity()
{
	this->setHP(1);
}

Character::Character( char type, std::string name, int hp, Weapon * weapon ):
AEntity(name, type)
{
	this->setHP(hp);
	this->equipWeapon(weapon);
}
Character::Character( Character const & src )
{
	*this = src;
}

Character::~Character( void )
{
	if (this->_weapon)
		delete this->_weapon;
}


Character const &		Character::operator=( Character const & rhs )
{
	if (this != &rhs)
	{
		this->AEntity::operator=( rhs );
		this->setHP(rhs.getHP());
		this->equipWeapon(rhs.getWeapon()->clone());
	}
	return *this;
}

void          			Character::fire( void )
{
	Game * game = Game::getGame();
	Missile * missile = this->_weapon->fire();
	missile->setDirection(this->getDirection());
	missile->setY(this->getY());
	missile->setX(this->getX());
	missile->forceMove();
	missile->setIsDestroy(false);
	game->addEntity(missile);
}

bool 			        Character::onAction( void )
{
	if (this->_weapon)
		return this->_weapon->onAction();
	return false;
}

bool					Character::toDelete( void )
{
	if (this->AEntity::toDelete())
		return true;
	if (this->getHP() <= 0)
		return true;
	return false;
}

int						Character::getHP( void ) const
{
	return this->_hp;
}

void					Character::setHP( int hp )
{
	this->_hp = hp;
}

void					Character::takeDamage( int damage )
{
	if ( damage < 0 )
		damage = 0;
	this->setHP(this->getHP() - damage);
}

int						Character::getDealDamage( void ) const
{
	return (COLLISION_DAMAGE);
}

void					Character::equipWeapon( Weapon* weapon )
{
	this->unequipWeapon();
	this->_weapon = weapon;
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
