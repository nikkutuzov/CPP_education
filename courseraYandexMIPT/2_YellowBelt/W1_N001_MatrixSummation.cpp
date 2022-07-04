/*================================================================================*/
/*                    C++_Development_Basics: The_Yellow_Belt                     */
/*================================================================================*/
/*  Title: Matrix summation                                                       */
/*  Start_time: 04.07.2022 15:26                                                  */
/*  End_time: 04.07.2022 18:06                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Предисловие
 *
 * Если вы не уверены, стоит ли вам сначала пройти наш первый курс, или у вас
 * достаточно знаний, чтобы начать с "Жёлтого пояса", попробуйте решить эту задачу.
 * Если вы не понимаете её условие или не можете быстро решить, скорее всего, вам
 * надо сначала пройти "Белый пояс"
 *
 * Условие
 *
 * В этой задаче вам надо разработать класс Matrix для представления целочисленной
 * матрицы. Более подробно, класс Matrix должен иметь:
 *
 * - конструктор по умолчанию, который создаёт матрицу с нулём строк и нулём
 *   столбцов
 * - конструктор от двух целочисленных параметров: num_rows и num_cols, - которые
 *   задают количество строк и столбцов матрицы соответственно
 * - метод Reset, принимающий два целочисленных параметра, которые задают новое
 *   количество строк и столбцов матрицы соответственно; метод Reset меняет размеры
 *   матрицы на заданные и обнуляет все её элементы
 * - константный метод At, который принимает номер строки и номер столбца (именно в
 *   этом порядке; нумерация строк и столбцов начинается с нуля) и возвращает
 *   значение в соответствущей ячейке матрицы
 * - неконстантный метод At с такими же параметрами, но возвращающий ссылку на
 *   значение в соответствущей ячейке матрицы
 * - константные методы GetNumRows и GetNumColumns, которые возвращают количество
 *   строк и столбцов матрицы соответственно
 *
 * Если количество строк или количество столбцов, переданное в конструктор класса
 * Matrix или метод Reset, оказалось отрицательным, то должно быть выброшено
 * стандартное исключение out_of_range.
 *
 * Это же исключение должен бросать метод At, если переданная в него ячейка выходит
 * за границы матрицы.
 *
 * Кроме того, для класса Matrix должны быть определены следующие операторы:
 *
 * - оператор ввода из потока istream; формат ввода простой - сначала задаётся
 *   количество строк и столбцов (именно в этом порядке), а затем все элементы
 *   матрицы: сначала элемент первой строки и первого столбца, затем элемент первой
 *   строки и второго столбца и так далее
 * - оператор вывода в поток ostream; он должен выводить матрицу в том же формате,
 *   в каком её читает оператор ввода, - в первой строке количество строк и
 *   столбцов, во второй - элементы первой строки, в третьей - элементы второй
 *   строки и т.д.
 * - оператор проверки на равенство (==): он должен возвращать true, если
 *   сравниваемые матрицы имеют одинаковый размер и все их соответствующие элементы
 *   равны между собой, в противном случае он должен возвращать false.
 * - оператор сложения: он должен принимать две матрицы и возвращать новую матрицу,
 *   которая является их суммой; если переданные матрицы имеют разные размеры этот
 *   оператор должен выбрасывать стандартное исключение invalid_argument.
 *
 * Вам дана заготовка решения, а также пример ввода и вывода. Когда вы реализуете
 * класс Matrix, вы можете использовать этот пример, чтобы убедиться, что ваш код
 * работает правильно.
 *
 * Важно! Пример не проверяет выполнение всех требований, приведённых в условии.
 *
 * Примечание
 *
 * Матрицы с нулём строк или нулём столбцов считаются пустыми. Любые две пустые
 * матрицы равны. Сумма двух пустых матриц также является пустой матрицей.
 *
 * Автор задачи - Дмитрий Минченко
 *
 * Файл с заготовкой решения задачи
 *
 * https://github.com/nikkutuzov/CPP_education/blob/master/courseraYandexMIPT/Templates/2_YB_W1_N001_MatrixSummation/matrix_sum.cpp
 *
 * Пример ввода
 *
 * 3 5
 * 6 4 -1 9 8
 * 12 1 2 9 -5
 * -4 0 12 8 6
 *
 * 3 5
 * 5 1 0 -8 23
 * 14 5 -6 6 9
 * 8 0 5 4 1
 *
 * Пример вывода
 *
 * 3 5
 * 11 5 -1 1 31
 * 26 6 -4 15 4
 * 4 0 17 12 7
 *
 */

/*<=====================================CODE=====================================>*/

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

/*<---------------------------------class_Matrix--------------------------------->*/
class Matrix {
public:
  Matrix() {
    rows = 0;
    columns = 0;
  }

  Matrix(const int num_rows, const int num_cols) {
    Reset(num_rows, num_cols);
  }

  void Reset(const int num_rows, const int num_cols) {
    if (num_rows < 0) {
      throw std::out_of_range("num_rows must be >= 0");
    }
    if (num_cols < 0) {
      throw std::out_of_range("num_columns must be >= 0");
    }
    if (num_rows == 0 or num_cols == 0) {
      rows = columns = 0;
    } else {
      rows = num_rows;
      columns = num_cols;
    }

    matrix_numbers.assign(num_rows, std::vector<int>(num_cols));
  }

  int At(const int number_of_row, const int number_of_col) const {
    return matrix_numbers.at(number_of_row).at(number_of_col);
  }

  int& At(const int number_of_row, const int number_of_col) {
    return matrix_numbers.at(number_of_row).at(number_of_col);
  }

  int GetNumRows() const {
    return rows;
  }

  int GetNumColumns() const {
    return columns;
  }

private:
  int rows;
  int columns;

  std::vector<std::vector<int>> matrix_numbers;
};

/*<----------------------------operators_overloading----------------------------->*/

std::istream& operator>> (std::istream& stream, Matrix& matrix) {
  int rows_count;
  int cols_count;

  stream >> rows_count >> cols_count;

  matrix.Reset(rows_count, cols_count);

  for (int i = 0; i < rows_count; ++i) {
    for (int j = 0; j < cols_count; ++j) {
      stream >> matrix.At(i, j);
    }
  }

  return stream;
}

std::ostream& operator<< (std::ostream& stream, const Matrix& matrix) {
  const int rows_count = matrix.GetNumRows();
  const int cols_count = matrix.GetNumColumns();

  stream << rows_count << ' ' << cols_count << std::endl;

  for (int i = 0; i < rows_count; ++i) {
    for (int j = 0; j < cols_count; ++j) {
      if (j > 0) {
        stream << ' ';
      }
      stream << matrix.At(i, j);
    }
    stream << std::endl;
  }

  return stream;
}

bool operator== (const Matrix& lhs, const Matrix& rhs) {
  if (lhs.GetNumRows() != rhs.GetNumRows() or
      lhs.GetNumColumns() != rhs.GetNumColumns()) {
    return false;
  }

  const int rows_count = lhs.GetNumRows();
  const int cols_count = lhs.GetNumColumns();

  for (int i = 0; i < rows_count; ++i) {
    for (int j = 0; j < cols_count; ++j) {
      if (lhs.At(i, j) != rhs.At(i, j)) {
        return false;
      }
    }
  }

  return true;
}

Matrix operator+ (const Matrix& lhs, const Matrix& rhs) {
  if (lhs.GetNumRows() != rhs.GetNumRows()) {
    throw std::invalid_argument("Mismatched number of rows");
  }

  if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
    throw std::invalid_argument("Mismatched number of columns");
  }

  const int rows_count = lhs.GetNumRows();
  const int cols_count = lhs.GetNumColumns();
  Matrix result(rows_count, cols_count);

  for (int i = 0; i < rows_count; ++i) {
    for (int j = 0; j < cols_count; ++j) {
      result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
    }
  }

  return result;
}

/*<------------------------------------main-------------------------------------->*/

int main() {
  Matrix one;
  Matrix two;

  std::cin >> one >> two;
  std::cout << one + two << std::endl;

  return 0;
}
