//
// Created by pelluro on 25/05/19.
//

#ifndef GAME_HPP
#define GAME_HPP

#include "Entity/AEntity.class.hpp"
#include "Entity/Characters/Player.class.hpp"
#include <ncurses.h>
#include <ctime>


#define WIDTH COLS
#define HEIGHT (LINES - 9)
#define FPS 50

class Game
{
protected:
	AEntity   **_entity;
	int     _timer;
	int     _score;
	WINDOW  *_winInfo;
	WINDOW  *_winGame;
	int		_count;



public:
	Game(void);
	Game(Player *player, WINDOW  *winInfo, WINDOW  *winGame);
	~Game(void);
	Game(const Game & src);
	Game & operator = (const Game & src);


	int getTimer() const;
	int getScore() const;


	void loop(void);
	int listen(void);
	void refreshBox(void);
	void refresh(int count);
	void displayInfo(void);
	int startGame(void);
	void gameOver(void);
	void checkDeath(void); //de tout les entity

	void addEntity(AEntity * entity);
	void removeEntity(int idx);
	AEntity* getEntity(int idx) const;
	int getCount( void ) const;


private:
	clock_t _time;
};

#endif //CPPRUSH00_GAME_HPP
