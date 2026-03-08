#include "main.h"
using namespace std;

long sum(std::vector<int> &a, int index = 0, long result = 0) {
  if (a.size() == index) {
    return result;
  }
  return sum(a, index + 1, result + a[index]);
}

int main() {
  printf("TAIL RECURSION:\n");
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