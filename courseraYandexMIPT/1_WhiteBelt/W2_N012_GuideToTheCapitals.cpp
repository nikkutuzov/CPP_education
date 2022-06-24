/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Tittle: Giuide to the capitals                                                */
/*  Start_time: 24.06.2022 16:23                                                  */
/*  End_time: 24.06.2022 17:54                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Реализуйте справочник столиц стран.
 *
 * На вход программе поступают следующие запросы:
 *
 * - CHANGE_CAPITAL country new_capital - изменение столицы страны country на
 *   new_capital, либо добавление такой страны с такой столицей, если раньше её
 *   не было.
 * - RENAME old_country_name new_country_name - переименование страны из
 *   old_country_name в new_country_name.
 * - ABOUT country - вывод столицы страны country.
 * - DUMP - вывод столиц всех стран.
 *
 *   Формат ввода
 *
 * В первой строке содержится количество запросов Q, в следующих Q строках -
 * описания запросов. Все названия стран и столиц состоят лишь из латинских букв,
 * цифр и символов подчёркивания.
 *
 * Формат вывода
 *
 * Выведите результат обработки каждого запроса:
 *
 * В ответ на запрос CHANGE_CAPITAL country new_capital выведите
 *
 * - Introduce new country country with capital new_capital, если страны country
 *   раньше не существовало;
 * - Country country hasn't changed its capital, если страна country до текущего
 *   момента имела столицу new_capital;
 * - Country country has changed its capital from old_capital to new_capital, если
 *   страна country до текущего момента имела столицу old_capital, название которой
 *   не совпадает с названием new_capital.
 *
 *   В ответ на запрос RENAME old_country_name new_country_name выведите
 *
 * - Incorrect rename, skip, если новое название страны совпадает со старым, страна
 *   old_country_name не существует или страна new_country_name уже существует;
 * - Country old_country_name with capital capital has been renamed to new_country_name,
 *   если запрос корректен и страна имеет столицу capital.
 *
 *   В ответ на запрос ABOUT country выведите
 *
 * - Country country doesn't exist, если страны с названием country не существует;
 * - Country country has capital capital, если страна country существует и имеет
 *   столицу capital.
 *
 *   В ответ на запрос DUMP выведите
 *
 * - There are no countries in the world, если пока не было добавлено ни одной страны;
 * - последовательность пар вида country/capital, описывающую столицы всех стран,
 *   если в мире уже есть хотя бы одна страна. При выводе последовательности пары
 *   указанного вида необходимо упорядочить по названию страны и разделять между
 *   собой пробелом.
 *
 * Пример 1
 *
 * Ввод
 *
 * 6
 * CHANGE_CAPITAL RussianEmpire Petrograd
 * RENAME RussianEmpire RussianRepublic
 * ABOUT RussianRepublic
 * RENAME RussianRepublic USSR
 * CHANGE_CAPITAL USSR Moscow
 * DUMP
 *
 * Вывод
 *
 * Introduce new country RussianEmpire with capital Petrograd
 * Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
 * Country RussianRepublic has capital Petrograd
 * Country RussianRepublic with capital Petrograd has been renamed to USSR
 * Country USSR has changed its capital from Petrograd to Moscow
 * USSR/Moscow
 *
 * Пример 2
 *
 * Ввод
 *
 * 24
 * RENAME FakeCountry FarFarAway
 * ABOUT FarFarAway
 * DUMP
 * CHANGE_CAPITAL TsardomOfRussia Moscow
 * CHANGE_CAPITAL TsardomOfRussia Moscow
 * CHANGE_CAPITAL ColonialBrazil Salvador
 * CHANGE_CAPITAL TsardomOfRussia SaintPetersburg
 * RENAME TsardomOfRussia RussianEmpire
 * CHANGE_CAPITAL RussianEmpire Moscow
 * CHANGE_CAPITAL RussianEmpire SaintPetersburg
 * CHANGE_CAPITAL ColonialBrazil RioDeJaneiro
 * DUMP
 * RENAME ColonialBrazil EmpireOfBrazil
 * ABOUT RussianEmpire
 * RENAME EmpireOfBrazil UnitedStatesOfBrazil
 * CHANGE_CAPITAL RussianEmpire Petrograd
 * RENAME RussianEmpire RussianRepublic
 * RENAME RussianRepublic USSR
 * CHANGE_CAPITAL USSR Moscow
 * CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
 * RENAME UnitedStatesOfBrazil FederativeRepublicOfBrazil
 * ABOUT RussianEmpire
 * DUMP
 * RENAME USSR USSR
 *
 * Вывод
 *
 * Incorrect rename, skip
 * Country FarFarAway doesn't exist
 * There are no countries in the world
 * Introduce new country TsardomOfRussia with capital Moscow
 * Country TsardomOfRussia hasn't changed its capital
 * Introduce new country ColonialBrazil with capital Salvador
 * Country TsardomOfRussia has changed its capital from Moscow to SaintPetersburg
 * Country TsardomOfRussia with capital SaintPetersburg has been renamed to RussianEmpire
 * Country RussianEmpire has changed its capital from SaintPetersburg to Moscow
 * Country RussianEmpire has changed its capital from Moscow to SaintPetersburg
 * Country ColonialBrazil has changed its capital from Salvador to RioDeJaneiro
 * ColonialBrazil/RioDeJaneiro RussianEmpire/SaintPetersburg
 * Country ColonialBrazil with capital RioDeJaneiro has been renamed to EmpireOfBrazil
 * Country RussianEmpire has capital SaintPetersburg
 * Country EmpireOfBrazil with capital RioDeJaneiro has been renamed to UnitedStatesOfBrazil
 * Country RussianEmpire has changed its capital from SaintPetersburg to Petrograd
 * Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
 * Country RussianRepublic with capital Petrograd has been renamed to USSR
 * Country USSR has changed its capital from Petrograd to Moscow
 * Country UnitedStatesOfBrazil has changed its capital from RioDeJaneiro to Brasilia
 * Country UnitedStatesOfBrazil with capital Brasilia has been renamed to FederativeRepublicOfBrazil
 * Country RussianEmpire doesn't exist
 * FederativeRepublicOfBrazil/Brasilia USSR/Moscow
 * Incorrect rename, skip
 *
 * Пример 3
 *
 * Ввод
 *
 * 10
 * CHANGE_CAPITAL RussianEmpire Petrograd
 * RENAME USSR RussianEmpire
 * DUMP
 * ABOUT USSR
 * DUMP
 * RENAME RussianEmpire RussianEmpire
 * DUMP
 * CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
 * RENAME RussianEmpire UnitedStatesOfBrazil
 * DUMP
 *
 * Вывод
 *
 * Introduce new country RussianEmpire with capital Petrograd
 * Incorrect rename, skip
 * RussianEmpire/Petrograd
 * Country USSR doesn't exist
 * RussianEmpire/Petrograd
 * Incorrect rename, skip
 * RussianEmpire/Petrograd
 * Introduce new country UnitedStatesOfBrazil with capital Brasilia
 * Incorrect rename, skip
 * RussianEmpire/Petrograd UnitedStatesOfBrazil/Brasilia
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <map>

/*<-------------------------------------main------------------------------------->*/

int main() {
  std::map<std::string, std::string> countries;
  int count = 0;
  std::cin >> count;
  for (int i = 0; i < count; ++i) {
    std::string request;
    std::cin >> request;
    if (request == "CHANGE_CAPITAL") {
      std::string country, new_capital;
      std::cin >> country >> new_capital;
      if (countries.count(country) == 0) {
        std::cout << "Introduce new country " << country <<
                     " with capital " << new_capital;
      } else if (countries[country] == new_capital) {
        std::cout << "Country " << country << " hasn't changed its capital";
      } else {
        std::cout << "Country " << country << " has changed its capital from " <<
                     countries[country] << " to " << new_capital;
      }
      countries[country] = new_capital;
      std::cout << std::endl;
    } else if (request == "RENAME") {
      std::string old_country_name, new_country_name;
      std::cin >> old_country_name >> new_country_name;
      if (old_country_name == new_country_name or
          countries.count(old_country_name) == 0 or
          countries.count(new_country_name) == 1) {
        std::cout << "Incorrect rename, skip";
      } else {
        std::cout << "Country " << old_country_name << " with capital " <<
                  countries[old_country_name] << " has been renamed to " <<
                  new_country_name;
        countries[new_country_name] = countries[old_country_name];
        countries.erase(old_country_name);
      }
      std::cout << std::endl;
    } else if (request == "ABOUT") {
      std::string country;
      std::cin >> country;
      if (countries.count(country) == 0) {
        std::cout << "Country " << country << " doesn't exist";
      } else {
        std::cout << "Country " << country <<
                     " has capital " << countries[country];
      }
      std::cout << std::endl;
    } else if (request == "DUMP") {
      if (countries.empty()) {
        std::cout << "There are no countries in the world";
      } else {
        for (const auto& [key, value] : countries) {
          std::cout << key << '/' << value << " ";
        }
      }
      std::cout << std::endl;
    }
  }

  return 0;
}
