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
#include <cmath>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

template<int sizeX, int sizeY>
class Fractal {

public:
	Fractal(const int step) : _step(step) {

		_complexArray = std::make_unique<BiDimensionnalArray<Math::Complex, sizeX, sizeY>>();
		_fractalArray = std::make_unique<BiDimensionnalArray<stepAndFinalValue, sizeX, sizeY>>();
	}

	~Fractal() {
	}
	//Will draw the fractal on the window
	//template<int sizeX, int sizeY>
	sf::Texture drawFractal() {

		//Call computeFractal() to update the data
		computeFractal();

		sf::Image renderImage;
		sf::Texture texture;

		renderImage.create(sizeX, sizeY);


		for(int i = 0; i < _fractalArray->getSize(0); ++i) {
			for(int j = 0; j < _fractalArray->getSize(1); ++j) {
				//Represent the actual complex value of the point we are currently looking at after applying step times
				//the fractalFormula on it's original coordinates
				auto workingComplex = _fractalArray->getData(i,j);
				sf::Color pixelColor = interpretResult(workingComplex);
				renderImage.setPixel(i,j, pixelColor);
			}
		}

		if (texture.loadFromImage(renderImage, sf::Rect<int>(0,0,sizeX,sizeY)))
			std::cout << "Texture : OK" << std::endl;
		texture.update(renderImage);
		std::cout << "Done \n" ;
		return texture;
	}

	sf::Texture test_rescale(){
		sf::Image renderImage;
		sf::Texture texture;

		renderImage.create(sizeX, sizeY);


		for(int i = 0; i < _fractalArray->getSize(0); ++i) {
			for(int j = 0; j < _fractalArray->getSize(1); ++j) {
				//Represent the actual complex value of the point we are currently looking at after applying step times
				//the fractalFormula on it's original coordinates
				auto workingComplex = _complexArray->getData(i,j);
				//sf::Color pixelColor = interpretResult(workingComplex);
				unsigned char red = static_cast<unsigned char>(fabs(workingComplex.Real) * 100);
				unsigned char green = static_cast<unsigned char>(fabs(workingComplex.Imaginary) * 100);
				unsigned char blue = 0;
				sf::Color pixelColor = {red, green,blue};
				renderImage.setPixel(i,j, pixelColor);
			}
		}

		if (texture.loadFromImage(renderImage, sf::Rect<int>(0,0,sizeX,sizeY)))
			std::cout << "Texture : OK" << std::endl;
		texture.update(renderImage);
		std::cout << "Done \n" ;
		return texture;
	};


	//Will interpolate all the points in the complex plan being given the 2 extremum of the window
	void rescale(const Math::Complex& origin, const Math::Complex& maximum) {

		for(int i = 0; i < _complexArray->getSize(0); ++i) {

			for(int j = 0; j < _complexArray->getSize(1); ++j) {

				//Interpolating all the points
				double realPart = double(i)/(sizeX-1) * maximum.Real + origin.Real * double(sizeX-1 - i)/sizeX;
				double imaginaryPart = double(j)/(sizeY-1) * maximum.Imaginary + origin.Imaginary * double(sizeY-1 -j)/sizeY;

				Math::Complex result = {realPart, imaginaryPart};

				_complexArray->setData(i, j, result);

			}
		}
	}


private:
	//A simple struct
	struct stepAndFinalValue {
		Math::Complex complex;
		int  step;
	};


	//will compute, for each element in the array, it's result through the recurrent suite defined in the function fractalFormula
	void computeFractal() {

		for(int i = 0; i < _complexArray->getSize(0); i++) {
			for(int j = 0; j < _complexArray->getSize(1); j++) {

				Math::Complex pointCoordInComplexSpace = _complexArray->getData(i, j);

				auto zn = fractalFormula( Math::Complex{0,0}, pointCoordInComplexSpace);
				int iterator = 0;
                while(iterator < _step) {
					++iterator;
					zn = fractalFormula(zn, pointCoordInComplexSpace);
                }
				_fractalArray->setData(i, j, {zn, iterator});
			}
		}
	};



	const int _step;

	// A bidimensionnal array with 1 complex number slot for each pixel containing the point coordinate
	std::unique_ptr<BiDimensionnalArray<Math::Complex, sizeX, sizeY>> _complexArray;


	std::unique_ptr<BiDimensionnalArray<stepAndFinalValue, sizeX, sizeY>> _fractalArray;


	// The formula used to compute the fractal
	Math::Complex fractalFormula(const Math::Complex& zn, const Math::Complex& c) {
		Math::Complex result = (zn * zn) + c;
		return result;
	}

	sf::Color interpretResult(const stepAndFinalValue& data) {
		auto dataModule = Math::module(data.complex);
		if (dataModule<2) {
			return sf::Color::Black;
			//return sf::Color(dataModule/data.step * 100, data.step/dataModule, 45);
		}
		else {
			return sf::Color::White;
		}
	};

};

#endif // FRACTALRENDERER_FRACTAL_H
