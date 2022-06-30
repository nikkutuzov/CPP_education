/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Tittle: Reversible string                                                     */
/*  Start_time: 30.06.2022 14:24                                                  */
/*  End_time: 30.06.2022 14:33                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Реализуйте класс ReversibleString, хранящий строку и поддерживающий методы
 * Reverse для переворота строки и ToString для получения строки.
 *
 * Пример
 *
 * Код
 *
 * int main() {
 *  ReversibleString s("live");
 *  s.Reverse();
 *  cout << s.ToString() << endl;
 *
 *  s.Reverse();
 *  const ReversibleString& s_ref = s;
 *  string tmp = s_ref.ToString();
 *  cout << tmp << endl;
 *
 *  ReversibleString empty;
 *  cout << '"' << empty.ToString() << '"' << endl;
 *
 * return 0;
 * }
 *
 * Вывод
 *
 * evil
 * live
 * ""
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <algorithm>

class ReversibleString {
public:
  ReversibleString() {}
  ReversibleString(const std::string& new_str) {
    str = new_str;
  }
  void Reverse() {
    std::reverse(begin(str), end(str));
  }
  std::string ToString() const{
    return str;
  }

private:
  std::string str;
};

/*<-------------------------------------main------------------------------------->*/

int main() {
  ReversibleString s("live");
  s.Reverse();
  std::cout << s.ToString() << std::endl;

  s.Reverse();
  const ReversibleString& s_ref = s;
  std::string tmp = s_ref.ToString();
  std::cout << tmp << std::endl;

  ReversibleString empty;
  std::cout << '"' << empty.ToString() << '"' << std::endl;

  return 0;
}
