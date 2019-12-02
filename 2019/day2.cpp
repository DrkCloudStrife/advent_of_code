#include <iostream>
#include <fstream>
#include <vector>

int main()
{
  std::string fileName = "./day2.txt";
  std::ifstream fs;
  fs.open(fileName);

  if (!fs)
  {
    std::cerr << "File: " << fileName << " could not be opened";
    exit(1);
  }

  std::vector<int> v;
  std::string s;
  v.reserve(1000);
  while (std::getline(fs, s, ','))
  {
    v.push_back(std::stoi(s));
  }

  int haltCode = { 99 };
  int addCode  = { 1 };
  int mulCode  = { 2 };
  int vSize    = v.size();

  std::vector<int> vp1;
  vp1 = v;
  // p1
  for(int i=0; i < vSize; i++)
  {
    int opCode = vp1[i];
    int n1     = vp1[i+1];
    int n2     = vp1[i+2];
    int t      = vp1[i+3];
    int v1     = vp1[n1];
    int v2     = vp1[n2];

    if (opCode == haltCode)
      break;

    if (opCode == addCode)
    {
      vp1[t] = v1 + v2;
    }

    if (opCode == mulCode)
    {
      vp1[t] = v1 * v2;
    }
    i += 3; // skip to next op
  }

  std::cout << vp1[0] << std::endl;

  //p2
  int desiredOut = 19690720;
  std::vector<int> vp2;
  vp2 = v;
  int c1 = { 0 };
  int c2 = { 0 };

  while (vp2[0] != desiredOut)
  {
    vp2 = v; // reset vector
    // increment c1 up to 99
    // once c1 has hit 99, increment c2 by 1
    // if c1 and c2 ever reach 99 both, exit
    if (c1 == 99 && c2 != 99)
    {
      c1 = 1;
      c2 += 1;
    }
    else
    {
      c1 += 1;
    }
    if (c1 == 100 && c2 == 100)
    {
      std::cout << "ERROR" << std::endl;
      break;
    }

    vp2[1] = c1;
    vp2[2] = c2;

    for(int i=0; i < vSize; i++)
    {
      int opCode = vp2[i];
      int n1     = vp2[i+1];
      int n2     = vp2[i+2];
      int t      = vp2[i+3];
      int v1     = vp2[n1];
      int v2     = vp2[n2];

      if (opCode == haltCode)
        break;

      if (opCode == addCode)
      {
        vp2[t] = v1 + v2;
      }

      if (opCode == mulCode)
      {
        vp2[t] = v1 * v2;
      }
      i += 3; // skip to next op
    }
  }

  std::cout << c1 << std::endl;
  std::cout << c2 << std::endl;
}
