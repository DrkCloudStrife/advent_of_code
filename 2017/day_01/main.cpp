#include <iostream>
#include <fstream>

void newLine()
{
  std::cout << "" << std::endl;
}

std::string readFile()
{
  std::cout << "Enter file path" << std::endl;
  std::string filePath;
  getline(std::cin, filePath);

  std::ifstream inFile;

  inFile.open(filePath);

  if (!inFile)
  {
    std::cerr << "Unable to open " << filePath << std::endl;
    exit(1);
  }

  std::string line;
  std::string str;
  while (inFile >> line)
  {
    str = str + line;
  }

  return str;
}

int convertToInt(char c)
{
  int i = c - '0';
  return i;
}

// Part 1
int partOne(std::string str)
{
  int result = { 0 };
  int prevInt = -1;
  for(std::string::size_type i = 0; i < str.size(); ++i)
  {
    int currInt = convertToInt(str[i]);
    if (prevInt == -1)
    {
      prevInt = currInt;
      continue;
    }

    if (prevInt == currInt)
    {
      result = result + prevInt;
    }

    prevInt = currInt;
  }

  // Check for first and last index before returning
  if (str[0] == str[str.size()-1])
  {
    result = result + convertToInt(str[0]);
  }

  return result;
}

// Part 2
int partTwo(std::string str)
{
  // TODO
  // Get the steps to get a lookahead based on length / 2
  // Check if lookahead is greater than length
  // If lookahead is greater than length, reduce length from lookahead to circulate
  // If lookahead number and current number match, add to result
  return 0;
}

// Part Selector
int selectPart()
{
  std::cout << "Which part should I solve for?" << std::endl;
  newLine();
  std::cout << "1) Part One" << std::endl;
  std::cout << "2) Part Two" << std::endl;
  int part = { 0 };
  std::cin >> part;
  // TODO
  return part;
}

int main()
{
  std::string str = readFile();
  int part = selectPart();
  newLine();
  std::cout << "Your answer for part " << part << " is:" << std::endl;
  int ans = { 0 };
  if (part == 2)
  {
    ans = partTwo(str);
  }
  else
  {
    ans = partOne(str);
  }
  std::cout << ans << std::endl;
  return 0;
}
