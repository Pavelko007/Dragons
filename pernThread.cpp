/*
 * File Name:    pernThread.cpp
 *
 * Author:        Your Name
 * Creation Date: Monday, September 01 2014, 15:49 
 * Last Modified: Monday, September 01 2014, 21:02
 * 
 * File Description:
 *
 */
#include "pernThread.h"
#include "util.h"

PernThread* PernThread::single = nullptr;
bool PernThread::instance = false;
int PernThread::ptXPos = -1;
int PernThread::ptYPos = -1;

/*
PernThread::PernThread( int xPos, int yPos )
          : ptXPos( xPos ), ptYPos( yPos )
{    }
*/

ostream& operator << ( ostream& os, const PernThread * pt )
{
    os << "Current thread is at x = " << pt->ptXPos
       << " y = " << pt->ptYPos;

    return os;
}

PernThread * PernThread::getThread( )
{
    if( !instance )
    {
       single = new PernThread;
       ptXPos = initialThreadXPos( );
       ptYPos = initialThreadYPos( );
       instance = true;
    }

    return single;
}

PernThread::~PernThread( )
{
       instance = false;
       single = nullptr;
       ptXPos = -1;
       ptYPos = -1;
}

