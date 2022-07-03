/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Title: Exception in Rational class                                            */
/*  Start_time: 03.07.2022 16:59                                                  */
/*  End_time: 03.07,2022 17:20                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Вспомним класс Rational, который мы реализовали в задачах, посвящённых перегрузке
 * операторов. Там специально говорилось, что в тестах объекты класса Rational
 * никогда не создаются с нулевым знаменателем и никогда не выполняется деление на
 * ноль. Настало время избавиться от этого ограничения и научиться обрабатывать
 * нулевой знаменатель и деление на ноль. В этой задаче вам предстоит это сделать.
 *
 * Поменяйте реализацию конструктора класса Rational так, чтобы он выбрасывал
 * исключение invalid_argument, если знаменатель  равен нулю. Кроме того,
 * переделайте реализацию оператора деления для класса Rational так, чтобы он
 * выбрасывал исключение domain_error, если делитель равен нулю.
 *
 * Напомним, что вам надо реализовать интерфейс
 *
 * class Rational {
 * public:
 *  Rational();
 *  Rational(int numerator, int denominator);
 *
 * int Numerator() const;
 * int Denominator() const;
 * };
 *
 * и оператор деления для класса Rational
 *
 * Rational operator / (const Rational& lhs, const Rational& rhs);
 *
 * Так же, как и в задачах на перегрузку операторов, вам будет предложен файл с
 * заготовкой кода. Функция main в этом файле содержит ряд юнит-тестов, которые
 * позволят вам проверить свою реализацию. При проверке вашего решения оно будет
 * тестироваться на более полном наборе тестов, так что успешное прохождение всех
 * юнит-тестов не гарантирует, что ваша реализация будет зачтена.
 *
 * Шаблон программы:
 *
 * https://github.com/nikkutuzov/CPP_education/blob/master/courseraYandexMIPT/Templates/1_WB_W4_N010_ExceptionInRationalClass/rational_throw.cpp
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <stdexcept>
#include <numeric> // for gcd

class Rational {
public:
  Rational() {
    numerator = 0;
    denominator = 1;
  }

  Rational(int new_numerator, int new_denominator) {
    if (new_denominator == 0) {
      throw std::invalid_argument("Incorrect fraction");
    }

    const int GCD = std::gcd(new_numerator, new_denominator);

    numerator = new_numerator / GCD;
    denominator = new_denominator / GCD;

    if (denominator < 0) {
      numerator = - numerator;
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

Rational operator/ (const Rational& lhs, const Rational& rhs) {
  if (rhs.Numerator() == 0) {
    throw std::domain_error("Division by ZERO");
  }

  return {
          lhs.Numerator() * rhs.Denominator(),
          rhs.Numerator() * lhs.Denominator()
         };
}

/*<-------------------------------------main------------------------------------->*/

int main() {
  try {
    Rational r(1, 0);
    std::cout << "Doesn't throw in case of zero denominator" << std::endl;
    return 1;
  } catch (std::invalid_argument&) {
  }

  try {
    auto x = Rational(1, 2) / Rational(0, 1);
    std::cout << "Doesn't throw in case of division by zero" << std::endl;
    return 2;
  } catch (std::domain_error&) {
  }

  std::cout << "OK" << std::endl;

  return 0;
}
