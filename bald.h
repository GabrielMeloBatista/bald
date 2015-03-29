#include <vector>
#include <cstdio>

#define TEST_CLASS_NAME(name) TestCase_ ## name
#define TEST(name, desc) \
  namespace bald { \
  struct TEST_CLASS_NAME(name) : public TestCase { \
    TEST_CLASS_NAME(name)() : TestCase(#name, desc) { } \
    virtual void runTest(); }; \
  TEST_CLASS_NAME(name) test_ ## name; }\
  void bald::TEST_CLASS_NAME(name)::runTest()

#define ASSERT(cond) if (!(cond)) { pass = false; msg = #cond; file = __FILE__; line = __LINE__; return; }

namespace bald {
struct TestCase;
std::vector<TestCase*> TEST_CASES;

struct TestCase {
  TestCase(const char *name, const char *desc) : name(name), desc(desc), pass(true) {
    TEST_CASES.push_back(this);
  }

  virtual void runTest() = 0;

  const char *name, *desc, *msg, *file;
  int line;
  bool pass;
};

void run() {
  printf("Running tests...\n");

  int failed = 0;
  for (unsigned i = 0; i < TEST_CASES.size(); i++) {
    TEST_CASES[i]->runTest();
    if (TEST_CASES[i]->pass) {
      printf("[PASS] %s\n", TEST_CASES[i]->desc);
    } else {
      printf("[FAIL] %s\n   %s:%d: ASSERT(%s)\n", TEST_CASES[i]->desc, TEST_CASES[i]->file, TEST_CASES[i]->line, TEST_CASES[i]->msg);
      failed++;
    }
  }

  if (failed == 0)
    printf("\nAll tests pass!\n");
  else
    printf("\n[%d/%d] tests failed.\n", failed, (int)TEST_CASES.size());
}
}
