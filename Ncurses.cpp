//
// Created by pelluro on 25/05/19.
//

#include "Ncurses.hpp"


#include <ncurses.h>
#include <csignal>

Ncurses* env(Ncurses *c)
{
	static Ncurses* ptr;

	if (c)
		ptr = c;
	return ptr;
}

void	onResize(int)
{
	// reinitialize the window
	endwin();
	refresh();
	clear();

	// get the new dimensions
	int x, y;
	getmaxyx(stdscr, y, x);
	env()->setSize(y, x);
}

Ncurses::Ncurses(void) : _x(0), _y(0)
{
	initscr(); // initialize ncurses
	cbreak(); // don't buffer the TTY
	noecho(); // don't echo in TTY

	curs_set(0); // hide cursor

	// main window flags
	keypad(stdscr, TRUE); // allow special keys
	nodelay(stdscr, TRUE); // dont block the main thread when querying keys
	scrollok(stdscr, FALSE); // dont allow scrolling the window

	// get dimensions
	getmaxyx(stdscr, this->_y, this->_x);

	// register handlers
	std::signal(SIGWINCH, onResize); // allow resizing
}


Ncurses::~Ncurses(void)
{
	// foreach window
	// delwin(win)

	endwin();
}

void Ncurses::setSize(int y, int x)
{
	this->_y = y;
	this->_x = x;
}

int Ncurses::getX(void)
{
	return this->_x;
}

int Ncurses::getY(void)
{
	return this->_y;
}

Ncurses::Ncurses(Ncurses const &) {}
Ncurses& Ncurses::operator=(Ncurses const &) { return *this; }
