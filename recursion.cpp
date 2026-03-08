#include <cstddef>
#include <cstring>
#include <iostream>
#include <mach/mach.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

int sum(std::vector<int> a) {
  if (a.size() == 0) {
    return 0;
  }
  int val = a.at(0);
  a.erase(a.begin());
  return val + sum(a);
}

int main() {
  printf("RECURSION:\n");
  std::vector<int> n;
  int i = 1;
  while (i < 1024) {
    n.insert(n.begin(), i);
    i++;
  }
  struct task_basic_info info;
  mach_msg_type_number_t infoCount = TASK_BASIC_INFO_COUNT;
  auto start = std::chrono::high_resolution_clock::now();

  int sumV = sum(n);

  auto end = std::chrono::high_resolution_clock::now();
  if (task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)&info,
                &infoCount) == KERN_SUCCESS) {
    std::cout << "Memory: " << info.resident_size / 1024 / 1024 << " MB"
              << std::endl;
  }
  std::cout << "Sum " << "is " << sumV << "\n";
  std::chrono::duration<double, std::milli> duration_ms = end - start;
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds\n";
  return 0;
}