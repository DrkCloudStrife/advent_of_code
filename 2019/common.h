#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Node 
{
  int data;
  struct Node * next;
  struct Node * prev;
};

struct Node* headNode;

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
