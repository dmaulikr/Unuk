#include "Timer.h"

Timer::Timer(void) {
  m_startTicks  = 0;
  m_pausedTicks = 0;
  m_paused  = false;
  m_started = false;
}

Timer::~Timer(void) {
}

void Timer::Start(void) {
  m_paused  = false;
  m_started = true;
  m_startTicks = SDL_GetTicks();
}

void Timer::Stop(void) {
  m_paused  = false;
  m_started = true;
}

void Timer::Pause(void) {
  assert(m_paused == false);
  m_paused = true;

  m_pausedTicks = SDL_GetTicks() - m_startTicks;
}

void Timer::Unpause(void) {
  assert(m_paused == true);
  m_paused = false;

  m_startTicks = SDL_GetTicks() - m_pausedTicks;

  m_pausedTicks = 0;
}

int Timer::GetTicks(void) {
  if(m_paused == true)
    return m_pausedTicks;
  else if(m_started == true)
    return SDL_GetTicks() - m_startTicks;
  else
    return 0;
}

string Timer::GetTicksStr(void) {
  stringstream str;
  str << GetTicks() << "ms";

  return str.str();
}
