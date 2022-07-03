/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Title: class Rational part 5                                                  */
/*  Start_time: 03.07.2022 13:55                                                  */
/*  End_time: 03.07.2022 14:09                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * В этой задаче вам надо разработать класс для представления рациональных чисел и
 * внедрить его в систему типов языка С++ так, чтобы им можно было пользоваться
 * естественным образом. Задание состоит из нескольких частей. К каждой части
 * приложен файл с заготовкой программы, который имеет следующую структуру
 *
 * #include <iostream>
 * using namespace std;
 *
 * // Комментарии, которые говорят, что именно нужно реализовать в этой программе
 *
 * int main() {
 *   // Набор юнит-тестов для вашей реализации
 *   cout << "OK" << endl;
 *   return 0;
 * }
 *
 * Вам нужно, не меняя тело функции main, реализовать то, что предложено в
 * комментариях, так, чтобы ваша программа выводила на экран сообщение OK.
 * Функция main содержит ряд юнит-тестов, которые проверяют правильность вашей
 * реализации. Если эти тесты находят ошибку в вашей реализации, то вместо OK
 * программа выведет подсказку о том, что именно работает неправильно.
 *
 * Когда ваша программа начнёт выводить OK, можете отправлять свой файл на проверку.
 * Ваша реализация будет тестироваться на другом, более полном наборе тестов.
 * То есть, если ваша программа выводит OK, то это не даёт гарантии, что ваша
 * реализация будет принята тестирующей системой. В случае неудачной посылки
 * тестирующая система также выдаст вам подсказку о том, какая именно часть
 * реализации работает неправильно.
 *
 * Внимательно изучите набор юнит-тестов для каждой заготовки решения. Тесты
 * описывают требования, предъявляемые к вашей реализации, которые могут быть не
 * указаны в условии задач.
 *
 * На проверку можно отправлять весь файл с вашей реализацией: функцию main удалять
 * из него не нужно.
 *
 * Часть 5
 *
 * Наконец, вам нужно реализовать возможность использовать объекты класса Rational в
 * качестве элементов контейнера set и ключей в контейнере map. Пример:
 *
 * set<Rational> rationals;
 * rationals.insert(Rational(1, 2));
 * rationals.insert(Rational(1, 3));
 *
 * map<Rational, string> name;
 * name[Rational(1, 2)] = "одна вторая";
 *
 * Шаблон программы:
 *
 * https://github.com/nikkutuzov/CPP_education/blob/master/courseraYandexMIPT/Templates/1_WB_W4_N008_Rational/5_rational_map.cpp
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <numeric> // for GCD

class Rational {
public:
  Rational() {
    numerator = 0;
    denominator = 1;
  }

  Rational(int new_numerator, int new_denominator) {
    const int GCD = std::gcd(new_numerator, new_denominator);

    numerator = new_numerator / GCD;
    denominator = new_denominator / GCD;

    if (denominator < 0) {
      numerator = -numerator;
      denominator = -denominator;
    }
  }

  int Numerator() const {
    return numerator;
  }

  int Denominator() const {
    return denominator;
  }

private:
  int numerator;
  int denominator;
};

bool operator== (const Rational& lhs, const Rational& rhs) {
  return lhs.Numerator() == rhs.Numerator() and
         lhs.Denominator() == rhs.Denominator();
}

bool operator< (const Rational& lhs, const Rational& rhs) {
  return lhs.Numerator() * rhs.Denominator() <
         rhs.Numerator() * lhs.Denominator();
  // у авторов красиво
  // return (lhs - rhs).Numerator() < 0;
}

/*<-------------------------------------main------------------------------------->*/

int main() {
  {
    const std::set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
    if (rs.size() != 3) {
      std::cout << "Wrong amount of items in the set" << std::endl;
      return 1;
    }

    std::vector<Rational> v;
    for (auto x : rs) {
      v.push_back(x);
    }
    if (v != std::vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
      std::cout << "Rationals comparison works incorrectly" << std::endl;
      return 2;
    }
  }

  {
    std::map<Rational, int> count;
    ++count[{1, 2}];
    ++count[{1, 2}];

    ++count[{2, 3}];

    if (count.size() != 2) {
      std::cout << "Wrong amount of items in the map" << std::endl;
      return 3;
    }
  }

  std::cout << "OK" << std::endl;

  return 0;
}
