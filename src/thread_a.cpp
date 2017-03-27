#include <chrono>
#include <iostream>
#include <thread>

#include "thread_a.hpp"


ThreadA::ThreadA(size_t count)
{
  this->count            = count;
  this->process_end_flag = false;
}


void ThreadA::addQueue(queue_t* queue)
{
  this->queues.push_back(queue);
}


void ThreadA::start()
{
  this->th = std::thread(&ThreadA::run, this);
  //this->th.detach();
}


void ThreadA::join()
{
  if (this->th.joinable()) {
    this->th.join();
  }
}


void ThreadA::run()
{
  std::cout << "Thread A Start" << std::endl;
  for (size_t i = 0; i < count; i++) {

    // Thread sleep 
    std::chrono::milliseconds dura(1);
    std::this_thread::sleep_for(dura);

    std::cout << "Thread A : " << i << std::endl;

    // Push to queue
    for (queue_t* queue: this->queues) {
      queue->push(i);
    }
  }
  std::cout << "Thread A End" << std::endl;

  this->process_end_flag = true;
}
