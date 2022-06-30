/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Tittle: Lecture title                                                         */
/*  Start_time: 30.06.2022 19:05                                                  */
/*  End_time: 30.06.2022 19:46                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Дана структура LectureTitle:
 *
 * struct LectureTitle {
 *  string specialization;
 *  string course;
 *  string week;
 * };
 *
 * Допишите конструктор и структуры Specialization, Course, Week так, чтобы объект
 * LectureTitle можно было создать с помощью кода:
 *
 * LectureTitle title(
 *  Specialization("C++"),
 *  Course("White belt"),
 *  Week("4th")
 * );
 *
 * но нельзя было с помощью следующих фрагментов кода:
 *
 * LectureTitle title("C++", "White belt", "4th");
 *
 * LectureTitle title(string("C++"), string("White belt"), string("4th"));
 *
 * LectureTitle title = {"C++", "White belt", "4th"};
 *
 * LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};
 *
 * LectureTitle title(
 *  Course("White belt"),
 *  Specialization("C++"),
 *  Week("4th")
 * );
 *
 * LectureTitle title(
 * Specialization("C++"),
 * Week("4th"),
 * Course("White belt")
 * );
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>

struct Specialization {
  std::string value;
  explicit Specialization(std::string new_value) {
    value = new_value;
  }
};

struct Course {
  std::string value;
  explicit Course(std::string new_value) {
    value = new_value;
  }
};

struct Week {
  std::string value;
  explicit Week(std::string new_value) {
    value = new_value;
  }
};

struct LectureTitle {
  std::string specialization;
  std::string course;
  std::string week;

  LectureTitle(Specialization new_specialization,
                Course new_course,
                Week new_week) {
    specialization = new_specialization.value;
    course = new_course.value;
    week = new_week.value;
  }
};

/*<-------------------------------------main------------------------------------->*/

int main() {
  LectureTitle title(
    Specialization("C++"),
    Course("White belt"),
    Week("4th")
  );

  return 0;
}
