#include <iostream>
#include <string>
#include <map>
#include <unordered_map>

int main()
{
    std::string str = "Hello world!!";

    std::cout << "[IN]: " << str << std::endl;

    std::unordered_map<char, int> map;

    for (auto const& each_char : str)
    {
        ++map[each_char];
    }

    std::multimap<int, char, std::greater<int>> sorted_map;

    for (auto const& unique_char : map)
    {
        sorted_map.insert({ unique_char.second, unique_char.first });
    }

    std::cout << "[OUT]: " << std::endl;

    for (auto const& frequency : sorted_map)
    {
        std::cout << frequency.second << ": " << frequency.first << std::endl;
    }

    return 0;
 }