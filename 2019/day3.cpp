#include "../shared/cpp/common.h"
#include <algorithm>
#include <unordered_map>

int main()
{
  std::ifstream fs;
  std::string file = "day3.txt"; fs.open(file);

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

  for(int i=0; i < vsSize; i++)
  {
    int px = { 0 };
    int py = { 0 };

    for(int j=0; j < vs[i].size(); j++)
    {
      s = vs[i][j];
      std::string dir = s.substr(0,1);
      int dist = std::atoi(s.substr(1).c_str());

      if (dir == "U")
      {
        for(int k=0; k < dist; k++)
        {
          std::string pos = std::to_string(px) + "," + std::to_string(py++);
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
  int v3Size = v3.size();
  for(int i=0; i < v3Size; i++)
  {
    std::vector<std::string> point = split(v3[i], ',');

    int x = abs(std::stoi(point[0]));
    int y = abs(std::stoi(point[1]));
    int m_dist = x + y;

    if (output == 0 || output > m_dist)
      output = m_dist;
  }

  std::cout << output << std::endl;

  //p2
  std::unordered_map<std::string,int> w1;
  std::unordered_map<std::string,int> w2;
  int steps = { 0 };
  for(int i=0; i < wires[0].size(); i++)
  {
    w1[wires[0][i]] = steps++;
  }

  steps = 0; // reset
  for(int i=0; i < wires[1].size(); i++)
  {
    w2[wires[1][i]] = steps++;
  }

  int p2out = { 0 };
  for(int i=0; i < v3Size; i++)
  {
    int w1l = w1[v3[i]];
    int w2l = w2[v3[i]];
    int m_dist = w1l + w2l;

    if (p2out == 0 || p2out > m_dist)
      p2out = m_dist;
  }

  std::cout << p2out << std::endl;

  return 0;
}
