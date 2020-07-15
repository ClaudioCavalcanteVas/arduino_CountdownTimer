/**
 * Created By Claudio <p3lpz> Cavalcante - July 14, 2020
 * At a Pandemic Home Office - XD
 */

#include "CountdownTimer.h"

#define RUNNING 'r'
#define STOPPED 's'
#define PAUSED 'p'

CountdownTimer::CountdownTimer(int defaultMinutes, int defaultSeconds) {

  this->_defaultMinutes = defaultMinutes;
  this->_defaultSeconds = defaultSeconds;

  clean();

}

void CountdownTimer::clean() {
  _minutes = _defaultMinutes;
  _seconds = _defaultSeconds;

  _state = STOPPED;

  _lastCountdown = 0;
}


int CountdownTimer::start() {
  if(isRunning())
    return 0; // Return false if the Countdown was started before

  _lastCountdown = millis();

  _state = RUNNING;

  return 1;
}

int CountdownTimer::stop() {
  clean(); 
}

int CountdownTimer::pause() {
  _state = PAUSED;
}

int CountdownTimer::count() {

  if ( _state == 0 ) {
    return 0;
  }

  int now = millis();
  
  int secondsPassed = (now - _lastCountdown)/1000;

  if (secondsPassed < 1) return 0;

  _lastCountdown = now;

  setSeconds(secondsPassed%60);
  setMinutes(secondsPassed/60);  

  if (_minutes == 0 && _seconds == 0) {
    stop();
    return 0;
  }

  return 1;

}

void CountdownTimer::setMinutes(int minutes) {
  if (_minutes >= minutes) minutes = 0;
  else _minutes -= minutes;
}

void CountdownTimer::setSeconds(int seconds) {

  if (_seconds < seconds) seconds = 0;
  else _seconds -= seconds;
}

int CountdownTimer::getMinutes() {
  return _minutes;
}

int CountdownTimer::getSeconds() {
  return _seconds;
}

int CountdownTimer::isRunning() {
  return _state == RUNNING;
}

int CountdownTimer::isStopped() {
  return _state == STOPPED;
}

int CountdownTimer::isPaused() {
  return _state == PAUSED;
}

