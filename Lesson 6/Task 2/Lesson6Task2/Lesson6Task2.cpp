#include <iostream>
#include <set>

int main()
{
    int size = 0, element = 0;

    std::cout << "[IN]: " << std::endl;
    std::cin >> size;

    std::set<int, std::greater<>> number_set;
    int counter = 0;
    while (counter < size)
    {
        std::cin >> element;
        number_set.insert(element);
        ++counter;
    }
   
    std::cout << "[OUT]: " << std::endl;

    for (auto const& frequency : number_set)
    {
        std::cout << frequency << std::endl;
    }

    return 0;
}