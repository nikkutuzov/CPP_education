/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Tittle: Anagrams                                                              */
/*  Start_time: 24.06.2022 15:58                                                  */
/*  End_time: 24.06.2022 16:21                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Слова называются анаграммами друг друга, если одно из них можно получить
 * перестановкой букв в другом. Например, слово «eat» можно получить перестановкой
 * букв слова «tea», поэтому эти слова являются анаграммами друг друга.
 * Даны пары слов, проверьте для каждой из них, являются ли слова этой пары
 * анаграммами друг друга.
 *
 * Указание
 *
 * Один из способов проверки того, являются ли слова анаграммами друг друга,
 * заключается в следующем. Для каждого слова с помощью словаря подсчитаем, сколько
 * раз в нём встречается каждая буква. Если для обоих слов эти словари равны (а это
 * проверяется с помощью обычного оператора ==), то слова являются анаграммами друг
 * друга, в противном случае не являются.
 *
 * При этом построение такого словаря по слову удобно вынести в отдельную функцию
 * BuildCharCounters.
 *
 * Формат ввода
 *
 * Сначала дано число пар слов N, затем в N строках содержатся пары слов, которые
 * необходимо проверить. Гарантируется, что все слова состоят лишь из строчных
 * латинских букв.
 *
 * Формат вывода
 *
 * Выведите N строк: для каждой введённой пары слов YES, если эти слова являются
 * анаграммами, и NO в противном случае.
 *
 * Пример
 *
 * Ввод
 *
 * 3
 * eat tea
 * find search
 * master stream
 *
 * Вывод
 *
 * YES
 * NO
 * YES
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <map>

std::map<char, int> BuildCharCounters(const std::string& str) {
  std::map<char, int> result;
  for (const char& c : str) {
    ++result[c];
  }

  return result;
}

/*<-------------------------------------main------------------------------------->*/

int main() {
  int count = 0;
  std::cin >> count;

  for (int i = 0; i < count; ++i) {
    std::string str1, str2;
    std::cin >> str1 >> str2;
    if (BuildCharCounters(str1) == BuildCharCounters(str2)) {
      std::cout << "YES";
    } else {
      std::cout << "NO";
    }
    std::cout << std::endl;
  }

  return 0;
}
