/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AEntity.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconti <mconti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 08:36:43 by mconti            #+#    #+#             */
/*   Updated: 2019/05/25 08:36:45 by mconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "AEntity.class.hpp"
#include "../Map/Map.class.hpp"

AEntity::AEntity( void ):
_x(0),_y(0), _oldX(), _oldY(), _speed(), _turn_before_move(), _direction(), _name("nobody"), _type( '_' )
{

}


AEntity::AEntity( std::string name, char type ):
_x(0), _y(0), _oldX(0), _oldY(0), _speed(), _turn_before_move(), _direction(), _name(name), _type(type)
{

}

AEntity::AEntity( std::string name, char type,int speed, int direction  ):
 _x(0), _y(0), _oldX(), _oldY(), _speed(speed), _turn_before_move(), _direction(direction), _name(name), _type(type)
{

}

AEntity::AEntity( char type ):
_x(0), _y(0), _oldX(), _oldY(), _speed(), _turn_before_move(), _direction(), _name(""), _type(type)
{

}

AEntity::AEntity( AEntity const & src )
{
	*this = src;
}

AEntity::~AEntity( void )
{

}

AEntity const &		AEntity::operator=( AEntity const & rhs )
{
	if (this != &rhs)
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
		this->_oldX = rhs._oldX;
		this->_oldY = rhs._oldY;
		this->_type = rhs._type;
	}
	return (*this);
}

void				AEntity::move( int dx, int dy )
{
	this->_oldX = this->_x;
	this->_oldY = this->_y;
	this->_x += dx;
	this->_y += dy;
	if(this->_x < 1)
		this->_x = 1;
	if(this->_y < 0)
		this->_y = 0;
	if(this->_x > WIDTH - 2)
		this->_x = WIDTH - 2;
	if(this->_y > HEIGHT - 1)
		this->_y = HEIGHT - 1;
	// If checkEntity true onHit() else tab[x][y] = &Aentity
}

void	AEntity::setX( int x )
{
	this->_x = x;
}

int		AEntity::getX( void ) const
{
	return this->_x;
}

int		AEntity::getOldX( void ) const
{
	return this->_oldX;
}

void	AEntity::setY( int y )
{
	this->_y = y;
}

int		AEntity::getY( void ) const
{
	return this->_y;
}

int		AEntity::getOldY( void ) const
{
	return this->_oldY;
}

std::string		AEntity::getName(void) const
{
	return this->_name;
}

void			AEntity::setName( std::string name)
{
	this->_name = name;
}


char	AEntity::getType(void) const
{
	return this->_type;
}

void			AEntity::setType(char type)
{
	this->_type = type;
}


void            	AEntity::move( void )
{
	if (this->_direction == LESS_Y)
		this->move(0, -1);
	else if (this->_direction == PLUS_Y)
		this->move(1, 0);
	else if (this->_direction == LESS_X)
		this->move(-1, 0);
	else if (this->_direction == PLUS_X)
		this->move(0, 1);
	else if (this->_direction == LESS_X_LESS_Y)
		this->move(-1, -1);
	else if (this->_direction == LESS_X_PLUS_Y)
		this->move(-1, 1);
	else if (this->_direction == PLUS_X_LESS_Y)
		this->move(1, -1);
	else if (this->_direction == PLUS_X_PLUS_Y)
		this->move(1, 1);
}


bool AEntity::onMove( void )
{
	if (--this->_turn_before_move <= 0 )
	{
		this->_turn_before_move = this->_speed;
		return true;
	}
	return false;
}

void				AEntity::setSpeed( int frequency )
{
	this->_speed = frequency;
	this->_turn_before_move = frequency;
}

void				AEntity::addSpeed( int frequency )
{
	this->_speed += frequency;
}

void            	AEntity::setDirection( int direction )
{
	this->_direction = direction;
}

int             	AEntity::getDirection( void ) const
{
	return this->_direction;
}
