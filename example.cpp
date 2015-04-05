#include "bald.h"

int main() {
  bald::test_module test_vector("Vector");

  test_vector("initial size is zero", []() {
    std::vector<int> v;
    ASSERT(v.size() == 0);
  });

  test_vector("reserve changes capacity but not size", []() {
    std::vector<int> v;
    v.reserve(100);
    ASSERT(v.capacity() == 100);
    ASSERT(v.size() == 0);
  });

  test_vector("initializer list creates 100 element vector", []() {
    std::vector<int> v {100};
    ASSERT(v.size() == 100);
  });
}
