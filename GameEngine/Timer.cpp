#include "Timer.h"

namespace GameEngine{

Timer::Timer(unsigned int fps) : m_desiredFPS(fps){

}
std::chrono::time_point<std::chrono::system_clock> Timer::startTime = std::chrono::system_clock::now();

void Timer::start(){
   m_lastFrameTime = std::chrono::system_clock::now();
}

double Timer::end(){
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsedSeconds = end-m_lastFrameTime;
  m_lastFrameDuration = elapsedSeconds.count();
  return elapsedSeconds.count();
}

double Timer::getTime(){
  auto end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsedSeconds = end-startTime;
  return elapsedSeconds.count();
}

void Timer::wait(){
	float time = end();
	if (1.0/time > m_desiredFPS){
		float timeToWait = 1.0f/(float)m_desiredFPS - time;
		while (timeToWait > 0){
			std::this_thread::sleep_for(std::chrono::nanoseconds(1000000));
			timeToWait -= 0.001f;
		}

	}
}


}
