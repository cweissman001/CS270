#include "Complex.h"
#include <iostream>
using namespace std;

int main(){
	float real;
	float imag;
	cout << "Please enter the real half of an imaginary number: ";
	cin >> real;
	cout << "Please enter the imagianry half of an imaginary number: ";
	cin >> imag;
	
	Complex num1(real, imag);
	
	num1.print();
	Complex num5(3, 4i);
	cout << num1.add(num5);
	

}