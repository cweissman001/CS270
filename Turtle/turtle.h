#include<iostream>
class Turtle { //creates objects that are all connected
public:	//everything after is considered public until next marker
	
	// default/zero-argument constructor
	//Turtle(); dont need this because of below
	
	//constructor with arguments
	Turtle(float dir=0.0f, float x=0.0f, float y=0.0f, bool d= true);
	
	//Method - a function that belongs to a class
	float get_direction() const {return direction; } //can declare in h file
	void left(float angle);
	void forward(float dist);
	void operator>>(float dist) {forward(dist);}
	friend void operator<<(std::ostream& out, const Turtle& t); //can use private variables but arent in the class or cant be method
	
	//put at bottom to make slightly less confusing for user
private: // make variables private so no one can mess with them
	float direction; //Angle orientation in the plane, as degrees
	float x_pos, y_pos; //Position
	bool drawing; //Whether or not it's currently drawing	
}; //need a ; because this is also a declartion ... of a class

//ostream is the version of output and a reference since you are changing
//function to print turtle
void operator<<(std::ostream& out, const Turtle& t);
/*non-member function is a function that the user of the class are an essential part of the class but from c++ syntax they dont belond inside the class. IE it is not a method and can't be inside the calss becasue of that */
