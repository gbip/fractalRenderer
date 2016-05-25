//
// Created by paul on 16/05/16.
//

#include <cmath>

namespace Math {

	// Struct representing a complex number
	struct Complex {
		double Real;
		double Imaginary;
		~Complex(){};
	};

	// Classic math operator
	inline Complex operator+(const Complex& a, const Complex& b) {
		return {a.Real + b.Real, a.Imaginary + b.Imaginary};
	}
	inline Complex operator*(const Complex& a, const Complex& b) {
		return {a.Real * b.Real - a.Imaginary * b.Imaginary, a.Real * b.Imaginary + a.Imaginary * b.Real};
	}

	inline Complex operator/(const Complex& a, const int &b) {
		return {a.Real/b, a.Imaginary/2};
	}

	inline Complex operator*(const Complex& a, const int &b) {
		return {a.Real*b, a.Imaginary*2};
	}
	// Return the module of a complex number
	const inline double module(const Complex& a) {
		return sqrt(pow(a.Real, 2) + pow(a.Imaginary, 2));
	};

	//Convert a complex to a string
	const inline std::string toString(const Complex& a) {
		return (std::to_string(a.Real) + " + " + std::to_string(a.Imaginary) + "i");
	}
}

