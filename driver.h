/*
 * File Name:    driver.h
 *
 * Author:        Your Name
 * Creation Date: Wednesday, August 27 2014, 19:52 
 * Last Modified: Thursday, September 04 2014, 19:02
 * 
 * File Description:
 *
 */
#include "dragon.h"
#include "util.h"
#include "pernThread.h"

const int NUMBER_OF_DRAGONS = 3;

enum { ADD = 1, DETECT, SELECT_ACTION, DISPLAY, QUIT };
int loadFile( Dragon * dragons );
void run( Dragon * dragons, int & currDragonNumbers );
void displayMainMenu( );
void process( Dragon * dragons, int & currentDragonsNumbers, int choice,
              PernThread *& ptPtr );
void addDragon( Dragon * dragons, int & currentDragonsNumbers );
int selectDragon( const Dragon * dragons, int currentDragonsNumbers );
void action( Dragon * dragons, int currentDragonsNumbers,
             PernThread *& ptPtr );
void showAll( const Dragon * dragons, int currentDragonsNumbers,
              const PernThread * ptPtr );
void save( const Dragon * dragons, const PernThread & pt );
void makeThread( PernThread *& pt );
