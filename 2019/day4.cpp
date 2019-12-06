#include "common.h"
#include <numeric>
#include <map>

void validateNumPass(int& p1Size, int&p2Size, int pw)
{
  std::vector<int> vd = splitInt(pw);

  bool isAsc   = false;
  bool isP1Val = false;
  bool isP2Val = false;
  int prevDigi = -1;
  std::map<int,int> freq_map;

  for(int i=0; i < vd.size(); i++)
  {
    int curDig = vd[i];
    if (prevDigi == -1)
    {
      prevDigi = curDig;
      continue; // skip. Nothing to compare
    }

    if (prevDigi >= curDig)
    {
      if (prevDigi == curDig)
      {
        if (freq_map.count(curDig) > 0)
          freq_map[curDig] += 1;
        else
          freq_map[curDig] = 1;

        isP1Val = true;
      }

      isAsc = true;
      prevDigi = vd[i];
    }
    else // prev digit is larger, no longer valid
    {
      isP1Val = false;
      isP2Val = false;
      isAsc = false;
      break;
    }
  }

  if (isAsc)
  {
    std::map<int,int>::iterator it = freq_map.begin();
    while(it != freq_map.end())
    {
      int count = it->second;

      if (count == 1) // 1 match of same key
        isP2Val = true;
      it++;
    }
  }

  if (isP1Val)
    p1Size++;
  if (isP2Val)
    p2Size++;
}

int main()
{
  int sInt = { 123257 };
  int eInt = { 647015 };
  int p1Size = { 0 };
  int p2Size = { 0 };

  for (int n = sInt; n < (eInt + 1); n++)
  {
    validateNumPass(p1Size, p2Size, n);
  }

  // p1
  std::cout << p1Size << std::endl;

  // p2
  std::cout << p2Size << std::endl;

  return 0;
}
