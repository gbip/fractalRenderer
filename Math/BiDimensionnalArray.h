//
// Created by paul on 16/05/16.
//

#ifndef FRACTALRENDERER_BIDIMENSIONNALARRAY_H
#define FRACTALRENDERER_BIDIMENSIONNALARRAY_H

#include <assert.h>
#include <memory>
#include <vector>
#include <iostream>

// A template classe representing a bidimensionnal array
template <typename T, const int sizeX, const int sizeY>
class BiDimensionnalArray {
public:

	BiDimensionnalArray() : _sizeX(sizeX), _sizeY(sizeY), _array{}{
		for(size_t i = 0; i < sizeX; ++i) {
			_array[i] = {};
			for(size_t j = 0; j < sizeY; ++j) {
				_array[i][j] = {{0},{0}};
			}
		}

	};

	// Delete the array
	~BiDimensionnalArray() {}

	// Set the value at the slot (X,Y)
	void setData(const int& X, const int& Y, T value) {
		_array[X][Y] = value;
	}

	// Return the value at the slot (X,Y)
	T getData(const int& X, const int& Y) {
		return _array.at(X).at(Y);
	}

	// Return the size of the dimension
	int getSize(const int& dimension) {

		assert(dimension == 0 || dimension == 1);

		if(dimension == 0)
			return _sizeX;
		else if(dimension == 1)
			return _sizeY;
		else
			return 0;
	}

private:

	int _sizeX;
	int _sizeY;
	std::array<std::array<T,sizeY>,sizeX> _array;
};

#endif // FRACTALRENDERER_BIDIMENSIONNALARRAY_H
