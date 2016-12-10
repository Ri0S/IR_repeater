#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <list>
#include <iostream>
#include "irrev.h"

using namespace std;

int readable = 1;
int interval = 10;
int max_wait = 40000;
int quit = 0;
int turnon[50];
int turnoff[50];
int read_pin;

int first=0;
int Hz = 38;
int duty_num = 1;
int duty_denomi = 3;
int unit = 26;
int duty_high = 9;
int duty_low = 17;
int repeat = 1;
int length;

void signalCallBackHandler(int sig){
    readable = 0;
}

double getMoment(){
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((double)(tv.tv_sec) * 1000000 + (double)(tv.tv_usec));
}

int repeater(int readpin, list<int> writepinList){
    int result;
    read_pin = readpin;
    if(!first){
        if(signal(SIGINT, signalCallBackHandler) == SIG_ERR){
            printf("can't set signal\n");
            exit(1);
        }

        if(wiringPiSetup() == -1){
            printf("error wiringPi setup\n");
            exit(1);
        }
        first = 1;
    }

    for(list<int>::iterator i = writepinList.begin();i != writepinList.end() ;i++)
        pinMode(*i, OUTPUT);
    pinMode(read_pin, INPUT);
    while(quit){
        result = scan();

        if(result || !readable){
            printf("\n\n!!! could not scanning. quit.\n\n");
        }
        
        send(writepinList);
    }

    return 0;
}

int scan(){
    if(!digitalRead(read_pin)){ return 1; }

    int on, off;

    while( readable && digitalRead(read_pin) ){}
    int i=0;
    while( readable ){

        on = getTime(0);
        off = getTime(1);
        turnon[i] = on;
        turnoff[i] = off;
        if(off > max_wait){ break; }
        i++;        
    }
    length = i;
    i = 0;
    return 0;
}

int getTime(int status){
    int count = 0;
    int max = max_wait / interval;
    double start, end;

    start = getMoment();
    while( digitalRead(read_pin) == status )    {
        delayMicroseconds(interval);
        count++;

        if(count > max){ break; }
    }
    end = getMoment();

    return getInterval(start, end);
}

int getInterval(double t1, double t2){
    return (int)(t2-t1);
}

void high(int on_time, list<int> writepinList){
    int j;
    int count = on_time/unit;
    for(j=0; j<count; j++)
    {
        for(list<int>::iterator i = writepinList.begin();i != writepinList.end() ;i++)
            digitalWrite(*i, 1);
        delayMicroseconds(duty_high);

        for(list<int>::iterator i = writepinList.begin();i != writepinList.end() ;i++)
            digitalWrite(*i, 0);
        delayMicroseconds(duty_low);
    }
}

void output(int on_time, int off_time, list<int> writepinList){
    high(on_time, writepinList);
    for(list<int>::iterator i = writepinList.begin();i != writepinList.end() ;i++)
        digitalWrite(*i, 0);
    delayMicroseconds(off_time);
}

void readAndSend(list<int> writepinList){
    int i, j;

    for(j=0; j<repeat; j++){
        for(i=0; i<length; i++){
            output(turnon[i], turnoff[i], writepinList);
        }
        usleep(50000);
    }
}

void send(list<int> writepinList){
    unit = (1.0f / (Hz * 1000)) * 1000000;
    duty_high = roundf(((float)unit / duty_denomi) * duty_num);
    unit = (int)unit;
    duty_low = unit - duty_high;

    readAndSend(writepinList);
}

