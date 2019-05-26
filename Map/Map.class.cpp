
#include "Map.class.hpp"
#include <ncurses.h>
#include <sstream>


Map::Map( void )
{
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			this->_tab[x][y] = new Square();
		}
	}
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



Square*  const &	Map::getSquare( int x, int y ) const
{
	return this->_tab[x][y];
}

void Map::addEntity(AEntity *entity)
{
	int x = entity->getX();
	int y = entity->getY();
	if(x < WIDTH && y < HEIGHT)
	{
		if (!this->_tab[x][y]->hasEntity())
			this->_tab[x][y]->setEntity(entity);
		else if (this->_tab[x][y]->getEntity() != entity)
		{
			AEntity * other = this->_tab[x][y]->getEntity();
			entity->hit(*other);
			other->hit(*entity);
		}
	}
	else
	{
		// Hors ecran
	}
}

void Map::updateEntity(WINDOW * w, AEntity *entity)
{
	if (entity->getOldX() != entity->getX() || entity->getOldY() !=entity->getY())
	{
		this->removeEntity(w, entity->getOldX(), entity->getOldY());
		this->addEntity(entity);		
	}

}

void Map::removeEntity(WINDOW *w, int x, int y)
{
	this->_tab[x][y]->setEntity(NULL);
	wmove(w, y, x);
	waddch(w, ' ');
}

void Map::print(WINDOW *w)
{
	// Affiche les bordures
	for (int i = 0; i < HEIGHT; i++)
	{
		wmove(w, i, 0);
		waddch(w, '*');
		wmove(w, i, WIDTH-1);
		waddch(w, '*');
	}
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			Square* s = this->getSquare(x, y);
			if(s->hasEntity())
			{
				AEntity* entity = s->getEntity();
				wmove(w, y, x);
				waddch(w, entity->getType());
			}
			s = NULL;
		}
	}

	// Affiche l ecran
	wrefresh(w);
}

std::string Map::toString()
{
	std::stringstream o;
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			Square* s = this->getSquare(x,y);
			if(s->hasEntity())
			{
				AEntity* entity = s->getEntity();
				o << "Entite '" << entity->getName() << "' en (" << entity->getX() << "," << entity->getY() << ")" << " | ";
			}
		}
	}
	return o.str();
}
