#include <iostream>
#include "turtle.h"
#include <math.h>

void turn_left(Turtle& t){ //passing in a reference
		t.left(45);
}
void print_dir(const Turtle& t) {
	std::cout << "Turtle direction: " << t.get_direction() << std::endl;
}

int main() {
	Turtle george; /*inside is contained a direction, an x_pos, y_pos and the other elements in the turtle class */
	//george.initialize(); //don't need because of the constructor
	Turtle fred; // Create variable called fred and call constructor on it 
	Turtle katie(90, 0, 100, false); //initialized with non-zero values
	//george.forward(100);
	
	//Turtle& justaname = fred; /*Reference to a Turtle - always have to refer to a valid object --place holder to refer to another object and does not create a copy */
	//dont have to make explicit references to use methods that take it
	//justaname.left(30); // works perfectly fine and does modify object
	
	george.left(45); /* creates a new turtle t which is a copy of george and then changes turtle and not george so it still prints 0 before method was changed to take a reference*/
	//george.forward(50);
	turn_left(fred); // now modifies fred object since method takes in reference
	turn_left(george); // can still call even without explicit reference call
	
	george.forward(100);//same as above just different way
	//george >> 100; //shortcut : operator>>(george, 100) BAD IDEA IN GENERAL
	
	std::cout << george.get_direction() << std::endl; //prints out current directon
	// '.' gets thing inside of a thing
	std::cout << fred.get_direction() << std::endl;
	std::<<george;
	
	//dont always want a function to be able to modify function maybe jsut look at
	//middle ground is const (const Turtle& t) saying you cannot modify object
}

