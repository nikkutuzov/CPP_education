/*================================================================================*/
/*                    C++_Development_Basics: The_Yellow_Belt                     */
/*================================================================================*/
/*  Title: Tests for func IsPalindrome                                            */
/*  Start_time: 22.07.2022 10:34                                                  */
/*  End_time:                                                                     */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * В этой задаче вам нужно разработать набор юнит-тестов для функции
 *
 * bool IsPalindrom(const string& s);
 *
 * Эта функция проверяет, является ли строка s палиндромом. Палиндром - это слово
 * или фраза, которые одинаково читаются слева направо и справа налево.
 * Примеры палиндромов: madam, level, wasitacaroracatisaw
 *
 * Разработайте набор юнит-тестов, который будет принимать правильные реализации
 * функции IsPalindrom и отвергать неправильные. При этом учитывайте, что правильная
 * реализация функции:
 *
 * - считает пустую строку палиндромом;
 * - считает строку из одного символа палиндромом;
 * - осуществляет обычное сравнение символов на равенство, не игнорируя никакие
 *   символы, в том числе пробельные.
 *
 * При разработке тестов подумайте, какие ошибки можно допустить при реализации
 * функции IsPalindrom. Примеры ошибок:
 *
 * - игнорируется первый или последний символ;
 * - сравнение соответствующих символов завершается не в середине строки, а раньше;
 * - игнорируются пробелы
 *
 * Начать работу вы можете с шаблона, который содержит наш фреймворк юнит-тестов и
 * заготовку функции IsPalindrom.
 *
 *
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>

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

void Assert(bool b, const std::string& hint) { AssertEqual(b, true, hint); }

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


/*<-------------------------------------main------------------------------------->*/

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты

  return 0;
}
