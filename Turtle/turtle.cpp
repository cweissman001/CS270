#include "turtle.h"
#include <math.h>
//need to use full name when calling outside of where class is defined ClassName::FunctionName
/* Turtle::Turtle(){ 
		direction = 0.0;
		x_pos = 0.0;
		y_pos = 0.0;
		drawing = true;
}  dont need anymore*/
Turtle::Turtle(float dir, float x, float y, bool d) {
		direction = dir;
		x_pos = x;
		y_pos = y;
		drawing = d;
	
}
void Turtle::left(float angle) {
	direction += angle;
}

void Turtle::forward(float dist) {
		x_pos += cosf(direction)*dist;
		y_pos += sinf(direction)*dist;
}

void operator<<(std::ostream& out, const Turtle& t){
	out << t.direction;
	out << "(" << t.x_pos << ", " << t.y_pos << ")";
}
	


/*class Turtle { //creates objects that are all connected
	
	
public:	//everything after is considered public until next marker
	// default/zero-argument constructor
	Turtle(){ /* only inside scope of class--if you name a function with the same name as the class it is called a constructor and it does it without being called */
/*
		direction = 0.0;
		x_pos = 0.0;
		y_pos = 0.0;
		drawing = true;
	}
	//constructor with arguments
	Turtle(float dir, float x, float y, bool d) {
		direction = dir;
		x_pos = x;
		y_pos = y;
		drawing = d;
	
	}
	
	//Method - a function that belongs to a class
	float get_direction() {return direction; }
	
	void left(float angle) {
	direction += angle;
	}

	void forward(float dist) {
		x_pos += cosf(direction)*dist;
		y_pos += sinf(direction)*dist;
  }
	//put at bottom to make slightly less confusing for user
private: // make variables private so no one can mess with them
	float direction; //Angle orientation in the plane, as degrees
	float x_pos, y_pos; //Position
	bool drawing; //Whether or not it's currently drawing	
}; //need a ; because this is also a declartion ... of a class


void turn_left(Turtle t) {
	t.left(90);
}

int main() {
	Turtle george; /*inside is contained a direction, an x_pos, y_pos and the other elements in the turtle class */
	//george.initialize(); //don't need because of the constructor
/*
	Turtle fred; // Create variable called fred and call constructor on it 
	Turtle katie(90, 0, 100, false); //initialized with non-zero values
	//george.forward(100);
	turn_left(george); /* creates a new turtle t which is a copy of george and then changes turtle t and not george so it still prints 0 */
	//george.forward(50);
	 /*
	std::cout << george.get_direction() << std::endl; //prints out current directon
	// '.' gets thing inside of a thing
	
	
*/