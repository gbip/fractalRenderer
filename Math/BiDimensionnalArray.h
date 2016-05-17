//
// Created by paul on 16/05/16.
//

#ifndef FRACTALRENDERER_BIDIMENSIONNALARRAY_H
#define FRACTALRENDERER_BIDIMENSIONNALARRAY_H

#include <assert.h>

// A template classe representing a bidimensionnal array
template <class T, int sizeX, int sizeY> class BiDimensionnalArray {
public:
  BiDimensionnalArray() {}

  // Delete the array
  ~BiDimensionnalArray() {}

  // Set the value at the slot (X,Y)
  void setData(const int &X, const int &Y, T &value) { _array[X][Y] = value; }

  // Return the value at the slot (X,Y)
  T &getData(const int &X, const int &Y) { return _array[X][Y]; }

  // Return the size of the dimension
  int getSize(const int &dimension) {

    assert(dimension == 0 || dimension == 1);

    if (dimension == 0)
      return sizeX;
    else if (dimension == 1)
      return sizeY;
    else
      return 0;
  }

private:
  T _array[sizeX][sizeY];
};

#endif // FRACTALRENDERER_BIDIMENSIONNALARRAY_H
