/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:45:56 by mipham            #+#    #+#             */
/*   Updated: 2019/05/26 16:46:02 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <sstream>
#include "Game.class.hpp"
#include "Entity/Characters/Creatures/Basic.hpp"

Game * Game::_current_game = NULL;

Game::Game()
{
	this->_current_game = this;
	this->_winGame = newwin(HEIGHT, WIDTH, 0, 0);
	this->_winInfo = newwin(8, WIDTH, HEIGHT + 1, 0);
	this->_map = new Map();
	this->_player = new Player();
	this->_count = 0;
	this->_entity = NULL;
	this->_current_game = this;
	this->_timer = 0;
	this->_score = 0;
}

Game::Game(const Game & src)
{
	this->_winGame = src._winGame;
	this->_winInfo = src._winInfo;
	this->_map = src._map;
	this->_player = src._player;
	this->_entity = src._entity;
	this->_count = src._count;
	this->_timer = src._timer;
	this->_score = src._score;

}

Game &Game::operator = (const Game & src){
	this->_winGame = src._winGame;
	this->_winInfo = src._winInfo;
	this->_map = src._map;
	this->_player = src._player;
	this->_entity = src._entity;
	this->_count = src._count;
	this->_timer = src._timer;
	this->_score = src._score;
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
	nodelay(stdscr,true);
	int i = 0;

<<<<<<< HEAD
	AEntity* unit;

	while(listen()){
		usleep(10);
=======
	while(listen() && this->_player->getHP()>0){
>>>>>>> b1448cb7a43d72c6c2ad8c463e211bc5d76179ac
		std::stringstream o;
		o << i << "||" << this->getCount() << "||" << this->_player->getHP() << std::endl;
		this->log(o.str());
		this->iterate();
		if(i == 40000)
		{
			i = 0;
		}
		switch(i++){
			case 150:
			case 300:
			case 450:
			case 600:
			case 750:
			case 900:
			case 1050:
			case 1200:
			{
<<<<<<< HEAD
				unit = new Basic();
				unit->setX(rand() % (WIDTH - 2) );
				unit->setY(1);
				this->addEntity(unit);
				break;
			}
			case 1000:
			case 2000:
			{
				unit = new Tier2();
				unit->setX(rand() % (WIDTH - 2) );
=======
				AEntity* unit = new Basic();
				unit->setX(rand() % (WIDTH - 2) );

>>>>>>> b1448cb7a43d72c6c2ad8c463e211bc5d76179ac
				unit->setY(1);
				this->addEntity(unit);
				break;
			}
		}
		this->_map->print(this->_winGame);
		this->_score++;
		this->displayInfo();
	}
	this->gameOver();
}

void Game::iterate()
{
	int i = 0;
	AEntity* entity;
	while (i < this->getCount())
	{
		entity = this->getEntity(i);
		if (!entity->toDelete())
		{
			if (entity->move())
			{

				this->_map->updateEntity(this->_winGame, entity);
			}
			if (entity->onAction())
				entity->fire();
		}
		i++;
	}
	i = 0;
	while (i < this->getCount())
	{
		entity = this->getEntity(i);
		if (entity->toDelete())
		{
			this->removeEntity(i);
		}
		else
			i++;
	}
}

bool Game::listen(void)
{
	int ch = getch();

	this->_player->wait();

	switch (ch)
	{
		case KEY_LEFT:
			this->_player->move(-1,0);
			break;
		case KEY_RIGHT:
			this->_player->move(1,0);
			break;
		case KEY_UP:
			this->_player->move(0,-1);
			break;
		case KEY_DOWN:
			this->_player->move(0,1);
			break;
		case KEY_HOME:
			nodelay(stdscr,false);
			while ((ch = getch()) != KEY_HOME);
			nodelay(stdscr,true);
			return (true);
		case 27:
			return (false);
		case 32:
		{
			this->_player->fire();
		}
		default:
			break;
	}
	this->_map->updateEntity(this->_winGame, this->_player);
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
	if (tmp)
		delete tmp;
	return (++this->_count);
}

void		Game::removeEntity(int idx)
{
	int i = 0;
	AEntity ** tmp = this->_entity;

	if (idx >= this->getCount() || idx < 0)
		return ;

	AEntity * to_delete = tmp[idx];

	this->_entity = new AEntity*[this->getCount() - 1];

	while (i < idx)
	{
		this->_entity[i] = tmp[i];
		i++;
	}
	

	while(++i < this->getCount())
		this->_entity[i - 1] = tmp[i];
	this->_count--;
	delete tmp;
	this->_map->removeEntity(this->_winGame, to_delete->getOldX(), to_delete->getOldY());
	this->_map->removeEntity(this->_winGame, to_delete->getX(), to_delete->getY());
	delete to_delete;
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

Game * 		Game::getGame( void )
{
	return Game::_current_game;
}


int Game::getScore(void) const
{
	return this->_score;
}

void Game::increaseScore(int s)
{
	this->_score += s;
	if(this->_score < 0)
		this->_score = 0;
}

int Game::getTimer(void) const
{
	return this->_timer;
}

<<<<<<< HEAD
void Game::addLife( void )
{
	this->_player->setHP(this->_player->getHP() + 1);
}

void Game::changeWeapon( Weapon * w )
{
	this->_player->equipWeapon(w);
}


=======
void Game::gameOver(void)
{
	nodelay(stdscr,false);
	this->log("ENTER KEYBOARD TO LEAVE");
	getch();
}

>>>>>>> b1448cb7a43d72c6c2ad8c463e211bc5d76179ac
void	Game::displayInfo(void)
{
	std::stringstream o;
	o << "HP: "  << this->_player->getHP() << " lives" << std::endl;
	std::string info = o.str();
	mvwprintw(this->_winInfo, 2, 1, info.c_str());
	o.clear();
	int score = this->getScore();
	o << "Score: " << score << std::endl;
	info = o.str();
	mvwprintw(this->_winInfo, 4, 1, info.c_str());
}
