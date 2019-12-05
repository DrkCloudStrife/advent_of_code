#include "common.h"
#include <numeric>

void validateNumPass(std::vector<int>& pwCol, int pw)
{
  int tmpNum = pw;
  int digit;
  std::vector<int> vd;

  while (tmpNum > 0)
  {
    digit = tmpNum % 10;
    tmpNum = tmpNum / 10;
    vd.push_back(digit);
  }

  bool isValid = false;
  int prevDigi = -1;
  for(int i=0; i < vd.size(); i++)
  {
    if (prevDigi == -1)
    {
      prevDigi = vd[i];
      continue; // skip. Nothing to compare
    }

    if (prevDigi >= vd[i])
    {
      if (prevDigi == vd[i])
        isValid = true;
      prevDigi = vd[i];
    }
    else {
      isValid = false;
      break;
    }
  }

  if (isValid)
    pwCol.push_back(pw);
}

int main()
{
  int sInt = { 123257 };
  int eInt = { 647015 };
  std::vector<int> pwCol;

  for (int n = sInt; n < eInt+ 1; n++)
  {
    validateNumPass(pwCol, n);
  }

  // p1
  std::cout << pwCol.size() << std::endl;
  return 0;
}
