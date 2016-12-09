#include <stdio.h>
#include <list>
#include <iostream>

using namespace std;

int repeater(int readpin, list<int> writepinList);
int scan();
int getTime(int status);
int getInterval(double t1, double t2);
void send(list<int> writepinList);
void readAndSend(list<int> writepinList);
void output(int on_time, int off_time, list<int> writepinList);
void high(int on_time, list<int> writepinList);
