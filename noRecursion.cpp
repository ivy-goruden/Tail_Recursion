#include <cstddef>
#include <iostream>
#include <mach/mach.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

int main() {
  printf("NO RECURSION:\n");
  std::vector<int> n;
  int i = 1;
  while (i < 1024) {
    n.insert(n.begin(), i);
    i++;
  }
  struct task_basic_info info;
  mach_msg_type_number_t infoCount = TASK_BASIC_INFO_COUNT;
  auto start = std::chrono::high_resolution_clock::now();
  auto end = std::chrono::high_resolution_clock::now();

  int sum = 0;
  for (const auto &val : n) {
    sum += val;
  }

  if (task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)&info,
                &infoCount) == KERN_SUCCESS) {
    std::cout << "Memory: " << info.resident_size / 1024 / 1024 << " MB"
              << std::endl;
  }
  std::cout << "Sum " << "is " << sum << "\n";

  std::chrono::duration<double, std::milli> duration_ms = end - start;
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds\n";
  return 0;
}