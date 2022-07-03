/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Title: Ensure equal                                                           */
/*  Start_time: 03.07.2022 16:46                                                  */
/*  End_time:                                                                     */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Напишите функцию
 *
 * void EnsureEqual(const string& left, const string& right);
 *
 * В случае, если строка left не равна строке right, функция должна выбрасывать
 * исключение runtime_error с содержанием "<l> != <r>", где <l> и <r> - строки,
 * которые хранятся в переменных left и right соответственно. Обратите внимание,
 * что вокруг знака неравенства в строке, которая помещается в исключение, должно
 * быть ровно по одному пробелу.
 *
 * Если left == right, функция должна корректно завершаться.
 *
 * Например, код
 *
 * int main() {
 *  try {
 *    EnsureEqual("C++ White", "C++ White");
 *    EnsureEqual("C++ White", "C++ Yellow");
 *  } catch (runtime_error& e) {
 *    cout << e.what() << endl;
 *  }
 *  return 0;
 * }
 *
 * должен выводить
 *
 * C++ White != C++ Yellow
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <exception>

void EnsureEqual(const std::string& left, const std::string& right) {
  if (left != right) {
    throw std::runtime_error(left + " != " + right);
  }
}

/*<-------------------------------------main------------------------------------->*/

int main() {
  try {
    EnsureEqual("C++ White", "C++ White");
    EnsureEqual("C++ White", "C++ Yellow");
  } catch (std::runtime_error& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
