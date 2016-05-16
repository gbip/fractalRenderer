//
// Created by paul on 16/05/16.
//

#ifndef FRACTALRENDERER_FRACTAL_H
#define FRACTALRENDERER_FRACTAL_H

#include <SFML/Graphics/Color.hpp>
#include <vector>
#include <functional>
#include "Math/MathHeader.h"

template <int sizeX, int sizeY> class Fractal {

public:
        Fractal();
    BiDimensionnalArray<Math::Complex, sizeX, sizeY> computeFractal();

private:

    const int _sizeX;
    const int _sizeY;
    BiDimensionnalArray<Math::Complex, sizeX, sizeY> _complexArray;


    Math::Complex fractalFormula(Math::Complex input) {
        return (input*input);
    }

};


#endif //FRACTALRENDERER_FRACTAL_H
