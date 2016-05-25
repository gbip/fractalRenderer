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
	Fractal()  {

		_complexArray = std::make_unique<BiDimensionnalArray<Math::Complex, sizeX, sizeY>>();
		_fractalArray = std::make_unique<BiDimensionnalArray<stepAndFinalValue, sizeX, sizeY>>();
	}

	~Fractal() {
	}
	//Will draw the fractal on the window
	//template<int sizeX, int sizeY>
	sf::Texture drawFractal(int step) {

		//Call computeFractal() to update the data
		computeFractal(step);

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
			texture.update(renderImage);
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
	//void rescale(const Math::Complex& origin, const Math::Complex& maximum) {

	void setNewRenderArea(int posX, int posY, float zoomFactor) {
		double half_width = sizeX / zoomFactor;
		double half_height = sizeY / zoomFactor;

		auto topLeftCorner = sf::Vector2<double>{posX - half_height, posY - half_width};
		auto bottomRightCorner = sf::Vector2<double>{posX + half_height, posY + half_width};

		Math::Complex newOrigin = {topLeftCorner.x/sizeX * fabs(_origin.Real-_maximum.Real), topLeftCorner.y/sizeY * fabs(_origin.Imaginary - _maximum.Imaginary)};

		/*
		Math::Complex newOrigin = {
				topLeftCorner.x / (sizeX - 1) * _maximum.Real + _origin.Real * topLeftCorner.x - 1 - posX / sizeX,
				topLeftCorner.y / (sizeY - 1) * _maximum.Imaginary + _origin.Imaginary * topLeftCorner.y - 1 -
				posY / sizeY};
				*/
		std::cout << "New Origin " << Math::toString(newOrigin) << std::endl;


		Math::Complex newMaximum = {bottomRightCorner.x/sizeX * fabs(_origin.Real-_maximum.Real), bottomRightCorner.y/sizeY * fabs(_origin.Imaginary - _maximum.Imaginary)};

		/*Math::Complex newMaximum = {
				bottomRightCorner.x / (sizeX - 1) * _maximum.Real + _origin.Real * bottomRightCorner.x - 1 -
				posX / sizeX,
				bottomRightCorner.y / (sizeY - 1) * _maximum.Imaginary + _origin.Imaginary * bottomRightCorner.y - 1 -
				posY / sizeY};
				*/

		std::cout << "New Origin " << Math::toString(newMaximum) << std::endl;

		mapWindowTo(newOrigin, newMaximum);
	}

	//Will interpolate all the points in the complex plan being given the 2 extremum of the window
	void interpolatePoints() {
		for(int i = 0; i < _complexArray->getSize(0); ++i) {

			for(int j = 0; j < _complexArray->getSize(1); ++j) {

				//Interpolating all the points
				double realPart = double(i)/(sizeX-1) * _maximum.Real + _origin.Real * double(sizeX-1 - i)/sizeX;
				double imaginaryPart = double(j)/(sizeY-1) * _maximum.Imaginary + _origin.Imaginary * double(sizeY-1 -j)/sizeY;
				Math::Complex result = {realPart, imaginaryPart};
				_complexArray->setData(i, j, result);

			}
		}
	}

	Math::Complex getOrigin() {
		return _origin;
	}
	Math::Complex getMaximum() {
		return  _maximum;
	}

	void mapWindowTo(Math::Complex origin, Math::Complex maximum) {
		_origin = origin;
		_maximum = maximum;
	}


private:

	//A simple struct
	struct stepAndFinalValue {
		Math::Complex complex;
		int  step;
	};

	// A bidimensionnal array with 1 complex number slot for each pixel containing the point coordinate
	std::unique_ptr<BiDimensionnalArray<Math::Complex, sizeX, sizeY>> _complexArray;

	// A bidimensionnal array wich contain all the term of the recurrent suite defined in fractal formula
	std::unique_ptr<BiDimensionnalArray<stepAndFinalValue, sizeX, sizeY>> _fractalArray;

	//A pair of point representing, respectively the top left corner and the bottom right corner of the complex plane
	Math::Complex _origin;
	Math::Complex _maximum;



	//will compute, for each element in the array, it's result through the recurrent suite defined in the function fractalFormula
	void computeFractal(int step) {

		for(int i = 0; i < _complexArray->getSize(0); i++) {
			for(int j = 0; j < _complexArray->getSize(1); j++) {

				Math::Complex pointCoordInComplexSpace = _complexArray->getData(i, j);

				auto zn = fractalFormula( Math::Complex{0,0}, pointCoordInComplexSpace);
				int iterator = 0;
                while(iterator < step) {
					++iterator;
					zn = fractalFormula(zn, pointCoordInComplexSpace);
                }
				_fractalArray->setData(i, j, {zn, iterator});
			}
		}
	};


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
