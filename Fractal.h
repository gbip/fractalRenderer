//
// Created by paul on 16/05/16.
//

#ifndef FRACTALRENDERER_FRACTAL_H
#define FRACTALRENDERER_FRACTAL_H

#include "Math/MathHeader.h"
#include "Window.h"
#include <memory>
#include <vector>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <iostream>

template<int sizeX, int sizeY>
class Fractal {

public:
	Fractal(const int step) : _step(step) {}

	//Will draw the fractal on the window
	//template<int sizeX, int sizeY>
	void drawFractal(Window &window) {
		//Call computeFractal() to update the data
		computeFractal();

		sf::VertexArray drawnData(sf::Points , sizeX*sizeY);

		double test;


		for(int i = 0; i < _fractalArray.getSize(0); i++) {
			for(int j = 0; j < _fractalArray.getSize(1); j++) {
				//Represent the actual complex value of the point we are currently looking at after applying step times
				//the fractalFormula on it's original coordinates
				auto workingComplex = _fractalArray.getData(i,j);
				test = interpretResult(workingComplex);
				auto graphicData = window.gradientFunction(45.0);

			}
		}
		test = test/(_fractalArray.getSize(0)*_fractalArray.getSize(1));
		std::cout << "Result :" << test << std::endl;
	}


private:

	//will compute, for each element in the array, it's result through the recurrent suite defined in the function fractalFormula
	void computeFractal() {

		for(int i = 0; i < _complexArray.getSize(0); i++) {
			for(int j = 0; j < _complexArray.getSize(1); j++) {

				auto pointCoordInComplexSpace = (_complexArray.getData(i, j));

				auto zn = fractalFormula( Math::Complex{0,0}, pointCoordInComplexSpace);

                for (int k = 0; k < _step; k++) {
					zn = fractalFormula(zn, pointCoordInComplexSpace);
                }
				_fractalArray.setData(i, j, zn);
			}
		}
	};


	const int _step;

	// A bidimensionnal array with 1 slot for each pixel
	BiDimensionnalArray<Math::Complex, sizeX, sizeY> _complexArray;
	BiDimensionnalArray<Math::Complex, sizeX, sizeY> _fractalArray;

	// The formula used to compute the fractal
	Math::Complex fractalFormula(const Math::Complex& zn, const Math::Complex& c) {
		auto result = (zn * zn) + c;
		return result;
	}

	double interpretResult(const Math::Complex& data) {
		auto dataModule = Math::module(data);
		if (dataModule<2) {
			return dataModule/_step;
		}
		else {
			return 45;
		}
	};
};

#endif // FRACTALRENDERER_FRACTAL_H
