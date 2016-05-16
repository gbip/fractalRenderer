//
// Created by paul on 16/05/16.
//

#include "BiDimensionnalArray.h"
template <class T, int sizeX, int sizeY>
BiDimensionnalArray<T, sizeX, sizeY>::BiDimensionnalArray(): _sizeX(sizeX),
_sizeY(sizeY){

    _array = nullptr;

}

template <class T, int sizeX, int sizeY>
BiDimensionnalArray<T, sizeX, sizeY>::~BiDimensionnalArray() {

    _array = nullptr;

}

template <class T, int sizeX, int sizeY>
void BiDimensionnalArray<T, sizeX, sizeY>::setData(int X, int Y, T& value) {

    _array[X][Y] = value;

}

template <class T, int sizeX, int sizeY>
T& BiDimensionnalArray<T, sizeX, sizeY>::getData(int X, int Y) {

    return _array[X][Y];

}

template <class T, int sizeX, int sizeY>
int BiDimensionnalArray<T, sizeX, sizeY>::getSize(int dimension) {

    if (dimension==0)
        return _sizeX;
        else if(dimension == 1)
            return  _sizeY;
            else
        return nullptr;

}