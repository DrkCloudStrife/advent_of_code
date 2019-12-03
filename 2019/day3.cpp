#include "common.h"
#include <sstream>
#include <unordered_set>

std::vector<std::string> intersection(std::vector<std::string> &v1, std::vector<std::string> &v2)
{
  std::unordered_set<std::string> m(v1.begin(),v1.end());
  std::vector<std::string> v3;

  for(auto a : v2)
  {
    if (m.count(a))
    {
      v3.push_back(a);
      m.erase(a);
    }
  }

  return v3;
}

int main()
{
  int x = { 0 };
  int y = { 0 };
  std::ifstream fs;
  std::string file = "day3.txt";
  fs.open(file);

  if (!fs)
  {
    std::cerr << "File: " << file << " could not be opened";
    exit(1);
  }

  typedef std::vector<std::vector<std::string> > matrix;
  matrix vs(2);
  std::string s;
  int lc= { 0 };
  while (std::getline(fs, s, '\n'))
  {
    std::stringstream ss(s);
    std::string substr;
    while (getline(ss, substr, ','))
    {
      vs[lc].push_back(substr);
    }
    lc += 1;
  }

  int vsSize = vs.size();
  matrix wires;
  wires.reserve(1000);
  int px = { 0 };
  int py = { 0 };
  int length = { 0 };
  for(int i=0; i < vsSize; i++)
  {
    px = 0;
    py = 0;
    for(int j=0; j < vs[i].size(); j++)
    {
      s = vs[i][j];
      std::string dir = s.substr(0,1);
      int dist = std::atoi(s.substr(1).c_str());
      if (dir == "U")
      {
        for(int k=0; k < dist; k++)
        {
          std::string pos = std::to_string(px+1) + "," + std::to_string(py);
          wires[i].push_back(pos);
        }
      }
      if (dir == "D")
      {
        for(int k=0; k < dist; k++)
        {
          std::string pos = std::to_string(px-1) + "," + std::to_string(py);
          wires[i].push_back(pos);
        }
      }
      if (dir == "L")
      {
        for(int k=0; k < dist; k++)
        {
          std::string pos = std::to_string(px) + "," + std::to_string(py-1);
          wires[i].push_back(pos);
        }
      }
      if (dir == "R")
      {
        for(int k=0; k < dist; k++)
        {
          std::string pos = std::to_string(px) + "," + std::to_string(py+1);
          wires[i].push_back(pos);
        }
      }
    }
  }

  std::vector<std::string> v3 = intersection(wires[0], wires[1]);
  for(int i=0; i < v3.size(); i++)
  {
    std::cout << v3[i] << std::endl;
  }

  return 0;
}
