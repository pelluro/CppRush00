//
// Created by pelluro on 25/05/19.
//

#ifndef NCURSES_HPP
#define NCURSES_HPP
# include <cstddef>

class Ncurses
{
	public:
		Ncurses(void);
		Ncurses(Ncurses const &);
		~Ncurses(void);

		Ncurses& operator=(Ncurses const &);

		void setSize(int y, int x);
		int getX(void);
		int getY(void);
	private:
		int _x;
		int _y;
	};

	Ncurses* env(Ncurses *c = NULL);

#endif //CPPRUSH00_NCURSES_HPP
