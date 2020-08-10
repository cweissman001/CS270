#ifndef CS270POEMBASE_H
#define CS270POEMBASE_H

#include <string>

//Abstract base class
class PoemBase {
 protected:
   //What data makes up a poem object?
   //A poem is made up of a collection of lines
   std::string title;
   std::string author;

 public:
   //What are things we'd like to do to/with a poem?
   virtual void print();
   std::string getAuthor() { return author; }
   std::string getTitle() { return title; }
   virtual std::string operator[](int linenum) = 0;
   virtual int getLineCount() = 0;
};

#endif 