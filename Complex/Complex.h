/*work in pairs 
design a class for a complex number-number that has two parts(one that is real value and one that is a real number*i)

*/

class Complex{
public:	

//methods or member functions
Complex(float, float); //constructor
Complex add(Complex);
	
Complex subtract(Complex);
	
Complex multiply(Complex);

Complex multiply(float);
	
Complex divide(Complex);
	
Complex exp(Complex);
void print();
void plot();
float get_real();
float get_imag();
void set_real(float);
void set_imag(float);
float magnitude();
	
	
private:
	float real;
	float imag;
};