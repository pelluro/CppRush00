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

AEntity::AEntity( void ):
_x(0),_y(0), _name("nobody"), _type( NULL )
{

}

AEntity::AEntity( std::string name, std::string type, int x, int y ):
_x(x),_y(y), _name( name ), _type( type )
{

}

AEntity::AEntity( std::string name, std::string type ):
_x(0), _y(0), _name(name), _type(type)
{

}

AEntity::AEntity( std::string type ):
_x(0), _y(0), _name(type), _type(type)
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

		this->_type = rhs._type;
	}
	return (*this);
}



void				AEntity::move( int x, int y )
{
	this->_x += x;
	this->_y += y;
	// If X leave map put x in map
	// If Y leave map delete Entity (protected pop it)
	// If checkEntity true onHit() else tab[y][x] = &Aentity
}

void            	AEntity::move( void )
{
	if (this->direction = LESS_Y)
		this->move(-1, 0);
	else if (this->direction = PLUS_Y)
		this->move(1, 0);
	else if (this->direction = LESS_X)
		this->move(0, -1);
	else if (this->direction = PLUS_X)
		this->move(0, 1);
}


bool				AEntity::onMove( void )
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


void	AEntity::setX( int x )
{
	this->_x = x;
}

int		AEntity::getX( void ) const
{
	return this->_x;
}


void	AEntity::setY( int y )
{
	this->_y = y;
}

int		AEntity::getY( void ) const
{
	return this->_y;
}

std::string		AEntity::getName(void) const
{
	return this->_name;
}

void			AEntity::setName( std::string name)
{
	this->_name = name;
}


std::string		AEntity::getType(void) const
{
	return this->_type;
}

void			AEntity::setType( std::string type)
{
	this->_type = type;
}

