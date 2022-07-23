/*================================================================================*/
/*                    C++_Development_Basics: The_Yellow_Belt                     */
/*================================================================================*/
/*  Title:  Реализовать класс, объявленный в заголовочном файле                   */
/*  Start_time: 22.07.2022 16:29                                                  */
/*  End_time:                                                                     */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Вам дан заголовочный файл phone_number.h, содержащий объявление класса
 * PhoneNumber. При этом в комментариях описано поведение, которое ожидается от
 * реализации этого класса.
 *
 * https://github.com/nikkutuzov/CPP_education/blob/master/courseraYandexMIPT/Templates/2_YB_W3_N002_PhoneNumber/phone_number.h
 *
 * Пришлите cpp-файл с определениями методов класса PhoneNumber, которые реализуют
 * описанное поведение.
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>

#include "phone_number.h"

/*<-------------------------------------main------------------------------------->*/
// !!! ПРИ ОТПРАВКЕ НА ПРОВЕРКУ НУЖНО УДАЛИТЬ ФУНКЦИЮ main() !!!
// оставил ее только для проверки компиляции!
int main() {

  return 0;
}

/*<-----------------------definition_of_funcs_and_classes------------------------>*/

PhoneNumber::PhoneNumber(const std::string &international_number) {
  
}

std::string PhoneNumber::GetCountryCode() const {
  return country_code_;
}
std::string PhoneNumber::GetCityCode() const {
  return city_code_;
}
std::string PhoneNumber::GetLocalNumber() const {
  return local_number_;
}
std::string PhoneNumber::GetInternationalNumber() const {
  return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}
