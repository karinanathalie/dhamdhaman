//animation.h
#ifndef ANIMATION_H
#define ANIMATION_H

//Define Sleep function
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <stdlib.h>
#include "printboard.h"

using namespace std;

void clear_screen();
void delay();
void delay_vis();
void delay_closing();
void visualization();
void HomePage();
void HowtoPlay();
void closing_multiplayer(string x);
void closing_vscomp(bool win_status);

#endif