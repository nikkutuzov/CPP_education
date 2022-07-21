/*================================================================================*/
/*                    C++_Development_Basics: The_Yellow_Belt                     */
/*================================================================================*/
/*  Title: Tests for class Person                                                 */
/*  Start_time: 21.07.2022 22:53                                                  */
/*  End_time:   ----------------                                                  */
/*  Note: Author's solution                                                       */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * В первом курсе "Белый пояс по С++" у нас была задача "Имена и фамилии - 1". В ней
 * надо было разработать класс Person, поддерживающий историю изменений человеком
 * своих фамилии и имени.
 * В данной задаче вам надо разработать юнит-тесты на реализацию класса Person.
 * При разработке тестов учитывайте ограничения, которые накладывает на класс Person
 * условие задачи "Имена и фамилии - 1".
 *
 * Начать работу вы можете с шаблона, который содержит наш фреймворк юнит-тестов и
 * заготовку класса.
 *
 * https://github.com/nikkutuzov/CPP_education/blob/master/courseraYandexMIPT/Templates/2_YB_W2_N003_Person/test_person.cpp
 *
 * Условие задачи "Имена и фамилии - 1"
 *
 * Реализуйте класс для человека, поддерживающий историю изменений человеком своих
 * фамилии и имени.
 *
 * class Person {
 * public:
 *   void ChangeFirstName(int year, const string& first_name) {
 *     // добавить факт изменения имени на first_name в год year
 *   }
 *   void ChangeLastName(int year, const string& last_name) {
 *     // добавить факт изменения фамилии на last_name в год year
 *   }
 *   string GetFullName(int year) {
 *     // получить имя и фамилию по состоянию на конец года year
 *   }
 * private:
 *   // приватные поля
 * };
 *
 * Считайте, что в каждый год может произойти не более одного изменения фамилии и не
 * более одного изменения имени. При этом с течением времени могут открываться всё
 * новые факты из прошлого человека, поэтому года́ в последовательных вызовах методов
 * ChangeLastName и ChangeFirstName не обязаны возрастать.
 *
 * Гарантируется, что все имена и фамилии непусты.
 *
 * Строка, возвращаемая методом GetFullName, должна содержать разделённые одним
 * пробелом имя и фамилию человека по состоянию на конец данного года.
 *
 * - Если к данному году не случилось ни одного изменения фамилии и имени, верните
 *   строку "Incognito".
 * - Если к данному году случилось изменение фамилии, но не было ни одного изменения
 *   имени, верните "last_name with unknown first name".
 * - Если к данному году случилось изменение имени, но не было ни одного изменения
 *   фамилии, верните "first_name with unknown last name".
 *
 * Примечание
 *
 * Перед отправкой вашего файла убедитесь, что он не содержит класса Person.
 * В противном случае вы получите ошибку компиляции. Наша тестирующая система умеет
 * игнорировать функции в файлах (поэтому, например, в задаче "Тесты для функции
 * IsPalindrom" необязательно удалять функцию IsPalindrom), но не умеет это делать
 * для классов.
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


class Person {
public:
  // Вы можете вставлять сюда различные реализации класса,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  void ChangeFirstName(int year, const std::string& first_name) {
  }
  void ChangeLastName(int year, const std::string& last_name) {
  }
  std::string GetFullName(int year) {
  }
};

void TestPredefinedLastNameFirst() {
    Person person;

    person.ChangeLastName(1965, "Sergeeva");
    person.ChangeFirstName(1967, "Polina");

    AssertEqual(person.GetFullName(1964), "Incognito");
    AssertEqual(person.GetFullName(1966), "Sergeeva with unknown first name");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");
}

void TestPredefined() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");

    AssertEqual(person.GetFullName(1964), "Incognito");
    AssertEqual(person.GetFullName(1966), "Polina with unknown last name");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");

    person.ChangeFirstName(1969, "Appolinaria");
    AssertEqual(person.GetFullName(1968), "Polina Sergeeva");
    AssertEqual(person.GetFullName(1969), "Appolinaria Sergeeva");
    AssertEqual(person.GetFullName(1970), "Appolinaria Sergeeva");

    person.ChangeLastName(1968, "Volkova");
    AssertEqual(person.GetFullName(1967), "Polina Sergeeva");
    AssertEqual(person.GetFullName(1968), "Polina Volkova");
    AssertEqual(person.GetFullName(1969), "Appolinaria Volkova");

}

/*<-------------------------------------main------------------------------------->*/

int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  runner.RunTest(TestPredefined, "TestPredefined");
  runner.RunTest(TestPredefinedLastNameFirst, "TestPredefinedLastNameFirst");

  return 0;
}
