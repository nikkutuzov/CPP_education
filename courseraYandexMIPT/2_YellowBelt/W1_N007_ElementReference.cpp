/*================================================================================*/
/*                    C++_Development_Basics: The_Yellow_Belt                     */
/*================================================================================*/
/*  Title: Element reference                                                      */
/*  Start_time: 21.07.2022 10:10                                                  */
/*  End_time: 21.07.2022 10:41                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 *
 * Реализуйте шаблонную функцию GetRefStrict, которая на вход принимает: map и
 * значение ключа k. Если элемент по ключу k в коллекции отсутствует, то функция
 * должна бросить исключение runtime_error, иначе вернуть ссылку на элемент в
 * коллекции.
 *
 * Пример использования функции:
 *
 * map<int, string> m = {{0, "value"}};
 * string& item = GetRefStrict(m, 0);
 * item = "newvalue";
 * cout << m[0] << endl; // выведет newvalue
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <map>
#include <stdexcept>

/*<----------------------------declaration_of_funcs------------------------------>*/

template <typename Key, typename Value>
Value& GetRefStrict(std::map<Key, Value>& m, const Key key);

/*<-------------------------------------main------------------------------------->*/

int main() {
  std::map<int, std::string> m = {{0, "value"}};
  std::string& item = GetRefStrict(m, 0);
  item = "newvalue";
  std::cout << m[0] << std::endl; // выведет newvalue

  return 0;
}

/*<-----------------------------definition_of_funcs------------------------------>*/

template <typename Key, typename Value>
Value& GetRefStrict(std::map<Key, Value>& m, const Key key) {
  if (m.count(key) == 0) {
    throw std::runtime_error("no such key in dictionary");
  }

  return m.at(key);
}
