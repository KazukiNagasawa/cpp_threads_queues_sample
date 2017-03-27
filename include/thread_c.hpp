#ifndef THREAD_C_H_
#define THREAD_C_H_

#include <iostream>
#include <thread>
#include <vector>

#include "const.hpp"

class ThreadC
{
public:
  ThreadC(size_t max_size);
  void addQueue(queue_t* queue);
  void setProcessEndFlag(bool* process_end_flag);
  void start();
  void join();

public:
  queue_t queue;
  bool process_end_flag;

private:
  void run();

private:
  size_t max_size;
  std::vector<int> data;
  std::vector<queue_t*> queues;

  bool* top_process_end_flag;
  std::thread th;
};

#endif // THREAD_C_H_
