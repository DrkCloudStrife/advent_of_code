#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <numeric>

int main()
{
  bool isFound = false;
  std::string fileName = "./day_01/input.txt";
  std::ifstream fs;
  fs.open(fileName);

	if (!fs)
	{
		std::cerr << "File: " << fileName << " could not be opened";
		exit(1);
	}

  std::vector<int> values;
  std::copy(std::istream_iterator<int>(fs), std::istream_iterator<int>(), std::back_inserter(values));

  fs.close();

	int output = { 0 };
	std::string currentOperator;
	int currentValue;

  output = std::accumulate(values.begin(), values.end(), 0);

  std::cout << output << std::endl;

  output = 0; // reset
  typedef std::map<int, int> MapType;
	MapType frequency_map;
	frequency_map[output] = 0;

  int vSize = values.size();
  while (!isFound)
  {
    for(int i=0; i < vSize; i++)
    {
      output += values.at(i);

      MapType::iterator it = frequency_map.lower_bound(output);
      if(it != frequency_map.end() && !(frequency_map.key_comp()(output, it->first)))
      {
        isFound = true;
      }
      else
      {
        frequency_map.insert(it, MapType::value_type(output, 0));
      }
    }
  }
  std::cout << output << std::endl;

  return 0;
}
