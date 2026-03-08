#include <cstddef>
#include <cstring>
#include <iostream>
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
  auto start = std::chrono::high_resolution_clock::now();
  std::vector<int> n;
  int i = 1;
  while (i < 1024) {
    n.insert(n.begin(), i);
    i++;
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::cout << "Sum " << "is " << sum(n) << "\n";
  std::chrono::duration<double, std::milli> duration_ms = end - start;
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds\n";
  return 0;
}