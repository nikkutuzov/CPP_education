/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Tittle: Palindrome filter                                                     */
/*  Start_time: 24.06.2022 11:06                                                  */
/*  End_time: 24.06.2022 11:54                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Напишите функцию, которая
 *
 * - называется PalindromeFilter
 * - возвращает vector<string>
 * - принимает vector<string> words и int minLength и возвращает все строки из
 *   вектора words, которые являются палиндромами и имеют длину не меньше minLength
 *
 * Входной вектор содержит не более 100 строк, длина каждой строки не больше 100
 * символов.
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <vector>

bool IsPalindrome(std::string str) {
  for (int i = 0; i < str.size() /2; ++i) {
    if (str[i] != str[str.size() - 1 - i]) {
      return false;
    }
  }

  return true;
}

std::vector<std::string> PalindromeFilter(std::vector<std::string> v,
                                          int minLength) {
  std::vector<std::string> result;
  for (std::string item : v) {
    if (IsPalindrome(item) and item.size() >= minLength) {
      result.push_back(item);
    }
  }

  return result;
}

/*<-------------------------------------main------------------------------------->*/

int main() {

  return 0;
}
