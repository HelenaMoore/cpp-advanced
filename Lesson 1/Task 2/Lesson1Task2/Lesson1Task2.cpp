#include <algorithm>
#include <iostream>
#include <string>
#include <variant>
#include <vector>

std::variant<int, std::string, std::vector<int>> getVariant()
{
	std::srand(std::time(nullptr));
	int random_variable = std::rand() % 3;

	std::variant<int, std::string, std::vector<int>> result;
	switch (random_variable)
	{
	case 0:
		result = 5;
		break;
	case 1:
		result = "string";
		break;
	case 2:
		result = std::vector<int>{ 1, 2, 3, 4, 5 };
		break;
	default:
		break;
	}
	return result;
}

int main(int argc, char** argv)
{
	auto variant = getVariant();
	if (std::holds_alternative<int>(variant))
	{
		std::cout << std::get<int>(variant) * 2;
	}
	else if (std::holds_alternative<std::string>(variant))
	{
		std::cout << std::get<std::string>(variant);
	}
	else if (std::holds_alternative<std::vector<int>>(variant))
	{
		std::vector<int> elements = std::get<std::vector<int>>(variant);

		std::for_each(elements.begin(), elements.end(), [](const int n)
			{
				std::cout << n << " ";
			});
	}

	return 0;
}