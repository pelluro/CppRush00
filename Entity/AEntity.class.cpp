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

void	AEntity::move( int x, int y )
{
	this->_x += x;
	this->_y += y;
	// If X leave map put x in map
	// If Y leave map delete Entity (protected pop it)
}



void	AEntity::setX( int x )
{
	this->_x = x;
}

int		AEntity::getX( void )
{
	return this->_x;
}


void	AEntity::setY( int y )
{
	this->_y = y;
}

int		AEntity::getY( void )
{
	return this->_y;
}
