//
// Created by pelluro on 25/05/19.
//

#ifndef GAME_HPP
#define GAME_HPP

#include "Entity/AEntity.class.hpp"
#include "Entity/Characters/Character.class.hpp"
#include "Entity/Characters/Player.class.hpp"
#include "Map/Map.class.hpp"
#include <ncurses.h>
#include <ctime>


class Game
{

public:
	Game();
	~Game();
	Game(const Game & src);
	Game & operator = (const Game & src);


	//int getTimer() const;
	//int getScore() const;
	//void loop(void);
	bool listen(void);
	//void refreshBox(void);
	//void refresh(int count);
	//void refresh();
	//void displayInfo(void);
	void start(void);
	void iterate(void);
	//void gameOver(void);
	//void checkDeath(void); //de tout les entity

	int addEntity(AEntity * entity);
	AEntity *getEntity( int idx ) const;
	void removeEntity(int idx);
	int getCount( void ) const;

	void log(std::string);

private:
	AEntity   **_entity;
	WINDOW  *_winInfo;
	WINDOW  *_winGame;
	int		_count;
	Map* _map;
	Player * _player;
	//int     _timer;
	//int     _score;
	//clock_t _time;

};

#endif
