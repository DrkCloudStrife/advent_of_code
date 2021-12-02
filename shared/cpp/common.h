#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <list>

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

std::list<int> splitInt(const int& num, bool reverse);
std::list<int> splitInt(const int& num, bool reverse)
{
  std::list<int> vds;
  int tmpNum = num;
  int digit;

  while (tmpNum > 0)
  {
    digit = tmpNum % 10;
    tmpNum = tmpNum / 10;
    vds.push_back(digit);
  }

  if (reverse == true)
    std::reverse(vds.begin(),vds.end());

  return vds;
}

std::list<int> splitInt(const int& num);
std::list<int> splitInt(const int& num)
{
  return splitInt(num, false);
}

std::vector<std::string> intersection(std::vector<std::string> &v1, std::vector<std::string> &v2)
{
  std::vector<std::string> v3;

  std::unordered_set<std::string> col(v1.begin(), v1.end());

  for(auto a : v2)
  {
    if (col.erase(a) > 0) {
      v3.push_back(a);
    }
  }

  return v3;
}


std::ifstream readFile(const char* fileName)
{
  std::ifstream fs;
  fs.open(fileName);
  if (!fs)
  {
    std::cerr << "File: " << fileName << " could not be opened";
    exit(1);
  }

  return fs;
}
