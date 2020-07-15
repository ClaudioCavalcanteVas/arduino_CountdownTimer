/**
 * Created By Claudio <p3lpz> Cavalcante - July 14, 2020
 * At a Pandemic Home Office - XD
 */

#ifndef COUNTDOWN_TIMER_H
#define COUNTDOWN_TIMER_H

#include <Arduino.h>

class CountdownTimer {
  private:
    int _minutes;
    int _seconds;
    int _defaultMinutes;
    int _defaultSeconds;

    int _lastCountdown;

    // Clock state 
    char _state;

  public:
    CountdownTimer(int defaultMinutes = 0, int defaultSeconds = 0);
    
    void clean(); // Set the values to default

    int count();
    
    int start();
    int pause();
    int stop();

    char *getTime(); // Update the time and returns it

    int isRunning();
    int isStopped();
    int isPaused();

    void setSeconds(int seconds);
    void setMinutes(int minutes);

    int getMinutes();
    int getSeconds();
};

#endif
