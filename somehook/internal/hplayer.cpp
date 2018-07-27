#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include "hplayer.h"

#include <stdio.h>
#include <dlfcn.h>
#include <string.h>


typedef void (Player::*t_orig_setCoord)(int x, int y);
t_orig_setCoord orig_setCoord = NULL;

void Player::setCoord(int x,int y)
{   
    if (!orig_setCoord)
    {
        void *tmpPtr = dlsym(RTLD_NEXT, "_ZN6Player8setCoordEii");
        memcpy(&orig_setCoord, &tmpPtr, sizeof(&tmpPtr));
    }

    printf("%i %i\n",x,y);

    (this->*orig_setCoord)(10,20);
}

std::string Player::getName() const
{   
    return "Almas Pite";
}