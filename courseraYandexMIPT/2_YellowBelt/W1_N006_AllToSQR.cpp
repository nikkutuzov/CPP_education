/*================================================================================*/
/*                    C++_Development_Basics: The_Yellow_Belt                     */
/*================================================================================*/
/*  Title: All to a square                                                        */
/*  Start_time: 20.07.2022 19:39                                                  */
/*  End_time:                                                                     */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Реализуйте шаблонную функцию Sqr, которая работает не только для чисел,но и для
 * контейнеров. Функция должна возвращать копию исходного контейнера, модифицировав
 * его следующим образом:
 *
 * - для vector элементы нужно возвести в квадрат;
 * - для map в квадрат нужно возвести только значения, но не ключи;
 * - для pair в квадрат нужно возвести каждый элемент пары.
 *
 * // Пример вызова функции
 * vector<int> v = {1, 2, 3};
 * cout << "vector:";
 * for (int x : Sqr(v)) {
 *   cout << ' ' << x;
 * }
 * cout << endl;
 *
 * map<int, pair<int, int>> map_of_pairs = {
 *   {4, {2, 2}},
 *   {7, {4, 3}}
 * };
 * cout << "map of pairs:" << endl;
 * for (const auto& x : Sqr(map_of_pairs)) {
 *   cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
 * }
 *
 * Код выше должен вывести:
 *
 * vector: 1 4 9
 * map of pairs:
 * 4 4 4
 * 7 16 9
 *
 * Функция должна корректно работать не только для контейнеров, состоящих
 * из чисел, но и для составных объектов, например, векторов словарей пар чисел.
 *
 * Для успешной сдачи решения необходимо сделать предварительное объявление
 * шаблонных функций перед всеми шаблонными функциями.
 *
 * Пример предварительного объявления шаблонной функци:
 *
 * // Предварительное объявление шаблонных функций
 * template<typename T> T FuncA(T x);
 * template<typename T> void FuncB(T x);
 *
 * // Объявляем шаблонные функции
 * template <typename T>
 * T FuncA(T x) { ... }
 *
 * template <typename T>
 * void FuncB(T x) { ... }
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <vector>
#include <map>
#include <utility>

/*<----------------------------declaration_of_funcs------------------------------>*/

// Предварительное объявление шаблонных функций
  // для простых действий
template <typename T>
T Sqr(T x);

  // для vector
template <typename T>
std::vector<T> Sqr(const std::vector<T>& v);

  // для pair
template <typename First, typename Second>
std::pair<First, Second> Sqr(const std::pair<First, Second>& p);

  // для map
template <typename Key, typename Value>
std::map<Key, Value> Sqr(const std::map<Key, Value>& m);

/*<-------------------------------------main------------------------------------->*/

int main() {
  std::vector<int> v = {1, 2, 3};
  std::cout << "vector:";

  for (int x : Sqr(v)) {
    std::cout << ' ' << x;
  }

  std::cout << std::endl;

  std::map<int, std::pair<int, int>> map_of_pairs = {
    {4, {2, 2}},
    {7, {4, 3}}
  };
  std::cout << "map of pairs:" << std::endl;

  for (const auto& x : Sqr(map_of_pairs)) {
    std::cout << x.first << ' ' << x.second.first
              << ' ' << x.second.second << std::endl;
  }

  return 0;
}

/*<-----------------------------definition_of_funcs------------------------------>*/

// Определяем шаблонные функции
template <typename T>
T Sqr(T x) {
  return x * x;
}

template <typename T>
std::vector<T> Sqr(const std::vector<T>& v) {
  std::vector<T> res;
  for (const T& item : v) {
    res.push_back(Sqr(item));
  }

  return res;
}

template <typename First, typename Second>
std::pair<First, Second> Sqr(const std::pair<First, Second>& p) {
  First first = Sqr(p.first);
  Second second = Sqr(p.second);

  return std::make_pair(first, second);
}

template <typename Key, typename Value>
std::map<Key, Value> Sqr(const std::map<Key, Value>& m) {
  std::map<Key, Value> res;
  for (const auto& [key, value] : m) {
    res[key] = Sqr(value);
  }

  return res;
}
