#ifndef THREAD_A_H_
#define THREAD_A_H_

#include <iostream>
#include <thread>
#include <vector>

#include "const.hpp"

class ThreadA
{
public:
  ThreadA(size_t count);
  void addQueue(queue_t* queue);  
  void start();
  void join();

public:
  bool process_end_flag;
  
private:
  void run();

private:
  size_t count;
  std::vector<queue_t*> queues;
 
  std::thread th;
};

#endif // THREAD_A_H_


