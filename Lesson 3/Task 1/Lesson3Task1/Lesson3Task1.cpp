#include <exception>
#include <iostream>

class SmartArray
{
private:

	int logical_size = 0;
	int actual_size = 0;
	int* arr;

public:
	SmartArray(int actual_size)
	{
		this->logical_size = 0;
		this->actual_size = actual_size;
		this->arr = new int[actual_size]();
	}

	void addElement(int new_element)
	{
		if (logical_size < actual_size)
		{
			arr[logical_size] = new_element;
			++logical_size;
		}
		else {
			throw std::exception("Превышен максимальный размер массива!");
		}
	}

	int getElement(int index)
	{
		if (index < 0)
		{
			throw std::exception("Индекс не может быть меньше нуля!");
		}
		else if (index > actual_size - 1)
		{
			throw std::exception("Превышен максимально допустимый индекс элемента!");
		}
		else if (index > logical_size - 1)
		{
			throw std::exception("Элемента с таким индексом нет.");
		}
		else {
			return arr[index];
		}
	}

	~SmartArray()
	{
		delete[] arr;
	}
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	try
	{
		SmartArray arr(5);
		arr.addElement(1);
		arr.addElement(4);
		arr.addElement(155);
		arr.addElement(14);
		arr.addElement(15);
		std::cout << arr.getElement(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}
