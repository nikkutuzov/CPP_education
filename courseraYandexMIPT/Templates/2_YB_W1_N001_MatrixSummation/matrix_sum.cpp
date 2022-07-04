#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

// Реализуйте здесь
// * класс Matrix
// * оператор ввода для класса Matrix из потока istream
// * оператор вывода класса Matrix в поток ostream
// * оператор проверки на равенство двух объектов класса Matrix
// * оператор сложения двух объектов класса Matrix

int main() {
  Matrix one;
  Matrix two;

  std::cin >> one >> two;
  std::cout << one + two << std::endl;
  
  return 0;
}
