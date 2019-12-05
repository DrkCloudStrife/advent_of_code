#include <iostream>
#include <fstream>
#include <vector>

struct Node 
{
  int data;
  struct Node * next;
  struct Node * prev;
};

struct Node* headNode;
