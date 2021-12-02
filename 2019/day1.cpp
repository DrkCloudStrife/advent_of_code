#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <math.h>

int main()
{
  std::string fileName = "./day1.txt";
  std::ifstream fs;
  fs.open(fileName);

	if (!fs)
	{
		std::cerr << "File: " << fileName << " could not be opened";
		exit(1);
	}

  std::vector<int> v;
  v.reserve(1000);
  std::copy(std::istream_iterator<int>(fs), std::istream_iterator<int>(), std::back_inserter(v));

  int vSize = v.size();

  // p1
  int p1 = { 0 };
  for(int i=0; i < vSize; i++)
  {
    int tmp = v.at(i);
    int r = round(tmp / 3);
    p1 += r - 2;
  }

  std::cout << p1 << std::endl;

  // p2
  int p2 = { 0 };
  int rem;
  bool isFueled ;
  for(int i=0; i < vSize; i++)
  {
    rem = -777;
    isFueled = false;

    while (!isFueled) {
      if (rem == -777)
        rem = v.at(i);

      int r = round(rem / 3);
      int f = (r - 2);
      if (f > 0)
        rem = f;

      if (f <= 0)
      {
        isFueled = true;
      }
      else
      {
        p2 += rem;
      }
    }
  }

  std::cout << p2 << std::endl;

  return 0;
}
