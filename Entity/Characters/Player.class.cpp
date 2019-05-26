

# include <string>
# include <iostream>
#include <ncurses.h>
#define WIDTH COLS
#define HEIGHT (LINES - 9)

#include "../AEntity.class.hpp"
#include "Player.class.hpp"

#include "../../Weapons/Gun.hpp"

Player::Player( void ) : Character(){
	this->_x = WIDTH / 2;
	this->_y = HEIGHT - 1;
	this->_oldX = this->_x;
	this->_oldY = this->_y;
	this->_type = 'X';
	this->_name = "Player";
	this->_direction = LESS_Y;
	this->equipWeapon(new Gun);
}
Player::Player( Player const & src ) : Character(src) {
	this->_x = src._x;
	this->_y = src._y;
	this->_type = src._type;
	this->_name = src._name;
}

Player::~Player( void ){

}

Player const &Player::operator=( Player const & rhs ){
	this->_x = rhs._x;
	this->_y = rhs._y;
	this->_type = rhs._type;
	this->_name = rhs._name;
	return *this;
}

void	Player::hit( AEntity const & entity ){
	if (entity.getDealDamage())
		this->setHP(this->getHP() - entity.getDealDamage());
}

void	Player::move( void ){

}

void Player::move(int x, int y)
{
	this->AEntity::move(x, y);
}

bool			Player::onMove( void )
{
	return  this->AEntity::onMove();
}
