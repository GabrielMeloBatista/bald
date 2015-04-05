#include <iostream>
#include <iomanip>
#include <vector>
#include <chrono>

namespace bald {

#define STRINGIFY2(x) (#x)
#define STRINGIFY(x) STRINGIFY2(x)
#define ASSERT(check) do { if (!(check)) { throw bald::test_failure { __FILE__, STRINGIFY(__LINE__), #check }; } } while(0)

struct test_failure { const char *file, *line, *check; };

class test_module {
  public:
    test_module(const std::string& name)
      : passed_(0), failed_(0)
    {
      std::cout << "[====] Testing module: " << name << std::endl;
      start_ = hrc::now();
    }

    ~test_module() {
      std::cout << "\nRan " << (passed_ + failed_) << " tests in ";
      std::cout << std::fixed << std::setprecision(3) <<
        std::chrono::duration_cast<ms>(hrc::now() - start_).count() / 1000.0 << "s ";
      std::cout << "(" << passed_ << " passed, " << failed_ << " failed)" << std::endl;
    }

    template <class F>
    void operator()(const std::string& desc, const F &func) {
      try {
        func();
        std::cout << "[PASS] " << desc << std::endl;
        passed_++;
      } catch (test_failure f) {
        std::cout << "[FAIL] " << desc << std::endl;
        std::cout << "   " << f.file << ":" << f.line << ": ASSERT(" << f.check << ")" << std::endl;
        failed_++;
      }
    }

  private:
    typedef std::chrono::high_resolution_clock hrc;
    typedef std::chrono::milliseconds ms;

    unsigned passed_, failed_;
    hrc::time_point start_;
};

}
