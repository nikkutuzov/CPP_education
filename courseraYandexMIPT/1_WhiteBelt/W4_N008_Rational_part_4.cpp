/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Title: class Rational part 4                                                  */
/*  Start_time: 03.07.2022 13:03                                                  */
/*  End_time: 03.07.2022 13:54                                                    */
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
 * Часть 4
 *
 * В этой части вам нужно реализовать операторы ввода и вывода для класса Rational.
 * В результате у вас должен работать, например, такой код
 *
 * Rational r;
 * cin >> r;
 * cout << r;
 *
 * Шаблон программы:
 *
 * https://github.com/nikkutuzov/CPP_education/blob/master/courseraYandexMIPT/Templates/1_WB_W4_N008_Rational/4_rational_io.cpp
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <sstream>
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
  {
    std::stringstream output;
    output << Rational(-6, 8);
    if (output.str() != "-3/4") {
      std::cout << "Rational(-6, 8) should be written as \"-3/4\"" << std::endl;
      return 1;
    }
  }

  {
    std::istringstream input("5/7");
    Rational r;
    input >> r;
    bool equal = r == Rational(5, 7);
    if (!equal) {
      std::cout << "5/7 is incorrectly read as " << r << std::endl;
      return 2;
    }
  }

  {
    std::istringstream input("");
    Rational r;
    bool correct = !(input >> r);
    if (!correct) {
      std::cout << "Read from empty stream works incorrectly" << std::endl;
      return 3;
    }
  }

  {
    std::istringstream input("5/7 10/8");
    Rational r1, r2;
    input >> r1 >> r2;
    bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct) {
      std::cout << "Multiple values are read incorrectly: " << r1 << " "
                << r2 << std::endl;
      return 4;
    }

    input >> r1;
    input >> r2;
    correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
    if (!correct) {
      std::cout << "Read from empty stream shouldn't change arguments: " << r1
                << " " << r2 << std::endl;
      return 5;
    }
  }

  {
    std::istringstream input1("1*2"), input2("1/"), input3("/4");
    Rational r1, r2, r3;
    input1 >> r1;
    input2 >> r2;
    input3 >> r3;
    bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
    if (!correct) {
      std::cout
        << "Reading of incorrectly formatted rationals shouldn't change arguments: "
        << r1 << " " << r2 << " " << r3 << std::endl;
      return 6;
    }
  }

  std::cout << "OK" << std::endl;

  return 0;
}
