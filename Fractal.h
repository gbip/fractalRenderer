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
        Fractal() : _sizeX(sizeX),
                    _sizeY(sizeY) {}
    BiDimensionnalArray<Math::Complex, sizeX, sizeY> computeFractal(){

        BiDimensionnalArray<Math::Complex, sizeX, sizeY> result;

        for (int i = 0; i < _complexArray.getSize(0); i++) {
            for (int j = 0; j < _complexArray.getSize(1); i++) {
                result.setData(i, j, fractalFormula(_complexArray.getData(i,j)));
            }
        }
        return result;
    };

private:

    const int _sizeX;
    const int _sizeY;
    BiDimensionnalArray<Math::Complex, sizeX, sizeY> _complexArray;


    Math::Complex& fractalFormula(Math::Complex input) {
        Math::Complex result =(input*input);
        return result;
    }

};


#endif //FRACTALRENDERER_FRACTAL_H
