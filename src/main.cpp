#include <iostream>
#include <ncurses.h>
#include <array>
#include <cmath>
#include "printnc.h"
int row, col;


void whowins(bool player)
{
	if (player == false)
	{
		printnccenter("player one wins");
	}
	else
	{
		printnccenter("player two wins");
	}
	

}

class hands
{
	private:
	WINDOW *wleft;
	WINDOW *wright;

	void delwins()
	{
		delwin(wleft);
		delwin(wright);
	}
	bool plr;

	void die()
	{
		for (int i = 0; i < 1; i++)
		{
			if (hitpoints[i] >5)
			{
				hitpoints[i]=0;
			}
		}
		if (hitpoints[0]==0 && hitpoints[1]==0)
		{
			whowins(plr);
		}
	}
	public:
	std::array<int, 2> hitpoints = {1,1}; //0 for l, 1 for r

	~hands()
	{
		delwins();
	}

	void transfer()	//equalize
	{
		float f = (float(hitpoints[0])+float(hitpoints[1]))/2;
		mvprintw(1,1,"%f",f);
		hitpoints[0]=int(floor(f));
		hitpoints[1]=int(ceil(f));	
	}

	hands(bool ontop)//constructor
	{
		if (ontop)
		{
			wleft = newwin(row/2,col/2,0,0);
			wright = newwin(row/2,col/2,0,col/2);
		}
		else
		{
			wleft = newwin(row/2,col/2,row/2,0);
			wright = newwin(row/2,col/2,row/2,col/2);
		}
		box(wleft,0,0);
		box(wright,0,0);
		wrefresh(wleft);
		wrefresh(wright);
		wgetch(wleft);
		plr = true;
	}
	
	void percall()
	{



	}
};


void init()
{
	initscr();
	getmaxyx(stdscr,row,col);
	return;
}


int main()
{	
	init();
	
	hands bottom(false);
	hands top(true);
	
	bottom.hitpoints[0]= 5;
	bottom.hitpoints[1] = 0;
	mvprintw(row/2-1,col/2,"%i|%i",bottom.hitpoints[0],bottom.hitpoints[1]);

	bottom.transfer();
	
	mvprintw(row/2,col/2,"%i|%i",bottom.hitpoints[0],bottom.hitpoints[1]);









	
	

	
	getch();

	
	endwin();
	
	return 0;
}