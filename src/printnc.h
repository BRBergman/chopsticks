#ifndef PRINTNC_H
#define PRINTNC_H
#include <ncurses.h>
#include <iostream>
#include <stdarg.h>
extern int row, col;

//print a message to the center of the screen, returns length 
int printnccenter (const char *format, ...);
//print a message to the center of the screen, add offset from middle, returns length
int printnccenter (int ver, int hoz, const char *format, ...);
//prints message to the left of the screen, ver to go down, hoz to go to the side
int printnc (int ver, int hoz, const char *format, ...);
//prints message to the left of the screen, ver to go down
int printnc (int ver, const char *format, ...);
//prints message to top left of the screen
int printnc (const char *format, ...);




#endif