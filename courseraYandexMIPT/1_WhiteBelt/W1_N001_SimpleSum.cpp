/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Tittle: Simple sum                                                            */
/*  Start_time: 23.06.2022 10:35                                                  */
/*  End_time: 23.06.2022 10:45                                                    */
/*  Note: The first programming assignment in the course                          */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * На вход программе через стандартный ввод передаются два целых числа, по модулю
 * не превышающие 100000. Выведите в стандартный вывод их сумму.
 *
 * Подсказки
 *
 * - Ваша программа должна выводить в cout только одно число — сумму введённых чисел
 *   (т.е. не надо выводить в cout входные числа или строки типа "A = ")
 * - Вам не надо проверять, что входные числа не превышают по модулю 100000. Мы
 *   гарантируем, что в тестирующей системе вашей программе будут подаваться только
 *   числа, удовлетворяющие указанным ограничениям
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>

/*<-------------------------------------main------------------------------------->*/

int main() {
  int x;
  int y;
  std::cin >> x >> y;
  std::cout << x + y << std::endl;

  return 0;
}