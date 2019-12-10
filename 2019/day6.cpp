#include "common.h"
#include <map>

int main()
{
  std::string fileName = "./day6_test.txt";
  std::ifstream fs;
  fs.open(fileName);

  if (!fs)
  {
    std::cerr << "File: " << fileName << " could not be opened";
    exit(1);
  }

  std::vector<std::map<std::string, std::string> > v;
  v.reserve(1000);

  std::string s;
  int lc= { 0 };
  while (std::getline(fs, s, '\n'))
  {
    std::istringstream ss(s);
    std::string sKey, sVal;
    while (getline(getline(ss, sKey, ')') >> std::ws, sVal)) // split and get k/v
    {
      std::map<std::string, std::string> tmpMap;
      tmpMap.insert(std::pair<std::string, std::string>(sKey,sVal));
      v.push_back(tmpMap);
    }
    lc += 1;
  }

  for(int i=0; i < v.size(); i++)
  {
    for (auto& x: v[i])
    {

    }
  }

  return 0;
}
