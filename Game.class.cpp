//
// Created by pelluro on 25/05/19.
//

#include <sstream>
#include "Game.class.hpp"
#include "Entity/Characters/Creatures/Basic.hpp"

Game::Game()
{
	this->_winGame = newwin(HEIGHT, WIDTH, 0, 0);
	this->_winInfo = newwin(8, WIDTH, HEIGHT + 1, 0);
	this->_map = new Map();
	this->_player = new Player();
}

Game::Game(const Game & src)
{
	this->_winGame = src._winGame;
	this->_winInfo = src._winInfo;
	this->_map = src._map;
	this->_player = src._player;
	this->_entity = src._entity;
	this->_count = src._count;
}

Game &Game::operator = (const Game & src){
	this->_winGame = src._winGame;
	this->_winInfo = src._winInfo;
	this->_map = src._map;
	this->_player = src._player;
	this->_entity = src._entity;
	this->_count = src._count;
	return *this;
}

Game::~Game()
{
	delete _map;
	delete _player;
	delwin(_winGame);
	delwin(_winInfo);
}

void Game::start()
{
	this->_map->addEntity(this->_player);
	this->_map->print(this->_winGame);
	nodelay(this->_winGame,true);
	int i = 0;
	while(listen()){
		this->iterate();
		if(i == 60)
		{
			i = 0;
		}
		switch(i){
			case 15:
				this->_map->addEntity(new Basic());
				break;
		}
		this->_map->print(this->_winGame);
		i++;
	}
}

void Game::iterate()
{
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			if(this->_map->getSquare(x,y)->hasEntity())
			{
				AEntity* entity = this->_map->getSquare(x,y)->getEntity();
				entity->move();
				this->log("Move "+entity->getName());
				this->_map->updateEntity(entity);
			}
		}
	}
}

bool Game::listen(void)
{
	int ch = getch();
	switch (ch)
	{
		case KEY_LEFT:
			this->_player->move(-1,0);
			this->_map->updateEntity(this->_player);
			break;
		case KEY_RIGHT:
			this->_player->move(1,0);
			this->_map->updateEntity(this->_player);
			break;
		case KEY_UP:
			this->_player->move(0,-1);
			this->_map->updateEntity(this->_player);
			break;
		case KEY_DOWN:
			this->_player->move(0,1);
			this->_map->updateEntity(this->_player);
			break;
		case KEY_HOME:
			nodelay(this->_winGame,false);
			while ((ch = getch()) != KEY_HOME);
			nodelay(this->_winGame,true);
		case 27:
			return (false);
		case 32:
		{
			//fire
		}
		default:
			break;
	}
	return (true);
}

void Game::log(std::string str)
{
	// Vide l ecran
	wrefresh(this->_winInfo);
	wmove(this->_winInfo, 0,0);
	int l = str.size();
	for (int i = 0; i < l; i++)
	{
		char c = str[i];
		waddch(this->_winInfo, c);
	}
	wrefresh(stdscr);
}

int		Game::addEntity(AEntity * entity)
{
	int i = 0;
	AEntity ** tmp = this->_entity;

	if (!entity)
		return (this->getCount());
	while (i < this->getCount())
		if (this->getEntity(i++) == entity)
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

void		Game::removeEntity(int idx)
{
	int i = 0;
	AEntity ** tmp = this->_entity;

	if (idx >= this->getCount() || idx < 0)
		return ;

	this->_entity = new AEntity*[this->getCount() - 1];

	while (i < idx)
	{
		this->_entity[i] = tmp[i];
		i++;
	}
	while(++i < this->getCount())
		this->_entity[i - 1] = tmp[i];
	delete tmp;
}

AEntity*	Game::getEntity(int idx) const
{
	if (idx < this->getCount() && idx >= 0)
		return this->_entity[idx];
	return NULL;
}

int			Game::getCount( void ) const
{
	return this->_count;
}

