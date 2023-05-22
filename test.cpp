#include <iostream>
#include "RingBuffer.hpp"

int main() {
  RingBuffer<int, 3> rb;
  for (int i = 0; i < 10; ++i) {
    std::cout << "---------------" << std::endl;
    rb.push_back(i);
    std::cout << rb.back(0) << std::endl;
    std::cout << "size: " << rb.size() << std::endl;

    for (int j = 0; j < rb.size(); ++j) {
      std::cout << rb.index(j) << " ";
    }
    std::cout << std::endl << (rb.full() ? "full" : "not full");
    std::cout << std::endl << "---------------" << std::endl;
  }

  return 0;
}