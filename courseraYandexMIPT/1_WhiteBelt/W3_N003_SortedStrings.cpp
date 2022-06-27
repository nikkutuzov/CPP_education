/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Tittle: Sorted strings                                                        */
/*  Start_time: 27.06.2022 10:58                                                  */
/*  End_time: 27.06.2022 11:11                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Реализуйте класс, поддерживающий набор строк в отсортированном порядке. Класс
 * должен содержать два публичных метода:
 *
 * class SortedStrings {
 * public:
 *  void AddString(const string& s) {
 *    // добавить строку s в набор
 *  }
 *  vector<string> GetSortedStrings() {
 *    // получить набор из всех добавленных строк в отсортированном порядке
 *  }
 * private:
 *  // приватные поля
 * };
 *
 * Пример
 *
 * Код
 *
 * void PrintSortedStrings(SortedStrings& strings) {
 *  for (const string& s : strings.GetSortedStrings()) {
 *  cout << s << " ";
 *  }
 *  cout << endl;
 * }
 *
 * int main() {
 *  SortedStrings strings;
 *
 *  strings.AddString("first");
 *  strings.AddString("third");
 *  strings.AddString("second");
 *  PrintSortedStrings(strings);
 *
 *  strings.AddString("second");
 *  PrintSortedStrings(strings);
 *
 *  return 0;
 * }
 *
 * Вывод
 *
 * first second third
 * first second second third
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class SortedStrings {
public:
  void AddString(const std::string& s) {
    strings.push_back(s);
  }
  std::vector<std::string> GetSortedStrings() {
    std::sort(begin(strings), end(strings));
    return strings;
  }

private:
  std::vector<std::string> strings;
};

void PrintSortedStrings(SortedStrings& strings) {
  for (const std::string& s : strings.GetSortedStrings()) {
    std::cout << s << " ";
  }
  std::cout << std::endl;
}

/*<-------------------------------------main------------------------------------->*/

int main() {
  SortedStrings strings;

  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  PrintSortedStrings(strings);

  strings.AddString("second");
  PrintSortedStrings(strings);

  return 0;
}
