#include "poembase.h"

#include <iostream>

void PoemBase::print() {
  std::cout << title << std::endl;
  std::cout << "A poem by: " << author << std::endl << std::endl;
  for (int i = 0; i < getLineCount(); i++) {
    std::cout << (*this)[i] << std::endl;
  }
  std::cout << std::endl;
}

