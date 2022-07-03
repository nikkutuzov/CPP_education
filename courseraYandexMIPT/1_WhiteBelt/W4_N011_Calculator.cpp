/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Title: Calculator of ordinary fractions                                       */
/*  Start_time: 03.07.2022 17:23                                                  */
/*  End_time: 03.07.2022                                                                     */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Итак, теперь у нас с вами есть полноценный тип для представления  обыкновенных
 * дробей: класс Rational интегрирован в язык с помощью  перегрузки операторов и не
 * позволяет выполнять некорректные операции за  счёт выбрасывания исключений.
 * Давайте на основе класса Rational создадим простой калькулятор для обыкновенных
 * дробей.
 *
 * Вам надо написать программу, которая считывает из стандартного ввода одну строку
 * в формате ДРОБЬ_1 операция ДРОБЬ_2.  ДРОБЬ_1 и ДРОБЬ_2 имеют формат X/Y, где
 * X - целое, а Y - целое неотрицательное число. операция - это один из символов
 * '+', '-', '*', '/'.
 *
 * Если ДРОБЬ_1 или ДРОБЬ_2 является  некорректной обыкновенной дробью, ваша
 * программа должна вывести в  стандартный вывод сообщение "Invalid argument". Если
 * считанная операция - это деление на ноль, выведите в стандартный вывод сообщение
 * "Division by zero". В противном случае выведите результат операции.
 *
 * Пример
 *
 * stdin                  stdout
 * 1/2 + 1/3              5/6
 * 1/2 + 5/0              Invalid argument
 * 4/5 / 0/8              Division by zero
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <stdexcept>
#include <numeric>

class Rational {
public:
  Rational() {
    numerator = 0;
    denominator = 1;
  }

  Rational(int new_numerator, int new_denominator) {
    if (new_denominator == 0) {
      throw std::runtime_error("Invalid argument");
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

Rational operator* (const Rational& lhs, const Rational& rhs) {
  return {
          lhs.Numerator() * rhs.Numerator(),
          lhs.Denominator() * rhs.Denominator()
         };
}

Rational operator/ (const Rational& lhs, const Rational& rhs) {
  if (rhs.Numerator() == 0) {
    throw std::runtime_error("Division by zero");
  }

  return {
          lhs.Numerator() * rhs.Denominator(),
          rhs.Numerator() * lhs.Denominator()
         };
}

std::ostream& operator<< (std::ostream& stream, const Rational& rational) {
  stream << rational.Numerator() << '/' << rational.Denominator();

  return stream;
}

std::istream& operator>> (std::istream& stream, Rational& rational) {
  int new_numerator;
  int new_denominator;
  char character;
  stream >> new_numerator >> character >> new_denominator;
  if (stream and character == '/') {
    rational = Rational(new_numerator, new_denominator);
  }

  return stream;
}

/*<-------------------------------------main------------------------------------->*/

int main() {
  Rational r1, r2;
  char op;
  try {
    std::cin >> r1 >> op >> r2;
    if (op == '+') {
      std::cout << r1 + r2 << std::endl;
    } else if (op == '-') {
      std::cout << r1 - r2 << std::endl;
    } else if (op == '*') {
      std::cout << r1 * r2 << std::endl;
    } else if (op == '/') {
      std::cout << r1 / r2 << std::endl;
    }
  } catch (std::runtime_error &re) {
    std::cout << re.what() << std::endl;
  }

  return 0;
}
