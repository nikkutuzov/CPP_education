/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Tittle: Sorting integers modulo                                               */
/*  Start_time: 26.06.2022 21:50                                                  */
/*  End_time: 26.06.2022 22:15                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Условие
 *
 * В стандартном потоке дана одна строка, состоящая из N + 1 целых чисел. Первым
 * числом идёт само число N. Далее следуют ещё N чисел, обозначим их за массив A.
 * Между собой числа разделены пробелом.
 *
 * Отсортируйте массив А по модулю и выведите его в стандартный поток.
 *
 * Ограничения
 *
 * 0 <= N <= 1000
 * -1000000 <= A[i] <= 1000000
 *
 *  Примеры
 *
 *    stdin           stdout
 *    2 -4 3          3 -4
 *    3 1 -3 2        1 2 -3
 *
 * Подсказка
 *
 * функция sort дополнительно принимает третий аргумент. Изучите его подробнее по
 * ссылке: http://www.cplusplus.com/reference/algorithm/sort/?kw=sort
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void PrintVector(const std::vector<int>& v) {
  for (const int& item : v) {
    std::cout << item << " ";
  }
  std::cout << std::endl;
}

/*<-------------------------------------main------------------------------------->*/

int main() {
  int count;
  std::cin >> count;
  std::vector<int> numbers(count);

  for (int& number : numbers) {
    std::cin >> number;
  }

  std::sort(begin(numbers), end(numbers),
      [] (const int& lhs, const int& rhs) {
        return abs(lhs) < abs(rhs);
      }
  );

  PrintVector(numbers);

  return 0;
}
