/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Tittle: Case-insensitive sorting                                              */
/*  Start_time: 26.06.2022 22:20                                                  */
/*  End_time: 26.06.2022 10:35                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Условие
 *
 * В стандартном потоке дана одна строка, состоящая из числа N и следующих за ним
 * N строк S. Между собой число и строки разделены пробелом.
 *
 * Отсортируйте строки S в лексикографическом порядке по возрастанию, игнорируя
 * регистр букв, и выведите их в стандартный поток вывода.
 *
 * Ограничения
 *
 * - 0 <= N <= 1000
 * - 1 <= |S| <= 15
 * - Каждая строка S[i] может состоять из следующих символов: [0-9,a-z,A-Z]
 *
 * Примеры
 *
 *     stdin           stdout
 *     2 qq Aa         Aa qq
 *     3 aA Cc bb      aA bb Cc
 *
 * Подсказка
 *
 * Обратите внимание на функцию tolower:
 * http://www.cplusplus.com/reference/cctype/tolower
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void PrintVector(const std::vector<std::string>& v) {
  for (const std::string& item : v) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

std::string ToLower(const std::string& str) {
  std::string result;
  for (const char& c : str) {
    result += tolower(c);
  }

  return result;
}

/*<-------------------------------------main------------------------------------->*/

int main() {
  int count;
  std::cin >> count;
  std::vector<std::string> strings(count);
  for (std::string& str : strings) {
    std::cin >> str;
  }

  std::sort(begin(strings), end(strings),
      [] (const std::string& lhs, const std::string& rhs) {
        return ToLower(lhs) < ToLower(rhs);
      }
  );

  PrintVector(strings);

  return 0;
}
