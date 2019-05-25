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
_x(0),_y(0), _type( NULL ), _name("nobody")
{

}

AEntity::AEntity( std::string name, std::string type, int x, int y ):
_x(x),_y(y), _type( type ), _name( name )
{

}

AEntity::AEntity( std::string name, std::string type ):
_x(0), _y(0), _type(type), _name(name)
{

}

AEntity::AEntity( std::string type ):
_x(0), _y(0), _type(type), _name(type)
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

		this->_action_frequency = rhs._action_frequency;
		this->_turn_before_action = rhs._turn_before_action;

		this->_move_frequency = rhs._move_frequency;
		this->_turn_before_move = rhs._turn_before_move;
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
