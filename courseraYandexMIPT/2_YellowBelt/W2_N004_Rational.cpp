/*================================================================================*/
/*                    C++_Development_Basics: The_Yellow_Belt                     */
/*================================================================================*/
/*  Title: Tests for class Rational                                               */
/*  Start_time: 21.07.2022 23:25                                                  */
/*  End_time: 22.07.2022 10:28                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Класс Rational представляет собой рациональное число и имеет следующий интерфейс:
 * class Rational {
 * public:
 *   Rational();
 *   Rational(int numerator, int denominator);
 *
 *   int Numerator() const;
 *   int Denominator() const;
 * };
 *
 * Список требований, предъявляемых к реализации интерфейса класса Rational:
 *
 * 1. Конструктор по умолчанию должен создавать дробь с
 *    числителем 0 и знаменателем 1.
 * 2. При конструировании объекта класса Rational с параметрами p и q должно
 *    выполняться сокращение дроби p/q.
 * 3. Если дробь p/q отрицательная, то объект Rational(p, q) должен иметь
 *    отрицательный числитель и положительный знаменатель.
 * 4. Если дробь p/q положительная, то объект Rational(p, q) должен иметь
 *    положительные числитель и знаменатель (обратите внимание на
 *    случай Rational(-2, -3)).
 * 5. Если числитель дроби равен нулю, то знаменатель должен быть равен 1.
 *
 * Разработайте набор юнит-тестов, которые будут проверять корректность
 * реализации класса Rational. Тестировать случай, когда знаменатель
 * равен нулю, не надо.
 *
 * Начать работу вы можете с шаблона, который содержит наш фреймворк
 * юнит-тестов и заготовку класса Rational.
 *
 * https://github.com/nikkutuzov/CPP_education/blob/master/courseraYandexMIPT/Templates/2_YB_W2_N004_Rational/test_rational.cpp
 *
 * Примечание
 *
 * Перед отправкой вашего файла убедитесь, что он не содержит класса Rational.
 * В противном случае вы получите ошибку компиляции. Наша тестирующая система
 * умеет игнорировать функции в файлах (поэтому, например, в задаче "Тесты для
 * функции IsPalindrom" необязательно удалять функцию IsPalindrom), но не умеет
 * это делать для классов.
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

class Rational {
public:
  // Вы можете вставлять сюда различные реализации,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный

  Rational();
  Rational(int numerator, int denominator) {
  }

  int Numerator() const {
  }

  int Denominator() const {
  }
};

// Равно
bool operator== (const Rational& lhs, const Rational& rhs){
  return lhs.Numerator() == rhs.Numerator() and
         lhs.Denominator() == rhs.Denominator();
}
// Не равно
bool operator!= (const Rational& lhs, const Rational& rhs){
  return !(lhs == rhs);
}
// Вывод в поток
std::ostream& operator<< (std::ostream& os, const Rational& rational){
    os << rational.Numerator() << "/" << rational.Denominator();
    return os;
}

void TestCreateRational(){
  std::string test_name = "Test create object: ";

  {
    // По умолчанию числитель равен 0, знаменатель равен 1
    Rational r, r_expected(0, 1);
    AssertEqual(r, r_expected, "Test default constructor");
  }

  {
    // Сокращение дроби при создании
    Rational r(2,4), r_experted(1, 2);
    AssertEqual(r, r_experted, "Reduce after create. Positive");

    r = Rational(-3, 6);
    r_experted = Rational(-1, 2);
    AssertEqual(r, r_experted, "Reduce after create. Negative");

    r = Rational(4, 2);
    r_experted = Rational(2, 1);
    AssertEqual(r, r_experted, "Reduce after create. Denomitator < Numerator");

  }

  {
    // Отрицательные дроби
    Rational r(3, -5), r_expected(-3, 5);
    AssertEqual(r, r_expected, "Negative rational");
  }

  {
    // Положительные дроби
    Rational r(-2, -5), r_expected(2, 5);
    AssertEqual(r, r_expected, "Positive rational");
  }

  {
    // Нулевой числитель
    Rational r(0, 43), r_expected(0, 1);
    AssertEqual(r, r_expected, "Numerator = 0, denominator > 0");
    r = Rational(0, -43);
    AssertEqual(r, r_expected, "Numerator = 0, denominator < 0");
  }
}

/*<-------------------------------------main------------------------------------->*/

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestCreateRational, "TestCreateRational");

  return 0;
}
