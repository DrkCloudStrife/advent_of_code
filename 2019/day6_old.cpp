#include "common.h"
#include <map>

const int ALPHABET_SIZE = 26;

struct Orbit
{
  std::string name;
  struct Orbit* children[ALPHABET_SIZE];
  struct Orbit* parent;
};

struct Orbit* currentOrbit;

struct Orbit* CreateOrbit(std::string name)
{
  struct Orbit* pOrbit = new Orbit();
  pOrbit->name = name;
  pOrbit->parent = NULL;

  for(int i = 0; i < ALPHABET_SIZE; i++)
    pOrbit->children[i] = NULL;

  return pOrbit;
}

bool navigateToOrbit(struct Orbit* root, std::string orbitName)
{
  struct Orbit* oCrawl = root;

  for(int i = 0; i < orbitName.length(); i++)
  {
    int idx = orbitName[i] - 'a';
    if (!oCrawl->children[idx])
      return false; // doesn't exists

    oCrawl = oCrawl->children[idx]; // Move to next child
  }

  if (oCrawl != NULL && oCrawl->name == orbitName) // it exists
  {
    currentOrbit = oCrawl;
    return true;
  }
  else
    return false;
}

void insertOrbit(struct Orbit* root, std::string orbitName)
{
  struct Orbit* oCrawl = root;

  for (int i = 0; i < orbitName.length(); i++) 
  { 
    int idx = orbitName[i] - 'a'; 
    if (!pCrawl->children[idx]) 
      pCrawl->children[idx] = CreateOrbit(orbitName); 

    pCrawl = pCrawl->children[idx]; 
  } 
}

// // struct Orbit* findOrCreateOrbit(std::string parentName, std::string childName)
// void findOrCreateOrbit(std::string parentName, std::string childName)
// {
//   struct Orbit* pOrbit;
//
//   if (navigateToOrbit(parentName))
//     pOrbit = currentOrbit;
//   else
//     pOrbit = CreateOrbit(parentName);
//
//   currentOrbit = CreateOrbit(childName);
//
//   currentOrbit->parent = pOrbit;
//
//   // return parentOrbit;
// }

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
    std::stringstream ss(s);
    std::string sKey, sVal;
    while (getline(ss, sKey, ')') >> std::ws, val)
    {
      vs[lc][sKey] = sVal;
    }
    lc += 1;
  }

  return 0;
}
