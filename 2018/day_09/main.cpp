#include "./main.h"

struct MarbleNode* GetNewMarbleNode(int x)
{
  struct MarbleNode* newMarble = new MarbleNode();
  newMarble->data = x;
  newMarble->prevNode = NULL;
  newMarble->nextNode = NULL;

  return newMarble;
}

// Add new marble at head of nodes
void addMarble(int x)
{
  struct MarbleNode * newMarble = GetNewMarbleNode(x);
  if (currentMarble == NULL)
  {
    currentMarble = newMarble;
    return;
  }

  // TODO: assign nodes based on rotation
  currentMarble->nextNode = newMarble;
  newMarble->prevNode = currentMarble;
  currentMarble = newMarble;
}

// integer to pointer of marble node to remove. e.g. 7 will go back 7 nodes to delete that node.
void removeMarble(int x)
{
  struct MarbleNode * tempMarble = currentMarble;
  struct MarbleNode * delNode;

  int count = { 0 };
  while (count < x && tempMarble != NULL)
  {
    tempMarble = (*tempMarble).prevNode;
    count++;
  }

  free(tempMarble);
}

int main()
{
  for (int i = 0; i < lastMarble; i++){
    if (i % MarbleMultiple == 0) {
      std::cout << "Not adding Marble. Removing one instead " << std::endl;
      removeMarble(7);
    }
    else {
      addMarble(i);
      std::cout << "Current Marble: " << std::to_string(currentMarble->data) << std::endl;
      if (currentMarble->prevNode != NULL) {
        std::cout << "Prev Marble: " << std::to_string(currentMarble->prevNode->data) << std::endl;
      }
      if (currentMarble->nextNode != NULL) {
        std::cout << "Next Marble: " << std::to_string(currentMarble->nextNode->data) << std::endl;
      }
    }
    std::cout << "------" << std::endl;
  }
}
