//
// Created by paul on 16/05/16.
//

#ifndef FRACTALRENDERER_FRACTAL_H
#define FRACTALRENDERER_FRACTAL_H

#include <SFML/Graphics/Color.hpp>
#include <vector>
#include <functional>
#include <memory>
#include "Math/MathHeader.h"

template <int sizeX, int sizeY> class Fractal {

public:
  Fractal() : _sizeX(sizeX), _sizeY(sizeY) {}
  BiDimensionnalArray<Math::Complex, sizeX, sizeY> computeFractal() {

    BiDimensionnalArray<Math::Complex, sizeX, sizeY> result;

    for (int i = 0; i < _complexArray.getSize(0); i++) {
      for (int j = 0; j < _complexArray.getSize(1); i++) {
        auto temp = (_complexArray.getData(i, j).get());
        *temp = fractalFormula(temp);
        result.setData(i, j, *temp);
      }
    }
    return result;
  };

private:
  const int _sizeX;
  const int _sizeY;

  // A bidimensionnal array with 1 slot for each pixel
  BiDimensionnalArray<std::shared_ptr<Math::Complex>, sizeX, sizeY>
      _complexArray;

  // The formula used to compute the fractal
  Math::Complex fractalFormula(const Math::Complex *input) {
    auto result = (*input * *input);
    return result;
  }
};

#endif // FRACTALRENDERER_FRACTAL_H
