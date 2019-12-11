#include "common.h"
#include <map>

struct Orbit
{
  std::string name;
  struct Orbit* parent;
};

struct Orbit* CreateOrbit(std::string name)
{
  struct Orbit* pOrbit = new Orbit();
  pOrbit->name = name;
  pOrbit->parent = NULL;

  return pOrbit;
}

typedef std::map<std::string, struct Orbit*> orbit_collection;

struct Orbit* findOrCreateOrbit(orbit_collection& orbits, std::string name)
{
  struct Orbit* myOrbit;
  if (orbits.count(name) > 0)
  {
    myOrbit = orbits.find(name)->second;
  }
  else
  {
    myOrbit = CreateOrbit(name);
    orbits[name] = myOrbit;
  }

  return myOrbit;
}

int main()
{
  std::string fileName = "./day6.txt";
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

  // build orbit collection
  orbit_collection orbits;

  for (int i=0; i < v.size(); i++)
  {
    for (auto& o: v[i])
    {
      struct Orbit* parentOrbit = findOrCreateOrbit(orbits, o.first);
      struct Orbit* childOrbit = findOrCreateOrbit(orbits, o.second);
      childOrbit->parent = parentOrbit;
    }
  }

  int dirOrbCount = { 0 };
  int indirOrbCount = { 0 };

  orbit_collection::iterator it = orbits.begin();

  while (it != orbits.end())
  {
    struct Orbit* currentOrbit = it->second;
    if (currentOrbit->parent != NULL)
    {
      dirOrbCount++;
      while (currentOrbit->parent != NULL)
      {
        currentOrbit = currentOrbit->parent;
        if (currentOrbit->parent != NULL)
          indirOrbCount++;
      }
    }

    it++;
  }

  // p1
  std::cout << "D: " << dirOrbCount << "; I: " << indirOrbCount << "; T: " << dirOrbCount + indirOrbCount << std::endl;

  return 0;
}
