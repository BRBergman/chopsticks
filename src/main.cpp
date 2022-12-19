#include <iostream>
#include <ncurses.h>
#include <array>
#include <cmath>
#include "printnc.h"


struct screensize
{
	
	private:
	
	public:
		int row, col;

	screensize()
	{
		initscr();
		getmaxyx(stdscr,row,col);
	}
	
};


struct eachhand{

	int hp = 1;
	bool dead = false;
	void takedamage(int damagepoints)
	{
		hp += damagepoints;
		if (hp > 5)
		{
			hp = 0;
			dead = true;
		}
		return;
	}
};

class player
{

	private:
	void delwins()
	{
		delwin(wleft);
		delwin(wright);
	}

	public:
	WINDOW *wleft;
	WINDOW *wright;
	eachhand hleft;
	eachhand hright;

	~player()
	{
		delwins();
	}

	void transfer()	//equalize
	{
		float f = (float(hleft.hp)+float(hright.hp))/2;
		mvprintw(1,1,"%f",f);
		hleft.hp=int(floor(f));
		hright.hp=int(ceil(f));	
	}
	
	player(bool ontop, struct screensize scr)//constructor
	{
		if (ontop)
		{
			wleft = newwin(scr.row/2,scr.col/2,0,0);
			wright = newwin(scr.row/2,scr.col/2,0,scr.col/2);
		}
		else
		{
			wleft = newwin(scr.row/2,scr.col/2,scr.row/2,0);
			wright = newwin(scr.row/2,scr.col/2,scr.row/2,scr.col/2);
		}
		box(wleft,0,0);
		box(wright,0,0);
		wrefresh(wleft);
		wrefresh(wright);
		wgetch(wleft);
	}
	
	void perframe()
	{
	

		
		return; 
	}
};






int main()
{	

	screensize scr;

	


	
	
	player plr1(false,scr); //bottom 
	player plr2(true,scr);	//top
	
	bool anyonewon = false;
	
	/*
	while (!anyonewon)
	{
		plr1.perframe();
		plr2.perframe();
		

	}
	
	*/






	
	

	getch();

	
	endwin();
	
	return 0;
}