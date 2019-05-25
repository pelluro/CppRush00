#include"Map.class.hpp"

Map::Map( void )
{

}
Map::Map( Map const & src )
{

}

Map::~Map( void )
{

}

Map const &		Map::operator=( Map const & rhs )
{
	if (this != &rhs)
	{
		return *this;
	}
}



Square  const &	Map::getSquare( int y, int x )
{
	return this->_tab[y][x];
}

AEntity *		Map::getEntity( int y, int x )
{
	return this->getSquare()->getEntity();
}