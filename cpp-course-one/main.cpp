#include <iostream>
#include <vector>

int main(int argc, char * argv[] )
{
    std::vector<int> vec;

    vec.push_back(42);
    vec.push_back(10);

    std::cout << vec[0] << "\n";
    std::cout << vec[1] << "\n";
    std::cout << vec[2] << "\n";// you get whatever is at this place in memory

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << "\n";
    }
    return 0;
}
