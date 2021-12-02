#include "../../../shared/cpp/common.h"
#include <iterator>
#include <numeric>

int main()
{
    std::ifstream fs;
    fs = readFile("../../shared/input_day01.txt");

    std::vector<int> v;
    v.reserve(1000); // might need to find a better way to reserve memory..
    std::copy(std::istream_iterator<int>(fs), std::istream_iterator<int>(), std::back_inserter(v));
    std::cout << "HELLO: " << v[0] << std::endl;

    // pt1
    int vSize = v.size();
    int p1 = { 0 };
    for(int i=0; i < vSize; i++)
    {
        std::vector<int>::const_iterator first = v.begin() + i;
        std::vector<int>::const_iterator last = v.begin() + i + 2;
        std::vector<int> tmpVector(first, last);
        if (tmpVector[0] < tmpVector[1])
        {
            p1 += 1;
        }
    }
    std::cout << "Part 1 Solution:" << std::endl;
    std::cout << p1 << std::endl;

    // pt2
    int p2 = { 0 };
    std::vector<int> tree;
    for(int i=0; i < vSize; i++)
    {
        std::vector<int>::const_iterator first = v.begin() + i;
        std::vector<int>::const_iterator last = v.begin() + i + 3;
        std::vector<int> tmpVector(first, last);

        int current_tree = std::accumulate(tmpVector.begin(), tmpVector.end(), 0);
        tree.push_back(current_tree);
    }
    for(int j=0; j < tree.size(); j++)
    {
        std::vector<int>::const_iterator first = tree.begin() + j;
        std::vector<int>::const_iterator last = tree.begin() + j + 2;
        std::vector<int> tmpVector(first, last);
        if (tmpVector[0] < tmpVector[1])
        {
            p2 += 1;
        }
    }
    std::cout << "Part 2 Solution:" << std::endl;
    std::cout << p2 << std::endl;
}
