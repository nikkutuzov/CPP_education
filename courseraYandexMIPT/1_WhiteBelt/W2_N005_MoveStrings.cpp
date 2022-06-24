/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Tittle: Move strings                                                          */
/*  Start_time: 24.06.2022 12:52                                                  */
/*  End_time: 24.06.2022 13:04                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Напишите функцию MoveStrings, которая принимает два вектора строк, source и
 * destination, и дописывает все строки из первого вектора в конец второго. После
 * выполнения функции вектор source должен оказаться пустым.
 *
 * Чтобы очистить содержимое вектора, надо вызвать у него метод clear:
 *
 * vector<string> words = {"hey", "hi"};
 * words.clear();
 * // Теперь вектор words пуст
 *
 * Пример
 *
 * vector<string> source = {"a", "b", "c"};
 * vector<string> destination = {"z"};
 * MoveStrings(source, destination);
 * // source должен оказаться пустым
 * // destination должен содержать строки "z", "a", "b", "c" именно в таком порядке
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <vector>

void MoveStrings(std::vector<std::string>& source,
                 std::vector<std::string>& destination) {
  for (const std::string& item : source) {
    destination.push_back(item);
  }
  source.clear();
}

/*<-------------------------------------main------------------------------------->*/

int main() {

  return 0;
}
