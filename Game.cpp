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