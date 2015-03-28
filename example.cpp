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
