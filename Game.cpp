//
// Created by pelluro on 25/05/19.
//

#include "Game.hpp"

Game::Game(Player *player, WINDOW *winInfo, WINDOW *winGame) :
 _entity(),
 _timer(0),
 _score(0),
 _winInfo(winInfo),
 _winGame(winGame)
{
	return;
}


int Game::listen(void)
{
	int ch = getch();
	switch (ch)
	{
		case KEY_LEFT:
			this->_entity->move();
			break;
		case KEY_RIGHT:
			this->_entity->move();
			break;
		case KEY_UP:
			this->_entity->move();
			break;
		case KEY_DOWN:
			this->_entity->move();
			break;
		case KEY_HOME:
			while ((ch = getch()) != KEY_HOME);
		case KEY_END:
			return (0);
		case 32:
		{
			//drop weapon
			//drop table AEntity
		}
		default:
			break;
	}
	return (1);
}

void		addEntity(AEntity * entity)
{
	int i = 0;
	AEntity ** tmp = this->_entity;

	if (!entity)
		return (this->getCount());
	while (i < this->getCount())
		if (this->getUnit(i++) == entity)
			return (this->getCount());

	i = 0;

	this->_entity = new AEntity*[this->getCount() + 1];


	while (i < this->getCount())
	{
		this->_entity[i] = tmp[i];
		i++;
	}
	this->_entity[i] = entity;
	delete tmp;
	return (++this->_count);
}

void		removeEntity(int idx)
{

}

AEntity*	getEntity(int idx) const
{
	if (n < this->getCount() && idx >= 0)
		return this->_entity[idx];
	return NULL;
}

int			getCount( void ) const
{
	return this->_count;
}
