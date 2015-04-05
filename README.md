# bald
Bald is a quick & dirty C++11 test harness in one header file. No fancy stuff.

# How to Use
1. Include bald.h in your testing file.
2. Create a `bald::test_module`.
3. Run tests using lambda expressions.

# Example Code
```cpp
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
```

# Example Output
```
$ g++ -std=c++11 example.cpp && ./a.out
[====] Testing module: Vector
[PASS] initial size is zero
[PASS] reserve changes capacity but not size
[FAIL] initializer list creates 100 element vector
   example.cpp:20: ASSERT(v.size() == 100)

Ran 3 tests in 0.000s (2 passed, 1 failed)

```
