//
// Created by paul on 16/05/16.
//

#ifndef FRACTALRENDERER_BIDIMENSIONNALARRAY_H
#define FRACTALRENDERER_BIDIMENSIONNALARRAY_H


#include <assert.h>

template <class T, int sizeX, int sizeY> class BiDimensionnalArray {
public:


    BiDimensionnalArray() {}

    ~BiDimensionnalArray() {
        delete[] _array;
    }

    void setData(int X, int Y, T& value) {
        _array[X][Y] = value;
    }

    T& getData(int X, int Y) {
        return _array[X][Y];
    }

    int getSize(int dimension) {

        assert(dimension == 0 || dimension == 1);

        if (dimension==0)
            return sizeX;
        else if(dimension == 1)
            return  sizeY;
            else return 0;
    }

private:

    T _array[sizeX][sizeY];

};


#endif //FRACTALRENDERER_BIDIMENSIONNALARRAY_H
