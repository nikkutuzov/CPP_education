/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Title: class Rational part 2                                                  */
/*  Start_time: 03.07.2022 12:19                                                  */
/*  End_time: 03.07.2022 12:50                                                    */
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
 * Часть 2
 *
 * Реализуйте для класса Rational операторы ==, + и - так, чтобы операции с дробями
 * можно было записывать естественным образом.
 * Например, следующий код должен быть валидным:
 *
 * const Rational r = Rational(1, 2) + Rational(1, 3) - Rational(1, 4);
 * if (r == Rational(7, 12)) {
 *   cout << "equal";
 * }
 *
 * Гарантируется, что во всех тестах, на которых будет тестироваться ваша
 * реализация, числители и знаменатели ВСЕХ дробей (как исходных, так и получившихся
 * в результате соответствующих арифметических операций) будут укладываться в
 * диапазон типа int.
 *
 * Шаблон программы:
 *
 * https://github.com/nikkutuzov/CPP_education/blob/master/courseraYandexMIPT/Templates/1_WB_W4_N008_Rational/2_rational_eq_add_sub.cpp
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
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

Rational operator+ (const Rational& lhs, const Rational& rhs) {
  return {lhs.Numerator() * rhs.Denominator() +
          rhs.Numerator() * lhs.Denominator(),
          lhs.Denominator() * rhs.Denominator()};
}

Rational operator- (const Rational& lhs, const Rational& rhs) {
  return {lhs.Numerator() * rhs.Denominator() -
          rhs.Numerator() * lhs.Denominator(),
          lhs.Denominator() * rhs.Denominator()};
}

/*<-------------------------------------main------------------------------------->*/

int main() {
  {
    Rational r1(4, 6);
    Rational r2(2, 3);
    bool equal = r1 == r2;
    if (!equal) {
      std::cout << "4/6 != 2/3" << std::endl;
      return 1;
    }
  }

  {
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a + b;
    bool equal = c == Rational(2, 1);
    if (!equal) {
      std::cout << "2/3 + 4/3 != 2" << std::endl;
      return 2;
    }
  }

  {
    Rational a(5, 7);
    Rational b(2, 9);
    Rational c = a - b;
    bool equal = c == Rational(31, 63);
    if (!equal) {
      std::cout << "5/7 - 2/9 != 31/63" << std::endl;
      return 3;
    }
  }

  std::cout << "OK" << std::endl;

  return 0;
}
