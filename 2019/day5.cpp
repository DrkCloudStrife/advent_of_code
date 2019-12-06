#include "intcode_computer.h"

int main()
{
  IntcodeComputer computer("day5_test.txt");
  computer.run();

  // p1
  std::cout << computer.getResult() << std::endl;

  return 0;
}
