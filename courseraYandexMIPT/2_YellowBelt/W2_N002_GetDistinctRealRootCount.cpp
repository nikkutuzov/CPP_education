/*================================================================================*/
/*                    C++_Development_Basics: The_Yellow_Belt                     */
/*================================================================================*/
/*  Title: Tests for func GetDistinctRealRootCount                                */
/*  Start_time: 21.07.2022 20:31                                                  */
/*  End_time:                                                                     */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Функция:
 *
 * int GetDistinctRealRootCount(double a, double b, double c);
 *
 * возвращает количество уникальных действительных корней уравнения ax² + bx + c = 0
 * Разработайте набор юнит-тестов для проверки корректности реализации этой функции.
 * Случай, когда все три коэффициента равны нулю, тестировать не надо.
 *
 * Начать работу вы можете с шаблона, который содержит наш фреймворк юнит-тест и
 * заготовку функции GetDistinctRealRootCount.
 *
 * https://github.com/nikkutuzov/CPP_education/blob/master/courseraYandexMIPT/Templates/2_YB_W2_N002_GetDistinctRealRootCount/test_equation.cpp
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

template <class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }

  return os << "}";
}

template <class T>
std::ostream& operator << (std::ostream& os, const std::set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
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
    if (!first) {
      os << ", ";
    }
    first = false;
    os << key << ": " << value;
  }

  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const std::string& hint = {}) {
  if (t != u) {
    std::ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw std::runtime_error(os.str());
  }
}

void Assert(bool b, const std::string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const std::string& test_name) {
    try {
      func();
      std::cerr << test_name << " OK" << std::endl;
    } catch (std::exception& e) {
      ++fail_count;
      std::cerr << test_name << " fail: " << e.what() << std::endl;
    } catch (...) {
      ++fail_count;
      std::cerr << "Unknown exception caught" << std::endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      std::cerr << fail_count << " unit tests failed. Terminate" << std::endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

int GetDistinctRealRootCount(double a, double b, double c) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
}

/*<-------------------------------------main------------------------------------->*/

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты

  return 0;
}
