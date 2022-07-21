/*================================================================================*/
/*           Universal functions for outputting containers to a stream            */
/*               Универсальные функции вывода контейнеров в поток                 */
/*================================================================================*/

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>

template <typename First, typename Second>
std::ostream& operator << (std::ostream& out, const std::pair<First, Second>& p);

template <typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& vi);

template <typename Key, typename Value>
std::ostream& operator << (std::ostream& out, const std::map<Key, Value>& m);

template <typename Collection>
std::string Join(const Collection& c, char d) {
  // создаем строковый поток
  std::stringstream ss;
  // флаг - первый элемент или нет
  bool first = true;
  for (const auto& i : c) {
    if (!first) {
      ss << d;
    }
    first = false;
    ss << i;
  }

  // вернем получившуюся строку
  return ss.str();
}

template <typename First, typename Second>
std::ostream& operator << (std::ostream& out, const std::pair<First, Second>& p) {
  return out << '(' << p.first << ',' << p.second << ')';
}

template <typename T>
std::ostream& operator << (std::ostream& out, const std::vector<T>& vi) {
  return out << '[' << Join(vi, ',') << ']';
}

template <typename Key, typename Value>
std::ostream& operator << (std::ostream& out, const std::map<Key, Value>& m) {
  return out << '{' << Join(m, ',') << '}';
}

/*<-------------------------------------main------------------------------------->*/

int main() {
  std::vector<double> vi = {1.4, 2, 3};
  std::cout << vi << std::endl;
  std::map<int, double> m = {{1, 2.5}, {3, 4}};
  std::cout << m << std::endl;
  std::vector<std::vector<int>> vvi = {{1, 2}, {3, 4}};
  std::cout << vvi << std::endl;

  return 0;
}

/* *** ВЫВОД ***

[1.4,2,3]
{(1,2.5),(3,4)}
[[1,2],[3,4]]

*/
