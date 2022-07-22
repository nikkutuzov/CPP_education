/*================================================================================*/
/*                    C++_Development_Basics: The_Yellow_Belt                     */
/*================================================================================*/
/*  Title: Tests for func IsPalindrome                                            */
/*  Start_time: 22.07.2022 10:34                                                  */
/*  End_time: 22.07.2022 11:04                                                    */
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
 * https://github.com/nikkutuzov/CPP_education/blob/master/courseraYandexMIPT/Templates/2_YB_W2_N005_IsPalindrome/test_palindrome.cpp
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

bool IsPalindrome(const std::string& str) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
}

void TestIsPalindrome(){
  std::string str="";
  {
    // Пустая строка - палиндром
    Assert(IsPalindrome(str), str + " Empty string is palindrome");
    // Строка из одного символа - палиндром
    str = "a";
    Assert(IsPalindrome(str), str + " One char string is palindrome");
    str = "1";
    Assert(IsPalindrome(str), str + " One char string is palindrome");
    str = "!";
    Assert(IsPalindrome(str), str + " One char string is palindrome");
    str = "ABBA";
    Assert(IsPalindrome(str), str + " Uppercase");
    str = " ";
    Assert(IsPalindrome(str), str + " One white-space string is palindrome");
    str = "ABcBA";
    Assert(IsPalindrome(str), str + " Odd numbers of chars");
    str = "####";
    Assert(IsPalindrome(str), str + " Even numbers of chars");
    // Палиндром из цифр
    str = "12345678987654321";
    Assert(IsPalindrome(str), "String " + str + "is numeric palindrome");
    // Палиндром из пунктуационных знаков
    str = "!@#$%^&*()_++_)(*&^%$#@!";
    Assert(IsPalindrome(str), "String " + str + " is symbols palindrome");

    str = "-madam-";
    Assert(IsPalindrome(str), "String" + str + " is a palindrome.");

    str = "|m a d a m|";
    Assert(IsPalindrome(str), "String" + str + " is a palindrome.");

    str = "\" \"";
    Assert(IsPalindrome(str), "String" + str + " is a palindrome.");

    str = "\tab\nba\t";
    Assert(IsPalindrome(str), "String" + str + " is a palindrome.");
  }
}

void TestIsNotPalindrome(){
  std::string str;
  // Игнорирование символов
  str = "a ba";
  Assert(!IsPalindrome(str), "String " + str +
         " is not a palindrome. Ignore symbol int the middle of string");
  str = " aba";
  Assert(!IsPalindrome(str), "String " + str +
         " is not a palindrome. Ignore symbol in the start of  string");
  str = "aba!";
  Assert(!IsPalindrome(str), "String" + str +
         " is not a palindrome. Ignore ! in the end of string");
  str = " m  ada m   ";
  Assert(!IsPalindrome(str), "String" + str +
      " is not a palindrome. Skipping white-space characters");

  // Сравнение завершается на середине строки
  str = "ABc ab cBA";
  Assert(!IsPalindrome(str), "String " + str +
         " is not a palindrome. Did not compare symbol in the middle of string");
  str = "AbcBa";
  Assert(!IsPalindrome(str), "String " + str +
         " is not a palindrome. Case sensetive");
  str = "\tabba ";
  Assert(!IsPalindrome(str), "String " + str +
         " is not a palindrome. Tab in the start");
  str = " abba\t";
  Assert(!IsPalindrome(str), "String " + str +
         " is not a palindrome. Tab in the end");
  str = "ab\t ba";
  Assert(!IsPalindrome(str), "String " + str +
         " is not a palindrome. Tab in the middle");
  str = "\nabcba";
  Assert(!IsPalindrome(str), "String " + str +
         " is not a palindrome. \n in the start");
}

/*<-------------------------------------main------------------------------------->*/

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestIsPalindrome, "TestIsPalindrome");
  runner.RunTest(TestIsNotPalindrome, "TestIsNotPalindrome");

  return 0;
}
