#include <iostream>

void drawBar(int len) {
  for (int i = 0; i < len; i++) {
    std::cout << '-';
  }
}

//Draw an internal segment (recursive)
void drawTicks(int tickLength) {
  //Base case: do nothing
  if (tickLength == 0)
    return;
  //recursive case:
  //print upper segment
  drawTicks(tickLength - 1);
  //print big bar
  drawBar(tickLength);
  std::cout << std::endl;
  //print lower segment
  drawTicks(tickLength - 1);
}

//Draw the ruler
int main() {
  int size = 5;
  int length = 3;

  //Print 0 bar
  drawBar(size);
  std::cout << " 0" << std::endl;
  //For each segment, print tick pattern and another numbered bar
  for (int i = 0; i < length; i++) {
    drawTicks(size-1);
    drawBar(size);
    std::cout << ' ' << i+1 << std::endl;
  }
  return 0;
}

//adds side bar(s)

//Iteratively repeats pattern
