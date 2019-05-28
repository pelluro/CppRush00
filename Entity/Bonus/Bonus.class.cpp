#include "Bonus.class.hpp"


Bonus::Bonus( void ):
AEntity("Bonus", '*', 100000, 0)
{
	this->_deal_damage = 0;
	this->_is_destroy = false;
}

Bonus::Bonus( Bonus const & src )
{
	*this = src;
}

Bonus::~Bonus( void )
{

}

Bonus const &	Bonus::operator=( Bonus const & rhs )
{
	if (this != &rhs)
	{
		this->AEntity::operator=(rhs);
		this->_deal_damage = rhs.getDealDamage();
		this->_is_destroy = false;
	}
	return *this;
}

bool        Bonus::onAction( void )
{
	return false;
}

void        Bonus::fire( void )
{

}

bool		Bonus::toDelete( void )
{
	if (this->AEntity::toDelete())
		return true;
	return this->_is_destroy;
}

void	Bonus::hit( const AEntity &s )
{
	if (s.getName() == "Player")
		Game::getGame()->addLife();
	this->_is_destroy = true;
}

int		Bonus::getDealDamage( void ) const
{
	return 0;
}

bool	Bonus::getIsDestroy( void ) const
{
	return this->_is_destroy;
}

void	Bonus::setIsDestroy( bool b )
{
	this->_is_destroy = b;
}













WeaponUpgrade::WeaponUpgrade( void ):
Bonus()
{
	this->_deal_damage = 0;
	this->_is_destroy = false;
}

WeaponUpgrade::WeaponUpgrade( WeaponUpgrade const & src )
{
	*this = src;
}

WeaponUpgrade::~WeaponUpgrade( void )
{

}













void	WeaponUpgrade::hit( const AEntity &s )
{
	if (s.getName() == "Player")
		Game::getGame()->changeWeapon(new MasterRiffle);
	this->_is_destroy = true;
}
