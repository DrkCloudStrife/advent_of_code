#include <iostream>
#include <fstream>
#include <sstream>
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
