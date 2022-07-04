/*================================================================================*/
/*                    C++_Development_Basics: The_Yellow_Belt                     */
/*================================================================================*/
/*  Title: Regions base                                                           */
/*  Start_time: 04.07.2022 19:48                                                  */
/*  End_time:                                                                     */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Имеется база регионов, представленная вектором структур Region:
 *
 * struct Region {
 *   string std_name;
 *   string parent_std_name;
 *   map<Lang, string> names;
 *   int64_t population;
 * };
 *
 * Здесь Lang - идентификатор языка:
 *
 * enum class Lang {
 *   DE, FR, IT
 * };
 *
 * Напишите функцию FindMaxRepetitionCount, принимающую базу регионов и
 * определяющую, какое максимальное количество повторов (число вхождений одного и
 * того же элемента) она содержит. Две записи (объекты типа Region) считаются
 * различными, если они отличаются хотя бы одним полем.
 *
 * int FindMaxRepetitionCount(const vector<Region>& regions);
 *
 * Если все записи уникальны, считайте максимальное количество повторов равным 1.
 * Если записи отсутствуют, верните 0. Гарантируется, что типа int достаточно для
 * хранения ответа.
 *
 * Пример кода
 *
 * int main() {
 *   std::cout << FindMaxRepetitionCount({
 *     {
 *       "Moscow",
 *       "Russia",
 *       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
 *       89
 *     }, {
 *       "Russia",
 *       "Eurasia",
 *       {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
 *       89
 *     }, {
 *       "Moscow",
 *       "Russia",
 *       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
 *       89
 *     }, {
 *       "Moscow",
 *       "Russia",
 *       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
 *       89
 *     }, {
 *       "Russia",
 *       "Eurasia",
 *       {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
 *       89
 *     },
 *   }) << std::endl;
 *
 *   std::cout << FindMaxRepetitionCount({
 *     {
 *       "Moscow",
 *       "Russia",
 *       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
 *       89
 *     }, {
 *       "Russia",
 *       "Eurasia",
 *       {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
 *       89
 *     }, {
 *       "Moscow",
 *       "Russia",
 *       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
 *       89
 *     }, {
 *       "Moscow",
 *       "Toulouse",
 *       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
 *       89
 *     }, {
 *       "Moscow",
 *       "Russia",
 *       {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
 *       31
 *     },
 *   }) << std::endl;
 *
 *   return 0;
 * }
 * Вывод
 *
 * 3
 * 1
 *
 * Пояснение
 *
 * В этой задаче вам надо прислать на проверку файл с реализацией функции
 * FindMaxRepetitionCount, а также дополнительных функций, если это необходимо.
 * Этот файл не должен содержать типы Lang и Region. В противном случае вы получите
 * ошибку компиляции.
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <vector>

/*<-------------------------------------main------------------------------------->*/

int main() {
  std::cout << FindMaxRepetitionCount({
    {
      "Moscow",
      "Russia",
      {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
      89
    }, {
      "Russia",
      "Eurasia",
      {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
      89
    }, {
      "Moscow",
      "Russia",
      {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
      89
    }, {
      "Moscow",
      "Russia",
      {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
      89
    }, {
      "Russia",
      "Eurasia",
      {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
      89
    },
  }) << std::endl;

  std::cout << FindMaxRepetitionCount({
    {
      "Moscow",
      "Russia",
      {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
      89
    }, {
      "Russia",
      "Eurasia",
      {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
      89
    }, {
      "Moscow",
      "Russia",
      {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
      89
    }, {
      "Moscow",
      "Toulouse",
      {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
      89
    }, {
      "Moscow",
      "Russia",
      {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
      31
    },
  }) << std::endl;

  return 0;
}
