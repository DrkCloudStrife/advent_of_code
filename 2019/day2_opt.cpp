#include "intcode_computer.h"

int main()
{
  //p1
  IntcodeComputer computer("day2.txt");
  computer.run();

  std::cout << computer.getResult() << std::endl;

  //p2
  int desiredOut = 19690720;
  int n = { 0 };
  int v = { 0 };

  computer.setInput(n, v);
  computer.run();

  while (computer.getResult() != desiredOut)
  {
    if (n == 99 && v != 99)
    {
      n = 1;
      v += 1;
    }
    else
    {
      n += 1;
    }
    if (n == 100 && v == 100)
    {
      std::cout << "ERROR" << std::endl;
      break;
    }

    computer.setInput(n, v);
    computer.run();
  }

  std::cout << n << std::endl;
  std::cout << v << std::endl;
}
