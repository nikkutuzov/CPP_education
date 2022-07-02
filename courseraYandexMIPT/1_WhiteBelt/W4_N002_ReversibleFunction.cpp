/*================================================================================*/
/*                    C++_Development_Basics: The_White_Belt                      */
/*================================================================================*/
/*  Title: Reversible function                                                    */
/*  Start_time: 30.06.2022 19:53                                                  */
/*  End_time: 02.07.2022 12:00                                                    */
/*  Note:                                                                         */
/*================================================================================*/

/*<===============================Problem_Statement==============================>*/

/*
 * Реализуйте рассказанный на лекции класс Function
 * https://github.com/nikkutuzov/CPP_education/blob/master/courseraYandexMIPT/Video/class_ReversibleFunction(class_Function).mov
 * позволяющий создавать, вычислять и инвертировать функцию, состоящую из следующих
 * элементарных операций:
 *
 * - прибавить вещественное число x;
 * - вычесть вещественное число x.
 * При этом необходимо объявить константными все методы, которые по сути такими
 * являются.
 *
 * Замечание
 *
 * Более детальное описание задачи с подробным разбором реализации вышеуказанного
 * класса приводится в двух предшествующих видеолекциях.
 *
 * На проверку пришлите файл, содержащий реализацию вышеуказанного класса Function.
 *
 * Пример
 *
 * Код
 *
 * struct Image {
 *  double quality;
 *  double freshness;
 *  double rating;
 * };
 *
 * struct Params {
 *  double a;
 *  double b;
 *  double c;
 * };
 *
 * Function MakeWeightFunction(const Params& params,
 *                             const Image& image) {
 *  Function function;
 *  function.AddPart('-', image.freshness * params.a + params.b);
 *  function.AddPart('+', image.rating * params.c);
 *  return function;
 *  }
 *
 * double ComputeImageWeight(const Params& params, const Image& image) {
 *  Function function = MakeWeightFunction(params, image);
 *  return function.Apply(image.quality);
 * }
 *
 * double ComputeQualityByWeight(const Params& params,
 *                               const Image& image,
 *                               double weight) {
 *  Function function = MakeWeightFunction(params, image);
 *  function.Invert();
 *  return function.Apply(weight);
 * }
 *
 * int main() {
 *  Image image = {10, 2, 6};
 *  Params params = {4, 2, 6};
 *  cout << ComputeImageWeight(params, image) << endl;
 *  cout << ComputeQualityByWeight(params, image, 46) << endl;
 * return 0;
 * }
 *
 * Вывод
 *
 * 36
 * 20
 *
 */

/*<=====================================CODE=====================================>*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Image {
  double quality;
  double freshness;
  double rating;
};

struct Params {
  double a;
  double b;
  double c;
};

class FunctionPart {
public:
  FunctionPart(char new_operation, double new_value) {
    value = new_value;
    operation = new_operation;
  }

  double Apply(double source_value) const {
    if (operation == '+') {
      return source_value + value;
    } else {
      return source_value - value;
    }
  }

  void Invert() {
    if (operation == '+') {
      operation = '-';
    } else {
      operation = '+';
    }
  }

private:
  char operation;
  double value;
};

class Function {
public:
  void AddPart(char operation, double value) {
    parts.push_back({operation, value});
  }

  double Apply(double value) const {
    for (const FunctionPart& part : parts) {
      value = part.Apply(value);
    }
    return value;
  }
  void Invert() {
    for (FunctionPart& part : parts) {
      part.Invert();
    }
    std::reverse(begin(parts), end(parts));
  }

private:
  std::vector<FunctionPart> parts;
};

Function MakeWeightFunction(const Params& params,
                            const Image& image) {
  Function function;
  function.AddPart('-', image.freshness * params.a + params.b);
  function.AddPart('+', image.rating * params.c);

  return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
                              const Image& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

/*<-------------------------------------main------------------------------------->*/

int main() {
  Image image = {10, 2, 6};
  Params params = {4, 2, 6};
  std::cout << ComputeImageWeight(params, image) << std::endl;
  std::cout << ComputeQualityByWeight(params, image, 46) << std::endl;

  return 0;
}
