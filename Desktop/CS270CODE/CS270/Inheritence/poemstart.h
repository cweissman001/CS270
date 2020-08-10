#ifndef CS270POEMSTART_H
#define CS270POEMSTART_H

#include <string>
#include <vector>

//Abstract base class
class Poem {
 private:
   //What data make up a poem object?
	std::vector<std::string> lines;
	std::string title;
	std::string author;

 public:
   //What are things we'd like to do to/with a poem?
	Poem(std:string title, std::string author) : title(title), author(author) {};
	
	void addLine(std::string line){
		lines.push_back(line);
	}
	void removeLine(int linenum){
		lines.remove(lines.begin() +linenum); //only allowed to remove an iterator
	void print();
	std::string getAuthor(){return author;}
	std::string getTitle(){return title;}
	//two ways of gettings a line
	std::string getLine(int linenum){ return lines[linenum];
	//std::string operator[](int linenum);
	int size() {return lines.size(); }
	
};
//Haiku inherits from(or extends) the class Poem
//includes all of the compenants of poem as a base starting point
class Haiku : public Poem {
	private:
	std::string haiku_lines[3];
	
	public:
	std::string getLine(int linenum){ return haiku_lines[linenum];
	
	
};
#endif 