#include "printnc.h"
#include <stdarg.h>
int prow, pcol;


int printnccenter (const char *format, ...)
{
   	char buffer[256];
  	va_list args;
  	va_start (args, format);
  	int done = vsprintf (buffer,format, args);
  	va_end (args);
	std::string in = buffer;
	mvprintw(prow/2,(pcol-done)/2,"%s",in.c_str()); //print string to center of screen
	return done;
}
//		mvprintw(row/2-7+i, (col-strlen(askev[i])-11)/2, "Press %i to %s",i,askev[i] );

int printnccenter (int ver, int hoz, const char *format, ...)
{
   	char buffer[256];
  	va_list args;
  	va_start (args, format);
  	int done = vsprintf (buffer,format, args);
  	va_end (args);
	std::string in = buffer;
	mvprintw(prow/2-ver,(pcol-done)/2-hoz,"%s",in.c_str()); //print string to center of screen
	return done;
}

int printnc (int ver, int hoz, const char *format, ...)
{
   	char buffer[256];
  	va_list args;
  	va_start (args, format);
  	int done = vsprintf (buffer,format, args);
  	va_end (args);
	std::string in = buffer;
	mvprintw(ver,hoz,"%s",in.c_str()); //print string to center of screen
	return done;
}
int printnc (int ver, const char *format, ...)
{
   	char buffer[256];
  	va_list args;
  	va_start (args, format);
  	int done = vsprintf (buffer,format, args);
  	va_end (args);
	std::string in = buffer;
	mvprintw(ver,0,"%s",in.c_str()); //print string to center of screen
	return done;
}

int printnc (const char *format, ...)
{
   	char buffer[256];
  	va_list args;
  	va_start (args, format);
  	int done = vsprintf (buffer,format, args);
  	va_end (args);
	std::string in = buffer;
	mvprintw(0,0,"%s",in.c_str()); //print string to center of screen
	return done;
}