#include "Square.class.hpp"

Square::Square( void )
{
	this->_entity = NULL;
}

Square::Square( Square const & src )
{
	*this = src;
}

Square::~Square( void )
{
	if(this->_entity != NULL)
		delete this->_entity;
}

Square const &		Square::operator=( Square const & rhs )
{
	if (this != &rhs)
	{

	}
	return *this;
}

AEntity *		Square::getEntity( void ) const
{
	return this->_entity;
}

void			Square::setEntity( AEntity * entity )
{
	this->_entity = entity;
}

bool			Square::hasEntity()
{
	return this->_entity != NULL;
}
