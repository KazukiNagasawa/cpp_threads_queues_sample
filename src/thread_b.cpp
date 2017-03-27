#include <chrono>
#include <iostream>
#include <queue>
#include <thread>

#include "thread_b.hpp"


ThreadB::ThreadB(size_t max_size)
{
  this->max_size         = max_size;
  this->process_end_flag = false;
}


void ThreadB::addQueue(queue_t* queue)
{
  this->queues.push_back(queue);
}


void ThreadB::setProcessEndFlag(bool* process_end_flag)
{
  this->top_process_end_flag = process_end_flag;
}



void ThreadB::start()
{
  this->th = std::thread(&ThreadB::run, this);
}


void ThreadB::join()
{
  if (this->th.joinable()) {
    this->th.join();
  }
}


void ThreadB::run()
{
  std::cout << "Thread B Start" << std::endl;
  while (true) {

    // Thread sleep
    std::chrono::milliseconds dura(1);
    std::this_thread::sleep_for(dura);
    
    if (this->queue.empty()) {
      if ((*this->top_process_end_flag) == true) {
	break;
      }
      else {
	continue;
      }
    }

    if (this->data.size() >= this->max_size) {
      this->data.erase(this->data.begin());
    }
    
    this->data.push_back(this->queue.front());
    this->queue.pop();

    if (this->data.size() == this->max_size) {
      std::cout << "Thread B : ";
      int sum = 0;
      for (size_t i = 0; i < this->data.size(); i++) {
	int datum = this->data[i];
	sum += datum;
	std::cout << datum << " ";
	if (i < this->data.size() - 1) {
	  std::cout << "+ ";
	}
      }
      std::cout << "=> " << sum << std::endl;

      // Push to queue
      for (queue_t* queue: this->queues) {
	queue->push(sum);
      }
      
    }
  }
  std::cout << "Thread B End" << std::endl;
  this->process_end_flag = true;
}
