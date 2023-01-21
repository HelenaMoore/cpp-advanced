#include <iostream>
#include <list>
#include <set>
#include <vector>

template <class T>
void printContainer(T& a)
{
    for (auto const& element : a)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char** argv)
{
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    printContainer(test_set); // выведет four one three two, потому что в данном типе сортировка реализуется по принципу красно-чёрного дерева

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    printContainer(test_list);

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    printContainer(test_vector);

    return 0;
}