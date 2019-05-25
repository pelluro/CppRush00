//
// Created by pelluro on 25/05/19.
//

#ifndef GAME_HPP
#define GAME_HPP

#include "Header.hpp"
#include "Entity/AEntity.class.hpp"
#include "Entity/Characters/Player.class.hpp"
#include <ncurses.h>
#include <ctime>
class Game
{
protected:
	AEntity   *_entity;
	int     _timer;
	int     _score;
	WINDOW  *_winInfo;
	WINDOW  *_winGame;
	int     _ray;

public:
	Game(void);
	Game(Player *player, WINDOW  *winInfo, WINDOW  *winGame);
	~Game(void);
	Game(const Game & src);
	Game & operator = (const Game & src);

//	 *getPlayer() const;
	int getFPS() const;
	int getTimer() const;
	int getScore() const;
//	 *getObjects() const;
	int getRay() const;

	void loop(void);
	int listen(void);
	void refreshBox(void);
	void refresh(int count);
	void displayInfo(void);
	int startGame(void);
	void gameOver(void);
	void checkCollisions(void);
	void checkDeath(void);

private:
	clock_t _time;
};

#endif //CPPRUSH00_GAME_HPP
