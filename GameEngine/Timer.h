#ifndef TIMER_H_
#define TIMER_H_
#include <chrono>
#include <ctime>
#include <thread>

namespace GameEngine{
class Timer {
public:
  Timer(unsigned int fps);
  void start();
  double end();
  void wait();
  double getTime();
private:
  static std::chrono::time_point<std::chrono::system_clock> startTime;
  unsigned int m_desiredFPS;
  double m_lastFrameDuration;
  std::chrono::time_point<std::chrono::system_clock> m_lastFrameTime;
};

}














#endif
