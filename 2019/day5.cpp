#include "intcode_computer.h"

int main()
{
  IntcodeComputer computer("day5.txt");

  //p1
  computer.runTest(1);

  computer.reset();
  std::cout << "=====" << std::endl;

  //p2
  computer.runTest(5);

  return 0;
}
