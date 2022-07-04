/*================================================================================*/
/*                    C++_Development_Basics: The_Yellow_Belt                     */
/*================================================================================*/
/*  Title: Mass Of Block                                                          */
/*  Start_time: 04.07.2022 19:24                                                  */
/*  End_time: 04.07.2022 19:45                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Вычислите суммарную массу имеющих форму прямоугольного параллелепипеда блоков
 * одинаковой плотности, но разного размера.
 *
 * Указание
 *
 * Считайте, что размеры блоков измеряются в сантиметрах, плотность - в граммах на
 * кубический сантиметр, а итоговая масса - в граммах. Таким образом, массу блока
 * можно вычислять как простое произведение плотности на объём.
 *
 * Формат ввода
 *
 * В первой строке вводятся два целых положительных числа: количество блоков N и
 * плотность каждого блока R. Каждая из следующих N строк содержит три целых
 * положительных числа W, H, D - размеры очередного блока.
 *
 * Гарантируется, что:
 *
 * - количество блоков N не превосходит 10^5;
 * - плотность блоков R не превосходит 100;
 * - размеры блоков W, H, D не превосходят 10^4.
 *
 *   Пример
 *
 * Ввод
 *
 * 2 14
 * 1 2 3
 * 30 40 50
 *
 * Вывод
 *
 * 840084
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>

/*<-------------------------------------main------------------------------------->*/

int main() {
  int blocks_count = 0;
  int R = 0;
  int W, H, D;
  uint64_t mass = 0;

  std::cin >> blocks_count >> R;

  for(int i = 0; i < blocks_count; ++i) {
    std::cin >> W >> H >> D;
    mass += static_cast<uint64_t>(R) * W * H * D;
  }

  std::cout << mass << std::endl;

  return 0;
}
