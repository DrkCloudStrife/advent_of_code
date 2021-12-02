#include "../../../shared/cpp/common.h"
#include <iterator>

int main()
{
    std::ifstream fs;
    fs = readFile("../../shared/input_day01.txt");

    std::vector<int> v;
    v.reserve(1000); // might need to find a better way to reserve memory..
    std::copy(std::istream_iterator<int>(fs), std::istream_iterator<int>(), std::back_inserter(v));
    std::cout << "HELLO: " << v[0] << std::endl;
}
