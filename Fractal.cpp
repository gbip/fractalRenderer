//
// Created by paul on 16/05/16.
//

#include "Fractal.h"

template <int sizeX, int sizeY>
Fractal<sizeX,sizeY>::Fractal(): _sizeX(sizeX),
_sizeY(sizeY) { }


template <int sizeX, int sizeY>
BiDimensionnalArray<Math::Complex, sizeX, sizeY> Fractal<sizeX, sizeY>::computeFractal() {

    BiDimensionnalArray<Math::Complex, sizeX, sizeY> result;

    for (int i = 0; i < _complexArray.getSize(0); i++) {
        for (int j = 0; j < _complexArray.getSize(1); i++) {
        result.setData(i, j, fractalFormula(_complexArray.getData(i,j)));
        }
    }

}