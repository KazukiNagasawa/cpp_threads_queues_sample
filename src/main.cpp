#include <iostream>

#include "thread_a.hpp"
#include "thread_b.hpp"
#include "thread_c.hpp"

int main()
{
  ThreadA th_a(10);
  ThreadB th_b(3);
  ThreadC th_c(2);
  th_a.addQueue(&(th_b.queue));
  th_b.addQueue(&(th_c.queue));
  th_b.setProcessEndFlag(&(th_a.process_end_flag));
  th_c.setProcessEndFlag(&(th_b.process_end_flag));

  th_a.start();
  th_b.start();
  th_c.start();
  
  th_a.join();
  th_b.join();
  th_c.join();
  
  std::cout << "OK" << std::endl;
  
  return 0;
}
