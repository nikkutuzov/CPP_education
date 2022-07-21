/*================================================================================*/
/*                    C++_Development_Basics: The_Yellow_Belt                     */
/*================================================================================*/
/*  Title: Program decomposition                                                  */
/*  Start_time: 21.07.2022 10:54                                                  */
/*  End_time: 21.07.2022 14:39                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 *
 * В курсе "Белый пояс по С++" у нас была задача "Автобусные остановки - 1".
 * https://www.coursera.org/learn/c-plus-plus-white/programming/Gi9dw/avtobusnyie-ostanovki-1
 * В этой задаче вам будет дано её правильное решение, целиком содержащееся внутри
 * функции main. Вам надо будет выполнить декомпозицию этого решения на заранее
 * заданные блоки так, чтобы получившаяся программа так же корректно решала задачу.
 * Условие задачи "Автобусные остановки - 1" приведено ниже.
 *
 * Исходные файлы:
 *
 * Авторское решение этой задачи содержится в файле:
 * correct.cpp
 * https://github.com/nikkutuzov/CPP_education/blob/master/courseraYandexMIPT/Templates/2_YB_W2_N001_decomposition/correct.cpp
 *
 * Кроме того, вам дан файл:
 * starter.cpp
 * https://github.com/nikkutuzov/CPP_education/blob/master/courseraYandexMIPT/Templates/2_YB_W2_N001_decomposition/starter.cpp
 * ...который содержит заготовки классов и функций. Не меняя функцию main, вам надо
 * реализовать эти классы и функции так, чтобы получившаяся программа решала задачу
 * "Автобусные остановки - 1".
 *
 * Как будет тестироваться ваша программа:
 *
 * Автоматическая проверяющая система заменит в вашей программе функцию main на ту,
 * которая дана вам в файле starter.cpp, скомпилирует получившийся файл и прогонит
 * на тестах для задачи "Автобусные остановки - 1".
 *
 * Условие задачи "Автобусные остановки - 1":
 *
 * Реализуйте систему хранения автобусных маршрутов.
 * Вам нужно обрабатывать следующие запросы:
 *
 * - NEW_BUS busstop_countstop1stop2 ... - добавить маршрут автобуса с названием bus
 *   и stop_count остановками с названиями stop1, stop2, ...
 * - BUSES_FOR_STOP stop - вывести названия всех маршрутов автобуса, проходящих
 *   через остановку stop.
 * - STOPS_FOR_BUS bus - вывести названия всех остановок маршрута bus со списком
 *   автобусов, на которые можно пересесть на каждой из остановок.
 * - ALL_BUSES - вывести список всех маршрутов с остановками.
 *
 * Формат ввода
 *
 * В первой строке ввода содержится количество запросов Q, затем в Q строках следуют
 * описания запросов.
 *
 * Гарантируется, что все названия маршрутов и остановок состоят лишь из латинских
 * букв, цифр и знаков подчёркивания.
 * Для каждого запроса NEW_BUS bus stop_count stop1stop2 ... гарантируется, что
 * маршрут bus отсутствует, количество остановок больше 0, а после числа stop_count
 * следует именно такое количество названий остановок, причём все названия в каждом
 * списке различны.
 *
 * Формат вывода
 *
 * Для каждого запроса, кроме NEW_BUS, выведите соответствующий ответ на него:
 * - На запрос BUSES_FOR_STOP stop выведите через пробел список автобусов,
 *   проезжающих через эту остановку, в том порядке, в котором они создавались
 *   командами NEW_BUS. Если остановка stop не существует, выведите No stop.
 * - На запрос STOPS_FOR_BUS bus выведите описания остановок маршрута bus в
 *   отдельных строках в том порядке, в котором они были заданы в соответствующей
 *   команде NEW_BUS. Описание каждой остановки stop должно иметь вид Stop stop:
 *   bus1bus2 ..., где bus1bus2 ... - список автобусов, проезжающих через остановку
 *   stop, в порядке, в котором они создавались командами NEW_BUS, за исключением
 *   исходного маршрута bus. Если через остановку stop не проезжает ни один автобус,
 *   кроме bus, вместо списка автобусов для неё выведите no interchange. Если
 *   маршрут bus не существует, выведите No bus.
 * - На запрос ALL_BUSES выведите описания всех автобусов в алфавитном порядке.
 *   Описание каждого маршрута bus должно иметь вид Bus bus: stop1stop2 ..., где
 *   stop1stop2 ... - список остановок автобуса bus в порядке, в котором они были
 *   заданы в соответствующей команде NEW_BUS. Если автобусы отсутствуют, выведите
 *   No buses.
 *
 * Пример
 *
 * Ввод
 *
 * 10
 * ALL_BUSES
 * BUSES_FOR_STOP Marushkino
 * STOPS_FOR_BUS 32K
 * NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
 * NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
 * BUSES_FOR_STOP Vnukovo
 * NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
 * NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
 * STOPS_FOR_BUS 272
 * ALL_BUSES
 *
 * Вывод
 *
 * No buses
 * No stop
 * No bus
 * 32 32K
 * Stop Vnukovo: 32 32K 950
 * Stop Moskovsky: no interchange
 * Stop Rumyantsevo: no interchange
 * Stop Troparyovo: 950
 * Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
 * Bus 32: Tolstopaltsevo Marushkino Vnukovo
 * Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
 * Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  std::string bus;
  std::string stop;
  std::vector<std::string> stops;
};

std::istream& operator >> (std::istream& is, Query& q) {
  std::string typeStr;
  is >> typeStr;
  if (typeStr == "NEW_BUS") {
    q.type = QueryType::NewBus;
    is >> q.bus;
    int stop_count = 0;
    is >> stop_count;
    q.stops.resize(stop_count);
    for (auto& stop : q.stops) {
      is >> stop;
    }
  } else if (typeStr == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  } else if (typeStr == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  } else if (typeStr == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  }

  return is;
}

struct BusesForStopResponse {
  std::vector<std::string> buses;
};

std::ostream& operator << (std::ostream& os, const BusesForStopResponse& r) {
  if (r.buses.empty()) {
    os << "No stop";
  } else {
    for (const auto& bus : r.buses) {
      os << bus << " ";
    }
  }

  return os;
}

struct StopsForBusResponse {
  std::string bus;
  std::vector<std::pair<std::string, std::vector<std::string>>> stops_for_buses;
};

std::ostream& operator << (std::ostream& os, const StopsForBusResponse& r) {
   if (r.stops_for_buses.empty()) {
    os << "No bus";
  } else {
    for (const auto& [key, value] : r.stops_for_buses) {
      os << "Stop " << key << ": ";
      if (value.size() == 1) {
        os << "no interchange" << std::endl;;
      } else {
        for (const auto& bus : value) {
          if (bus != r.bus) {
            os << " " << bus;
          }
        }
        os << std::endl;
      }
    }
  }

  return os;
}

struct AllBusesResponse {
  std::map<std::string, std::vector<std::string>> buses_for_stops;
};

std::ostream& operator << (std::ostream& os, const AllBusesResponse& r) {
  if (r.buses_for_stops.empty()) {
    os << "No buses";
  } else {
    for (const auto& [key, value] : r.buses_for_stops) {
      os << "Bus " << key << ":";
      for (const auto& stop : value) {
        os << " " << stop;
      }
      os << std::endl;
    }
  }

  return os;
}

class BusManager {
public:
  void AddBus(const std::string& bus, const std::vector<std::string>& stops) {
    buses_for_stop.insert(std::make_pair(bus, stops));
    for (const auto& stop : stops) {
      stops_for_bus[stop].push_back(bus);
    }
  }

  BusesForStopResponse GetBusesForStop(const std::string& stop) const {
    if (stops_for_bus.count(stop) == 0) {
      return BusesForStopResponse{std::vector<std::string>()};
    } else {
      return BusesForStopResponse{stops_for_bus.at(stop)};
    }
  }

  StopsForBusResponse GetStopsForBus(const std::string& bus) const {
    std::vector<std::pair<std::string, std::vector<std::string>>> result;

    if (buses_for_stop.count(bus) > 0) {
      for (const auto& stop : buses_for_stop.at(bus)) {
        result.push_back(std::make_pair(stop, stops_for_bus.at(stop)));
      }
    }

    return StopsForBusResponse{bus, result};
  }

  AllBusesResponse GetAllBuses() const {
    return AllBusesResponse{buses_for_stop};
  }

private:
  std::map<std::string, std::vector<std::string>> buses_for_stop;
  std::map<std::string, std::vector<std::string>> stops_for_bus;
};

/*<-------------------------------------main------------------------------------->*/

int main() {
  int query_count;
  Query q;

  std::cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    std::cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      std::cout << bm.GetBusesForStop(q.stop) << std::endl;
      break;
    case QueryType::StopsForBus:
      std::cout << bm.GetStopsForBus(q.bus) << std::endl;
      break;
    case QueryType::AllBuses:
      std::cout << bm.GetAllBuses() << std::endl;
      break;
    }
  }

  return 0;
}
