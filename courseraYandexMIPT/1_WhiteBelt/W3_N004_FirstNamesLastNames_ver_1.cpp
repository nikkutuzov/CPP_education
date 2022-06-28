/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Tittle: First names, last names                                               */
/*  Start_time: 27.06.2022 11:14                                                  */
/*  End_time: 28.06.2022 15:42                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Реализуйте класс для человека, поддерживающий историю изменений человеком своих
 * фамилии и имени.
 *
 * class Person {
 * public:
 *  void ChangeFirstName(int year, const string& first_name) {
 *    // добавить факт изменения имени на first_name в год year
 *  }
 *  void ChangeLastName(int year, const string& last_name) {
 *    // добавить факт изменения фамилии на last_name в год year
 *  }
 *  string GetFullName(int year) {
 *    // получить имя и фамилию по состоянию на конец года year
 *  }
 * private:
 *  // приватные поля
 * };
 *
 * Считайте, что в каждый год может произойти не более одного изменения фамилии и не
 * более одного изменения имени. При этом с течением времени могут открываться всё
 * новые факты из прошлого человека, поэтому годА в последовательных вызовах методов
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
 * Пример
 *
 * Код
 *
 * int main() {
 *  Person person;
 *
 *  person.ChangeFirstName(1965, "Polina");
 *  person.ChangeLastName(1967, "Sergeeva");
 *  for (int year : {1900, 1965, 1990}) {
 *    cout << person.GetFullName(year) << endl;
 *  }
 *
 *  person.ChangeFirstName(1970, "Appolinaria");
 *  for (int year : {1969, 1970}) {
 *    cout << person.GetFullName(year) << endl;
 *  }
 *
 *  person.ChangeLastName(1968, "Volkova");
 *  for (int year : {1969, 1970}) {
 *    cout << person.GetFullName(year) << endl;
 *  }
 *
 * return 0;
 * }
 *
 * Вывод
 *
 * Incognito
 * Polina with unknown last name
 * Polina Sergeeva
 * Polina Sergeeva
 * Appolinaria Sergeeva
 * Polina Volkova
 * Appolinaria Volkova
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <map>

std::string findName(const std::map<int, std::string>& yearName, const int& year) {
  std::string result = "";
  for (const auto [key, value] : yearName) {
    if (key <= year) {
      result = value;
    } else {
      break;
    }
  }
  return result;
}

class Person {
public:
  void ChangeFirstName(int year, const std::string& first_name) {
    yearFirstName[year] = first_name;
  }
  void ChangeLastName(int year, const std::string& last_name) {
    yearLastName[year] = last_name;
  }
  std::string GetFullName(int year) {
    const std::string findedFirstName = findName(yearFirstName, year);
    const std::string findedLastName = findName(yearLastName, year);
    if (findedFirstName.empty() and findedLastName.empty()) {
      return "Incognito";
    } else if (findedFirstName.empty()) {
      return findedLastName + " with unknown first name";
    } else if (findedLastName.empty()) {
      return findedFirstName + " with unknown last name";
    } else {
      return findedFirstName + " " + findedLastName;
    }
  }

private:
  std::map<int, std::string> yearFirstName;
  std::map<int, std::string> yearLastName;
};

/*<-------------------------------------main------------------------------------->*/

int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    std::cout << person.GetFullName(year) << std::endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullName(year) << std::endl;
  }

  return 0;
}
