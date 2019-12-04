#include "common.h"
#include <algorithm>
#include <sstream>
#include <unordered_set>

std::vector<int *> intersection(std::vector<int *> &v1, std::vector<int *> &v2)
{
  std::vector<int *> v3;

  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());

  std::set_intersection(v1.begin(),v1.end(),
    v2.begin(),v2.end(),
    back_inserter(v3)
  );

  std::vector<int *>::iterator ip;
  ip = std::unique(v3.begin(), v3.end());
  v3.resize(std::distance(v3.begin(), ip));

  return v3;
}

int main()
{
  std::ifstream fs;
  // std::string file = "day3.txt";
  std::string file = "day3_test.txt";
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
  std::vector<std::vector<int *> > wires;
  wires.reserve(1000);
  int px = { 0 };
  int py = { 0 };

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
          int arr[2] = {px, py++};
          wires[i].push_back(arr);
        }
      }
      else if (dir == "D")
      {
        for(int k=0; k < dist; k++)
        {
          int arr[2] = {px, py--};
          wires[i].push_back(arr);
        }
      }
      else if (dir == "R")
      {
        for(int k=0; k < dist; k++)
        {
          int arr[2] = {px++, py};
          wires[i].push_back(arr);
        }
      }
      else if (dir == "L")
      {
        for(int k=0; k < dist; k++)
        {
          int arr[2] = {px--, py};
          wires[i].push_back(arr);
        }
      }
      else
        continue; // skip
      std::cout << px << "," << py << std::endl;
    }
    std::cout << "====" << std::endl;
  }

  //p1
  std::vector<int *> v3 = intersection(wires[0], wires[1]);
  int output = { 0 };
  for(int i=0; i < v3.size(); i++)
  {
    std::cout << v3[i][0] << "," << v3[i][1] << std::endl;
    int m_dist = v3[i][0] + v3[i][1];
    // std::cout << m_dist << std::endl;
    if (output == 0 || output > m_dist)
      output = m_dist;
  }

  std::cout << output << std::endl;
  return 0;
}
