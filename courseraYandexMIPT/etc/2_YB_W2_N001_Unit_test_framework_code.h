/*================================================================================*/
/*                           Unit test framework code                             */
/*================================================================================*/

/* ***HOW TO USE***
 *
 * #include "test_runner.h"
 *
 * void TestWorks() {
 *   AssertEqual(1, 1, "Just to check that Assert works");
 * }
 *
 * int main() {
 *   TestRunner tr;
 *   tr.RunTest(TestWorks, "TestWorks");
 *  
 *   return 0;
 * }
 *
 */

#pragma once // included only once

#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <exception>

/*<-----------------------declaration_of_funcs_and_classes----------------------->*/

template <class T>
std::ostream& operator << (std::ostream& os, const std::set<T>& s);

template <class K, class V>
std::ostream& operator << (std::ostream& os, const std::map<K, V>& m);

template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint);

inline void Assert(bool b, const std::string& hint);

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const std::string& test_name);

  ~TestRunner();

private:
  int fail_count = 0;
};

/*<----------------------------operators_overloading----------------------------->*/

template <class T>
std::ostream& operator << (std::ostream& os, const std::set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) { os << ", "; }
    first = false;
    os << x;
  }

  return os << "}";
}

template <class K, class V>
std::ostream& operator << (std::ostream& os, const std::map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& [key, value] : m) {
    if (!key) { os << ", "; }
    first = false;
    os << key << ": " << value;
  }

  return os << "}";
}

/*<-----------------------definition_of_funcs_and_classes------------------------>*/

template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint)
{
  if (t != u) {
    std::ostringstream os;
    os << "Assertion failed: " << t << " != " << u << " hint: " << hint;
    throw std::runtime_error(os.str());
  }
}

inline void Assert(bool b, const std::string& hint) { AssertEqual(b, true, hint); }

template <class TestFunc>
void TestRunner::RunTest(TestFunc func, const std::string& test_name) {
  try {
  func();
  std::cerr << test_name << " OK" << std::endl;
  } catch (std::runtime_error& e) {
  ++fail_count;
  std::cerr << test_name << " fail: " << e.what() << std::endl;
  }
}

TestRunner::~TestRunner() {
  if (fail_count > 0) {
    std::cerr << fail_count << " unit tests failed. Terminate" << std::endl;
    exit(1);
  }
}
