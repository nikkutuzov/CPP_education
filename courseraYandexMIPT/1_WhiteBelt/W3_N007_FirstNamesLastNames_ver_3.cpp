/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Tittle: First names, last names ver. 3                                        */
/*  Start_time: 30.06.2022 14:37                                                  */
/*  End_time:                                                                     */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Дополните класс Person из задачи «Имена и фамилии - 2» конструктором, позволяющим
 * задать имя и фамилию человека при рождении, а также сам год рождения.
 * Класс НЕ должен иметь конструктора по умолчанию.
 *
 * При получении на вход года, который меньше года рождения:
 *
 * - методы GetFullName и GetFullNameWithHistory должны отдавать "No person";
 * - методы ChangeFirstName и ChangeLastName должны игнорировать запрос.
 * Кроме того, необходимо объявить константными все методы, которые по сути ими
 * являются.
 *
 * Пример
 *
 * Код
 *
 * int main() {
 *  Person person("Polina", "Sergeeva", 1960);
 *  for (int year : {1959, 1960}) {
 *    cout << person.GetFullNameWithHistory(year) << endl;
 *  }
 *
 *  person.ChangeFirstName(1965, "Appolinaria");
 *  person.ChangeLastName(1967, "Ivanova");
 *  for (int year : {1965, 1967}) {
 *    cout << person.GetFullNameWithHistory(year) << endl;
 *  }
 *
 * return 0
 * }
 *
 * Вывод
 *
 * No person
 * Polina Sergeeva
 * Appolinaria (Polina) Sergeeva
 * Appolinaria (Polina) Ivanova (Sergeeva)
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

std::vector<std::string> GetNamesWithHistory(const int year,
                                      const std::map<int, std::string>& yearNames) {
  std::vector<std::string> result;

  for (const auto& [key, value] : yearNames) {
    if (key <= year and (result.empty() or result.back() != value)) {
        result.push_back(value);
    }
  }

  return result;
}

std::string PartOfFullNameWithHistory(const std::vector<std::string>& v) {
  std::vector<std::string> names = v;
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
  Person(const std::string& new_first_name, const std::string& new_last_name,
          const int new_year) {
    birth_year = new_year;
    yearFirstName[birth_year] = new_first_name;
    yearLastName[birth_year] = new_last_name;
  }

  void ChangeFirstName(int year, const std::string& first_name) {
    yearFirstName[year] = first_name;
  }

  void ChangeLastName(int year, const std::string& last_name) {
    yearLastName[year] = last_name;
  }

  std::string GetFullName(int year) const {
    if (year < birth_year) {
      return "No person";
    }
    const std::string findedFirstName = findName(yearFirstName, year);
    const std::string findedLastName = findName(yearLastName, year);

    return FullName(findedFirstName, findedLastName);
  }

  std::string GetFullNameWithHistory(int year) const {
    if (year < birth_year) {
      return "No person";
    }
  const std::string first_name_with_history =
      PartOfFullNameWithHistory(GetNamesWithHistory(year, yearFirstName));
    const std::string last_name_with_history =
      PartOfFullNameWithHistory(GetNamesWithHistory(year, yearLastName));

    return FullName(first_name_with_history, last_name_with_history);
  }

private:
  int birth_year;
  std::map<int, std::string> yearFirstName;
  std::map<int, std::string> yearLastName;
};

/*<-------------------------------------main------------------------------------->*/

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  return 0;
}
