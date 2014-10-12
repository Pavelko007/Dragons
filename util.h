/*
 * File Name:    util.h
 *
 * Author:        Your Name
 * Creation Date: Wednesday, August 27 2014, 20:09 
 * Last Modified: Thursday, September 04 2014, 19:05
 * 
 * File Description:
 *
 */
#ifndef UTIL_H
#define UTIL_H

#include "dragon.h"
#include "pernThread.h"

const int MAX_DRAGON_XPOS = 3000;
const int MIN_DRAGON_XPOS = -3000;
const int MAX_DRAGON_YPOS = 3000;
const int MIN_DRAGON_YPOS = 100;

const int MAX_THREAD_XPOS = 3000;
const int MIN_THREAD_XPOS = -3000;
const int MAX_THREAD_YPOS = 4000;
const int MIN_THREAD_YPOS = 2000;

#include <ctime>
using std::time;

#include <cstdlib>
using std::srand;

#include <cmath>
using std::pow;
using std::sqrt;

int dragonNewXPos( const Dragon & d, bool direction );
int dragonNewYPos( const Dragon & d, bool direction );
void threadNewPos( PernThread*& pt );
bool flameThread( const Dragon& d, const PernThread * ptPtr );
int distance(const Dragon &d, const PernThread * pt);

int initialDragonXPos( );
int initialDragonYPos( );
int initialThreadXPos( );
int initialThreadYPos( );

void initialize( );
#endif
