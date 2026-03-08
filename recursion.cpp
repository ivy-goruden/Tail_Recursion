#include "main.h"

long sum(const std::vector<int> &a, int index = 0) {
  if (index == a.size()) {
    return 0;
  }
  return a[index] + sum(a, index + 1);
}

int main() {
  printf("RECURSION:\n");
  std::vector<int> n;
  int i = 1;
  while (i < NUMBER) {
    n.insert(n.begin(), i);
    i++;
  }
  auto start = std::chrono::high_resolution_clock::now();

  // Здесь сама функция
  long sumV = sum(n);

  auto end = std::chrono::high_resolution_clock::now();
  struct rusage usage;
  if (getrusage(RUSAGE_SELF, &usage) == 0) {
    std::cout << "Peak Memory: " << usage.ru_maxrss / 1024 << " KB"
              << std::endl;
  }
  std::cout << "Sum " << "is " << sumV << "\n";
  std::chrono::duration<double, std::milli> duration_ms = end - start;
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds\n";
  return 0;
}