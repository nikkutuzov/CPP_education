/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Title: Student list                                                           */
/*  Start_time: 02.07.2022 17:43                                                  */
/*  End_time:                                                                     */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Определите структуру «Студент» со следующими полями: имя, фамилия, день, месяц и
 * год рождения. Создайте вектор из таких структур, заполните его из входных данных
 * и затем по запросам выведите нужные поля. Чтение и запись данных в этой задаче
 * производится с использованием стандартных потоков.
 *
 * Формат ввода
 *
 * Первая строка содержит одно целое число N от 0 до 10000 - число студентов.
 *
 * Далее идут N строк, каждая из которых содержит две строки длиной от 1 до 15
 * символов - имя и фамилию очередного студента, и три целых числа от 0 до
 * 1000000000 - день, месяц и год рождения.
 *
 * Следующая строка содержит одно целое число M от 0 до 10000 - число запросов.
 *
 * Следующие M строк содержат строку длиной от 1 до 15 символов - запрос, и целое
 * число от 1 до 1000000000 - номер студента (нумерация начинается с 1).
 *
 * Формат вывода
 *
 * Для запроса вида name K, где K от 1 до N, выведите через пробел имя и
 * фамилию K-го студента.
 *
 * Для запроса вида date K, где K от 1 до N, выведите через точку день,
 * месяц и год рождения K-го студента.
 *
 * Для остальных запросов выведите bad request.
 *
 * NB: неверные запросы могут выходить за границы, указанные для данных.
 *
 * Пример ввода
 *
 * 3
 * Ivan Ivanov 1 1 1901
 * Petr Petrox 2 2 1902
 * Alexander Sidorov 3 3 1903
 * 3
 * name 1
 * date 3
 * mark 5
 *
 * Пример вывода
 *
 * Ivan Ivanov
 * 3.3.1903
 * bad request
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <vector>

struct Student {
  std::string first_name;
  std::string last_name;
  int day;
  int month;
  int year;
};

/*<-------------------------------------main------------------------------------->*/

int main() {
  int student_count = 0;
  std::cin >> student_count;
  std::vector<Student> students(student_count);

  for (Student& student : students) {
    std::cin >> student.first_name >> student.last_name >>
                student.day >> student.month >> student.year;
  }

  int request_count = 0;
  std::cin >> request_count;

  for (int i = 0; i < request_count; ++i) {
    std::string request;
    int number;
    std::cin >> request >> number;
    --number;
    if (request == "name" and number < student_count and number >= 0) {
      std::cout << students[number].first_name << ' ' <<
                students[number].last_name;
    } else if (request == "date" and number < student_count and number >= 0) {
        std::cout << students[number].day << '.' <<
                     students[number].month << '.' <<
                     students[number].year;
    } else {
      std::cout << "bad request";
    }
    std::cout << std::endl;
  }

  return 0;
}
