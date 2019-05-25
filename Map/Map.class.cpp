#include "Map.class.hpp"

Map::Map( void )
{

}
Map::Map( Map const & src )
{
	*this = src;
}

Map::~Map( void )
{

}

Map const &		Map::operator=( Map const & rhs )
{
	if (this != &rhs)
	{

	}
	return *this;
}



Square  const &	Map::getSquare( int y, int x ) const
{
	return this->_tab[y][x];
}

AEntity *		Map::getEntity( int y, int x ) const
{
	std::cout << "[ " << y << ", " << x << " ]" << std::endl;
	return this->getSquare(y, x).getEntity();
}

void			Map::setEntity( int y, int x, AEntity * entity )
{
	this->_tab[y][x].setEntity(entity);
}

void			Map::removeEntity( int y, int x )
{
	this->_tab[y][x].setEntity(NULL);
}

