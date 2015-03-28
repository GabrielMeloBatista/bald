# bald
Bald is a quick & dirty C++ test harness in one header file. No fancy stuff.

# How to Use
1. Include bald.h in your testing file.
2. Declare your tests using the `TEST` macro.
2. Call `bald::run()` in `main`.

# Example
```cpp
#include "bald.h"

TEST(Test1, "Does maths work?") {
  ASSERT(3 * 9 == 27);
}

TEST(Test2, "This is a 64 bit system") {
  ASSERT(sizeof(void *) == 8);
}

TEST(Test3, "This test fails") {
  ASSERT(false);
}

int main() {
  bald::run();
}
```

# Example Output
```
Running tests...
[FAIL] This test fails
   example.cpp:12: ASSERT(false)
[PASS] This is a 64 bit system
[PASS] Does maths work?

[1/3] tests failed.
```
