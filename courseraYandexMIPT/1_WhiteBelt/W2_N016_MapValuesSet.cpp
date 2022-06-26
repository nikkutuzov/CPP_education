/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Tittle: Map values set                                                        */
/*  Start_time: 26.06.2022 12:57                                                  */
/*  End_time: 26.06.2022 13:06                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Напишите функцию BuildMapValuesSet, принимающую на вход словарь map<int, string>
 * и возвращающую множество значений этого словаря:
 *
 * set<string> BuildMapValuesSet(const map<int, string>& m) {
 *  // ...
 * }
 *
 * Пример
 *
 * Код
 *
 * set<string> values = BuildMapValuesSet({
 *  {1, "odd"},
 *  {2, "even"},
 *  {3, "odd"},
 *  {4, "even"},
 *  {5, "odd"}
 * });
 *
 * for (const string& value : values) {
 *  cout << value << endl;
 * }
 *
 * Вывод
 *
 * even
 * odd
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <map>
#include <set>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m) {
  std::set<std::string> result;
  for (const auto& [key, value] : m) {
    result.insert(value);
  }

  return result;
}

/*<-------------------------------------main------------------------------------->*/

int main() {
  std::set<std::string> values = BuildMapValuesSet({
    {1, "odd"},
    {2, "even"},
    {3, "odd"},
    {4, "even"},
    {5, "odd"}
  });

  for (const std::string& value : values) {
    std::cout << value << std::endl;
  }

  return 0;
}
