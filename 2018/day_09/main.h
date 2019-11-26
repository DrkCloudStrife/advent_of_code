#include <iostream>

std::string fileName;
// TODO: Update to read from file
int playersCount = { 0 }; // 452
int lastMarble   = { 1618 };// 70784
static int MarbleMultiple = { 23 };

struct MarbleNode 
{
  int data;
  struct MarbleNode* nextNode;
  struct MarbleNode* prevNode;
};

struct MarbleNode* currentMarble;
struct MarbleNode* GetNewMarbleNode(int);

void addMarble(int);
void removeMarble(int);

int main();
