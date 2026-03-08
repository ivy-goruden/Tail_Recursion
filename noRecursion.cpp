#include "main.h"
using namespace std;

int main() {
  printf("NO RECURSION:\n");
  std::vector<int> n;
  int i = 1;
  while (i < NUMBER) {
    n.insert(n.begin(), i);
    i++;
  }
  auto start = std::chrono::high_resolution_clock::now();

  // Здесь сама функция
  long sum = 0;
  for (const auto &val : n) {
    sum += val;
  }

  auto end = std::chrono::high_resolution_clock::now();

  struct rusage usage;
  if (getrusage(RUSAGE_SELF, &usage) == 0) {
    std::cout << "Peak Memory: " << usage.ru_maxrss / 1024 << " KB"
              << std::endl;
  }
  std::cout << "Sum " << "is " << sum << "\n";

  std::chrono::duration<double, std::milli> duration_ms = end - start;
  std::cout << "Execution time: " << duration_ms.count() << " milliseconds\n";
  return 0;
}