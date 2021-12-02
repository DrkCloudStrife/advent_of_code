#include "../shared/cpp/common.h"
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

  // p1
  int dirOrbCount = { 0 };
  int indirOrbCount = { 0 };

  // p2
  std::string YOU = "YOU";
  std::string SAN = "SAN";

  std::map<std::string, int> sanOrbitsDist;
  std::map<std::string, int> youOrbitsDist;
  std::vector<std::string> vYOU;
  std::vector<std::string> vSAN;

  orbit_collection::iterator it = orbits.begin();

  while (it != orbits.end())
  {
    struct Orbit* currentOrbit = it->second;
    if (currentOrbit->parent != NULL)
      dirOrbCount++;

    bool trackYOU = false;
    bool trackSAN = false;
    int idx = { 0 };

    while (currentOrbit->parent != NULL)
    {
      if (currentOrbit->name == YOU)
        trackYOU = true;
      if (currentOrbit->name == SAN)
        trackSAN = true;

      currentOrbit = currentOrbit->parent;

      if (trackSAN)
      {
        sanOrbitsDist.insert(std::pair<std::string, int>(currentOrbit->name, idx));
        vSAN.push_back(currentOrbit->name);
      }
      if (trackYOU)
      {
        youOrbitsDist.insert(std::pair<std::string, int>(currentOrbit->name, idx));
        vYOU.push_back(currentOrbit->name);
      }

      if (currentOrbit->parent != NULL)
        indirOrbCount++;

      idx++;
    }

    it++;
  }

  // p1
  std::cout << dirOrbCount + indirOrbCount << std::endl;

  // p2
  int lowYOU = { 0 };
  int lowSAN = { 0 };
  std::vector<std::string> similar = intersection(vYOU, vSAN);
  for(int i = 0; i < similar.size(); i++)
  {
    std::string sOrbit = similar[i];
    int tmpSAN = sanOrbitsDist.find(sOrbit)->second;
    int tmpYOU = youOrbitsDist.find(sOrbit)->second;

    if (lowYOU == 0 && tmpYOU > 0)
      lowYOU = tmpYOU;
    if (lowYOU != 0 && lowYOU > tmpYOU)
      lowYOU = tmpYOU;

    if (lowSAN == 0 && tmpSAN > 0)
      lowSAN = tmpSAN;
    if (lowSAN != 0 && lowSAN > tmpSAN)
      lowSAN = tmpSAN;
  }

  std::cout << lowSAN + lowYOU << std::endl;

  return 0;
}
