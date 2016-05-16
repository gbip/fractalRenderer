//
// Created by paul on 16/05/16.
//

#ifndef FRACTALRENDERER_BIDIMENSIONNALARRAY_H
#define FRACTALRENDERER_BIDIMENSIONNALARRAY_H


template <class T, int sizeX, int sizeY> class BiDimensionnalArray {
public:
    BiDimensionnalArray();
    ~BiDimensionnalArray();

    void setData(int X, int Y, T& value);

    T& getData(int X, int Y);

    int getSize(int dimension);

private:

    T _array[sizeX][sizeY];
    int _sizeX;
    int _sizeY;

};


#endif //FRACTALRENDERER_BIDIMENSIONNALARRAY_H
