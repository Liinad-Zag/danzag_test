#include <iostream>

int main() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int* ptr = arr;
  ptr += 3;
  std::cout << "Fourth element of the array: " << *ptr << std::endl;
  return 0;
}
