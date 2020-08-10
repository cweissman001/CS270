#include <iostream>
#include "Complex.h"


Complex::Complex(float r, float i){
	real = r;
	imag = i;
} //constructor

Complex Complex::add(Complex one){
	float res_real = one.real + real;
	float res_imag = one.imag + imag;
	Complex ad1(res_real, res_imag);
	return ad1;
}

Complex Complex::subtract(Complex one){
	float res_real = one.real - real;
	float res_imag = one.imag - imag;
	Complex sub1(res_real, res_imag);
	return sub1;
}


void Complex::print(){
	std::cout << get_real()<< " + " << get_imag() <<"i" << std::endl;
}

float Complex::get_real(){
	return real;
}

float Complex::get_imag(){
	return imag;
}

Complex Complex::multiply(Complex two){
	float real_res = two.real * real - two.imag * imag;
	float imag_res = two.real * imag + two.imag * real;
	Complex mult1(real_res, imag_res);
	return mult1;
}
	
Complex Complex::multiply(float c){
	float res_real = real*c;
	float res_imag = imag*c;
	Complex mul2(res_real, res_imag);
	return mul2;
	}

Complex Complex::divide(Complex two){
	float real_res = two.real / real - two.imag / imag;
	float imag_res = two.real / imag + two.imag / real;
	Complex div1(real_res, imag_res);
	return div1;
}

Complex Complex::exp(Complex){
	
}

void Complex::plot(){
	
}


void Complex::set_real(float r2){
	real = r2;
}

void Complex::set_imag(float i2){
	real = i2;
}

float Complex::magnitude(){
	
}