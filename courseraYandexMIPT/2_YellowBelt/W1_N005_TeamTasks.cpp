/*================================================================================*/
/*                    C++_Development_Basics: The_Yellow_Belt                     */
/*================================================================================*/
/*  Title: Team tasks                                                             */
/*  Start_time: 05.07.2022 10:37                                                  */
/*  End_time: 20.07.2022 19:38                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Реализуйте класс TeamTasks, позволяющий хранить статистику по статусам
 * задач команды разработчиков:
 *
 * // Перечислимый тип для статуса задачи
 * enum class TaskStatus {
 *   NEW,          // новая
 *   IN_PROGRESS,  // в разработке
 *   TESTING,      // на тестировании
 *   DONE          // завершена
 * };
 *
 * // Объявляем тип-синоним для map<TaskStatus, int>,
 * // позволяющего хранить количество задач каждого статуса
 * using TasksInfo = map<TaskStatus, int>;
 *
 * class TeamTasks {
 * public:
 *   // Получить статистику по статусам задач конкретного разработчика
 *   const TasksInfo& GetPersonTasksInfo(const string& person) const;
 *
 *   // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
 *   void AddNewTask(const string& person);
 *
 *   // Обновить статусы по данному количеству задач конкретного разработчика,
 *   // подробности см. ниже
 *   tuple<TasksInfo, TasksInfo> PerformPersonTasks(
 *                               const string& person, int task_count);
 * };
 *
 * Метод PerformPersonTasks должен реализовывать следующий алгоритм:
 *
 * 1. Рассмотрим все невыполненные задачи разработчика person.
 * 2. Упорядочим их по статусам: сначала все задачи в статусе NEW, затем все
 *    задачи в статусе IN_PROGRESS и, наконец, задачи в статусе TESTING.
 * 3. Рассмотрим первые task_count задач и переведём каждую из них в следующий
 *    статус в соответствии с естественным порядком:
 *    NEW -> IN_PROGRESS -> TESTING -> DONE
 * 4. Вернём кортеж из двух элементов: информацию о статусах обновившихся задач
 *    (включая те, которые оказались в статусе DONE) и информацию о статусах
 *    остальных не выполненных задач.
 *
 * В случае отсутствия разработчика с именем person метод PerformPersonTasks
 * должен вернуть кортеж из двух пустых TasksInfo
 *
 * Гарантируется, что task_count является положительным числом. Если task_count
 * превышает текущее количество невыполненных задач разработчика, достаточно
 * считать, что task_count равен количеству невыполненных задач: дважды
 * обновлять статус какой-либо задачи в этом случае не нужно.
 *
 * Кроме того, гарантируется, что метод GetPersonTasksInfo не будет вызван для
 * разработчика, не имеющего задач.
 *
 * Пример работы метода PerformPersonTasks:
 *
 * Предположим, что у конкретного разработчика имеется 10 задач со следующими
 * статусами:
 *
 * NEW - 3
 * IN_PROGRESS - 2
 * TESTING - 4
 * DONE - 1
 *
 * Поступает команда PerformPersonTasks с параметром task_count = 4, что
 * означает обновление статуса для 3 задач c NEW до IN_PROGRESS и для 1 задачи
 * с IN_PROGRESS до TESTING.
 * Если выписать статусы всех задач по порядку, а обновляемые заключить в
 * квадратные скобки, то изменение можно изобразить следующим образом:
 *
 * [NEW, NEW, NEW, IN_PROGRESS,] IN_PROGRESS, TESTING,
 * TESTING, TESTING, TESTING, DONE
 *
 * ==>
 *
 * [IN_PROGRESS, IN_PROGRESS, IN_PROGRESS, TESTING,] IN_PROGRESS, TESTING,
 * TESTING, TESTING, TESTING, DONE
 *
 * Таким образом, новые статусы задач будут следующими:
 *
 * IN_PROGRESS - 3 обновлённых, 1 старая
 * TESTING - 1 обновлённая, 4 старых
 * DONE - 1 старая
 *
 * В этом случае необходимо вернуть кортеж из 2 словарей:
 * - Обновлённые задачи: IN_PROGRESS - 3, TESTING - 1.
 * - Необновлённые задачи, исключая выполненные: IN_PROGRESS - 1, TESTING - 4.
 *
 * Ни один из словарей не должен содержать лишних элементов, то есть статусов,
 * которым соответствует ноль задач.
 *
 * По условию, DONE задачи не нужно возвращать в необновлённых задачах
 * (untouched_tasks).
 *
 * Примечание:
 *
 * Обновление словаря одновременно с итерированием по нему может привести к
 * непредсказуемым последствиям. При возникновении такой необходимости рекомендуется
 * сначала в отдельном временном словаре собрать информацию об обновлениях, а затем
 * применить их к основному словарю.
 *
 *
 * Пример кода
 *
 * // Принимаем словарь по значению, чтобы иметь возможность
 * // обращаться к отсутствующим ключам с помощью [] и получать 0,
 * // не меняя при этом исходный словарь
 * void PrintTasksInfo(TasksInfo tasks_info) {
 *   cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
 *     ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
 *     ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
 *     ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
 * }
 *
 * int main() {
 *   TeamTasks tasks;
 *   tasks.AddNewTask("Ilia");
 *   for (int i = 0; i < 3; ++i) {
 *     tasks.AddNewTask("Ivan");
 *   }
 *   cout << "Ilia's tasks: ";
 *   PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
 *   cout << "Ivan's tasks: ";
 *   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
 *
 *   TasksInfo updated_tasks, untouched_tasks;
 *
 *   tie(updated_tasks, untouched_tasks) =
 *     tasks.PerformPersonTasks("Ivan", 2);
 *   cout << "Updated Ivan's tasks: ";
 *   PrintTasksInfo(updated_tasks);
 *   cout << "Untouched Ivan's tasks: ";
 *   PrintTasksInfo(untouched_tasks);
 *
 *   tie(updated_tasks, untouched_tasks) =
 *     tasks.PerformPersonTasks("Ivan", 2);
 *   cout << "Updated Ivan's tasks: ";
 *   PrintTasksInfo(updated_tasks);
 *   cout << "Untouched Ivan's tasks: ";
 *   PrintTasksInfo(untouched_tasks);
 *
 *   return 0;
 * }
 *
 * Вывод
 *
 * Ilia's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
 * Ivan's tasks: 3 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
 * Updated Ivan's tasks: 0 new tasks, 2 tasks in progress, 0 tasks are being tested, 0 tasks are done
 * Untouched Ivan's tasks: 1 new tasks, 0 tasks in progress, 0 tasks are being tested, 0 tasks are done
 * Updated Ivan's tasks: 0 new tasks, 1 tasks in progress, 1 tasks are being tested, 0 tasks are done
 * Untouched Ivan's tasks: 0 new tasks, 1 tasks in progress, 0 tasks are being tested, 0 tasks are done
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <tuple>

// Перечислимый тип для статуса задачи
enum class TaskStatus {
  NEW,          // новая
  IN_PROGRESS,  // в разработке
  TESTING,      // на тестировании
  DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = std::map<TaskStatus, int>;

TaskStatus NextStatus(const TaskStatus& task_status) {
  return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
}

void RemoveZeros(TasksInfo& tasks_info) {
  std::vector<TaskStatus> statuses_to_remove;
  for (const auto& task_item : tasks_info) {
    if (task_item.second == 0) {
      statuses_to_remove.push_back(task_item.first);
    }
  }
  for (const TaskStatus status : statuses_to_remove) {
    tasks_info.erase(status);
  }
}

class TeamTasks {
public:
  // Получить статистику по статусам задач конкретного разработчика
  const TasksInfo& GetPersonTasksInfo(const std::string& person) const {
    return developers.at(person);
  }

  // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
  void AddNewTask(const std::string& person) {
    ++developers[person][TaskStatus::NEW];
  }

  // Обновить статусы по данному количеству задач конкретного разработчика,
  std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(const std::string& person,
                                                      int task_count) {
    TasksInfo updated;
    TasksInfo not_updated;

    TasksInfo& tasks = developers[person];

    for (TaskStatus status = TaskStatus::NEW;
         status != TaskStatus::DONE;
         status = NextStatus(status)) {
      updated[NextStatus(status)] = std::min(task_count, tasks[status]);
      task_count = task_count - updated[NextStatus(status)];
    }

    for (TaskStatus status = TaskStatus::NEW;
         status != TaskStatus::DONE;
         status = NextStatus(status)) {
      not_updated[status] = tasks[status] - updated[NextStatus(status)];
      tasks[status] += updated[status] - updated[NextStatus(status)];
    }

    tasks[TaskStatus::DONE] += updated[TaskStatus::DONE];

    RemoveZeros(updated);
    RemoveZeros(not_updated);
    RemoveZeros(developers.at(person));

    return {updated, not_updated};
  }

private:
  std::map<std::string, TasksInfo> developers;
};

void PrintTasksInfo(TasksInfo tasks_info) {
  std::cout << tasks_info[TaskStatus::NEW] << " new tasks"
            << ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress"
            << ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested"
            << ", " << tasks_info[TaskStatus::DONE] << " tasks are done"
            << std::endl;
 }

/*<-------------------------------------main------------------------------------->*/

int main() {
  TeamTasks tasks;
  tasks.AddNewTask("Ilia");

  for (int i = 0; i < 3; ++i) {
    tasks.AddNewTask("Ivan");
  }

  std::cout << "Ilia's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
  std::cout << "Ivan's tasks: ";
  PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

  TasksInfo updated_tasks, untouched_tasks;

  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);

  std::cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  std::cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ivan", 2);

  std::cout << "Updated Ivan's tasks: ";
  PrintTasksInfo(updated_tasks);
  std::cout << "Untouched Ivan's tasks: ";
  PrintTasksInfo(untouched_tasks);

  return 0;
}
