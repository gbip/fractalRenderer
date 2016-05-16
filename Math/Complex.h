//
// Created by paul on 16/05/16.
//

#include <cmath>

namespace Math {

    //Struct representing a complex number
    struct Complex {
        double Real;
        double Imaginary;

        Complex operator*(Complex a) {return {this->Real * a.Real - this->Imaginary * a.Imaginary, this->Real * a.Real + this->Imaginary * a.Imaginary};}
    };

    //Classic math operator
    //Complex operator+(Complex a, Complex b) {return {a.Real + b.Real, a.Imaginary + b.Imaginary};}

    //Return the module of a complex number
    //double module(Complex a) { return sqrt((a.Real,2) + pow(a.Imaginary, 2));};
}

