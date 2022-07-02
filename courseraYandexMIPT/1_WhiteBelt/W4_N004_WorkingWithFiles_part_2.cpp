/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Title: Working with files part 2                                              */
/*  Start_time: 02.07.2022 13:20                                                  */
/*  End_time: 02.07.2022 13:38                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Часть 2
 *
 * Снова считайте все содержимое файла input.txt, но на этот раз выведите его в файл
 * output.txt . Точно так же гарантируется, что содержимое файла input.txt
 * заканчивается переводом строки.
 *
 * Пример
 *
 * input.txt
 *
 * Keep calm
 * and
 * learn C++
 *
 * output.txt
 *
 * Keep calm
 * and
 * learn C++
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <fstream>

/*<-------------------------------------main------------------------------------->*/

int main() {
  std::ifstream input("W4_N004_input.txt"); // for coursera rename to input.txt
  std::ofstream output("W4_N004_output.txt"); // for coursera rename to output.txt

  if (input) {
    std::string str;
    while (input) {
      std::getline(input, str);
      output << str << std::endl;
    }
  }

  return 0;
}
