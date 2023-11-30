#pragma once
#include <math.h>
#include <iostream>

using namespace std;

class Complex {
	double real, imag;
public:
	Complex();
	Complex(double r, double i) {
		real = r;
		imag = i;
	};
	void setVals(double r, double i) {
		real = r;
		imag = i;
	};
	double getReal() {
		return real;
	}; // Return real part
	double getImag() {
		return imag;
	}; // Return imaginary part
	double getMag() {
		return sqrt(real * real + imag * imag);
	}; // Return magnitude
	Complex operator+(Complex c); // Add two complex numbers
	Complex operator-(Complex c); // Subtract two complex numbers
	Complex operator*(Complex c); // Multiply two complex numbers
	Complex operator/(Complex c); // Divide two complex numbers
};

Complex::Complex() {
	real = 0;
	imag = 0;
}

ostream& operator<<(ostream& out, Complex c) {
	if (c.getImag() >= 0)
		return out << c.getReal() << " + " << c.getImag() << "i";
	else
		return out << c.getReal() << " - " << -1 * c.getImag() << "i";
}; // Write c to the output stream out

Complex Complex::operator+(Complex c) {
	Complex temp;
	temp.real = real + c.real;
	temp.imag = imag + c.imag;
	return temp;
}

Complex Complex::operator-(Complex c) {
	Complex temp;
	temp.real = real - c.real;
	temp.imag = imag - c.imag;
	return temp;
}

Complex Complex::operator*(Complex c) {
	Complex temp;
	temp.real = (real * c.real - imag * c.imag);
	temp.imag = (real * c.imag + imag * c.real);
	return temp;
} // Return reciprocal of z multiplied by scalar x
/*
Complex Complex::operator/(Complex c) { // this is for complex and complex
	Complex temp, temp2(real, imag);
	temp.real = c.real / (pow(c.real, 2) + pow(c.imag, 2));
	temp.imag = c.imag / (pow(c.real, 2) + pow(c.imag, 2));
	temp =  temp2.operator*(temp); // we use *this because we have to point to the variable we are multiplying
	return temp;
} // Return reciprocal of z multiplied by scalar x
*/
Complex Complex::operator/(Complex c) {
	c.imag *= -1;
	Complex temp = (*this) * c;
	temp.real /= c.real * c.real + c.imag * c.imag;
	temp.imag /= c.real * c.real + c.imag * c.imag;
	return temp;
}

Complex operator/(double x, Complex c) { // for complex and natural numbers
	Complex numer(x, 0);
	return numer / c;
}