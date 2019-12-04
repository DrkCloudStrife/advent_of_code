#include "common.h"
#include <algorithm>
#include <sstream>
#include <unordered_set>

std::vector<std::string> intersection(std::vector<std::string> &v1, std::vector<std::string> &v2)
{
  std::vector<std::string> v3;

  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());

  std::set_intersection(v1.begin(),v1.end(),
    v2.begin(),v2.end(),
    back_inserter(v3)
  );

  std::vector<std::string>::iterator ip;
  ip = std::unique(v3.begin(), v3.end());
  v3.resize(std::distance(v3.begin(), ip));

  return v3;
}

std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream ss(s);
   while (std::getline(ss, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

int main()
{
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
  std::vector<std::vector<std::string> > wires;
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
          std::string pos = std::to_string(px) + "," + std::to_string(py++);// {px, py++};
          wires[i].push_back(pos);
        }
      }
      else if (dir == "D")
      {
        for(int k=0; k < dist; k++)
        {
          std::string pos = std::to_string(px) + "," + std::to_string(py--);
          wires[i].push_back(pos);
        }
      }
      else if (dir == "R")
      {
        for(int k=0; k < dist; k++)
        {
          std::string pos = std::to_string(px++) + "," + std::to_string(py);
          wires[i].push_back(pos);
        }
      }
      else if (dir == "L")
      {
        for(int k=0; k < dist; k++)
        {
          std::string pos = std::to_string(px--) + "," + std::to_string(py);
          wires[i].push_back(pos);
        }
      }
      else
        continue; // skip
    }
  }

  //p1
  std::vector<std::string> v3 = intersection(wires[0], wires[1]);
  int output = { 0 };
  for(int i=0; i < v3.size(); i++)
  {
    std::vector<std::string> point = split(v3[i], ',');

    int x = abs(std::stoi(point[0]));
    int y = abs(std::stoi(point[1]));
    int m_dist = x + y;

    if (output == 0 || output > m_dist)
      output = m_dist;
  }

  std::cout << output << std::endl;

  return 0;
}
