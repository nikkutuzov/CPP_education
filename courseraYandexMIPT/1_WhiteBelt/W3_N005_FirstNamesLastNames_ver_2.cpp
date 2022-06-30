/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Tittle: First names, last names ver. 2                                        */
/*  Start_time: 28.06.2022 15:44                                                  */
/*  End_time: 30.06.2022 14:13                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Дополните класс из предыдущей задачи «Имена и фамилии — 1» методом
 * GetFullNameWithHistory:
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
 *  string GetFullNameWithHistory(int year) {
 *    // получить все имена и фамилии по состоянию на конец года year
 *  }
 * private:
 *  // приватные поля
 * };
 *
 * В отличие от метода GetFullName, метод GetFullNameWithHistory должен вернуть не
 * только последние имя и фамилию к концу данного года, но ещё и все предыдущие
 * имена и фамилии в обратном хронологическом порядке. Если текущие факты говорят о
 * том, что человек два раза подряд изменил фамилию или имя на одно и то же, второе
 * изменение при формировании истории нужно игнорировать.
 *
 * Для лучшего понимания формата см. примеры.
 *
 * Пример 1
 *
 * Код
 *
 * int main() {
 *  Person person;
 *
 *  person.ChangeFirstName(1900, "Eugene");
 *  person.ChangeLastName(1900, "Sokolov");
 *  person.ChangeLastName(1910, "Sokolov");
 *  person.ChangeFirstName(1920, "Evgeny");
 *  person.ChangeLastName(1930, "Sokolov");
 *  cout << person.GetFullNameWithHistory(1940) << endl;
 *
 *  return 0;
 * }
 *
 * Вывод
 *
 * Evgeny (Eugene) Sokolov
 *
 * Пример 2
 *
 * Код
 *
 * int main() {
 *  Person person;
 *
 *  person.ChangeFirstName(1965, "Polina");
 *  person.ChangeLastName(1967, "Sergeeva");
 *  for (int year : {1900, 1965, 1990}) {
 *    cout << person.GetFullNameWithHistory(year) << endl;
 *  }
 *
 *  person.ChangeFirstName(1970, "Appolinaria");
 *  for (int year : {1969, 1970}) {
 *    cout << person.GetFullNameWithHistory(year) << endl;
 *  }
 *
 *  person.ChangeLastName(1968, "Volkova");
 *  for (int year : {1969, 1970}) {
 *    cout << person.GetFullNameWithHistory(year) << endl;
 *  }
 *
 *  person.ChangeFirstName(1990, "Polina");
 *  person.ChangeLastName(1990, "Volkova-Sergeeva");
 *  cout << person.GetFullNameWithHistory(1990) << endl;
 *
 *  person.ChangeFirstName(1966, "Pauline");
 *  cout << person.GetFullNameWithHistory(1966) << endl;
 *
 *  person.ChangeLastName(1960, "Sergeeva");
 *  for (int year : {1960, 1967}) {
 *    cout << person.GetFullNameWithHistory(year) << endl;
 *  }
 *
 *  person.ChangeLastName(1961, "Ivanova");
 *  cout << person.GetFullNameWithHistory(1967) << endl;
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
 * Appolinaria (Polina) Sergeeva
 * Polina Volkova (Sergeeva)
 * Appolinaria (Polina) Volkova (Sergeeva)
 * Polina (Appolinaria, Polina) Volkova-Sergeeva (Volkova, Sergeeva)
 * Pauline (Polina) with unknown last name
 * Sergeeva with unknown first name
 * Pauline (Polina) Sergeeva
 * Pauline (Polina) Sergeeva (Ivanova, Sergeeva)
 *
 * Пример 3
 *
 * Код
 *
 * int main() {
 *   Person person;
 *
 *   person.ChangeFirstName(1965, "Polina");
 *   person.ChangeFirstName(1965, "Appolinaria");
 *
 *   person.ChangeLastName(1965, "Sergeeva");
 *   person.ChangeLastName(1965, "Volkova");
 *   person.ChangeLastName(1965, "Volkova-Sergeeva");
 *
 *   for (int year : {1964, 1965, 1966}) {
 *     cout << person.GetFullNameWithHistory(year) << endl;
 *   }
 *
 * return 0;
 * }
 *
 * Вывод
 *
 * Incognito
 * Appolinaria Volkova-Sergeeva
 * Appolinaria Volkova-Sergeeva
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

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

std::vector<std::string> GetNamesWithHistory(int year,
                                            std::map<int, std::string>& yearNames) {
  std::vector<std::string> result;

  for (const auto& [key, value] : yearNames) {
    if (key <= year and (result.empty() or result.back() != value)) {
        result.push_back(value);
    }
  }

  return result;
}

std::string PartOfFullNameWithHistory(std::vector<std::string> names) {
  std::string result = "";

  if (names.empty()) {
    return result;
  }

  std::reverse(begin(names), end(names));

  result += names[0];

  for (int i = 1; i < names.size(); ++i) {
    if (i == 1) {
      result += " (";
    } else {
      result += ", ";
    }
    result += names[i];
  }

  if (names.size() > 1) {
    result += ")";
  }

    return result;
}

std::string FullName(const std::string& first_name,
                        const std::string& last_name) {
    if (first_name.empty() and last_name.empty()) {
      return "Incognito";
    } else if (first_name.empty()) {
      return last_name + " with unknown first name";
    } else if (last_name.empty()) {
      return first_name + " with unknown last name";
    } else {
      return first_name + " " + last_name;
    }
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

    return FullName(findedFirstName, findedLastName);
  }

  std::string GetFullNameWithHistory(int year) {
    const std::string first_name_with_history =
      PartOfFullNameWithHistory(GetNamesWithHistory(year, yearFirstName));
    const std::string last_name_with_history =
      PartOfFullNameWithHistory(GetNamesWithHistory(year, yearLastName));

    return FullName(first_name_with_history, last_name_with_history);
  }

private:
  std::map<int, std::string> yearFirstName;
  std::map<int, std::string> yearLastName;
};

/*<-------------------------------------main------------------------------------->*/

int main() {

  /*<---------------------------------example_1---------------------------------->*/

  /*
  Person person;

  person.ChangeFirstName(1900, "Eugene");
  person.ChangeLastName(1900, "Sokolov");
  person.ChangeLastName(1910, "Sokolov");
  person.ChangeFirstName(1920, "Evgeny");
  person.ChangeLastName(1930, "Sokolov");
  std::cout << person.GetFullNameWithHistory(1940) << std::endl;
  */

  /*<--------------------------------example_2------------------------------------>*/

  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  std::cout << person.GetFullNameWithHistory(1990) << std::endl;

  person.ChangeFirstName(1966, "Pauline");
  std::cout << person.GetFullNameWithHistory(1966) << std::endl;

  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeLastName(1961, "Ivanova");
  std::cout << person.GetFullNameWithHistory(1967) << std::endl;

  /*<--------------------------------example_3------------------------------------>*/

  /*
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeFirstName(1965, "Appolinaria");

  person.ChangeLastName(1965, "Sergeeva");
  person.ChangeLastName(1965, "Volkova");
  person.ChangeLastName(1965, "Volkova-Sergeeva");

  for (int year : {1964, 1965, 1966}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }
  */

  return 0;
}
