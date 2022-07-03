#include <iostream>
#include <exception>

class Rational {
    // Вставьте сюда реализацию класса Rational
};

// Вставьте сюда реализацию operator / для класса Rational

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
