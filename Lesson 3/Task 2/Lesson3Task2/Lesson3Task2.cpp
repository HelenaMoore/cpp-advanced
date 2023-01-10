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

	void printArray()
	{
		for (int i = 0; i < actual_size; ++i)
		{
			if (i > logical_size - 1)
			{
				std::cout << "_" << std::endl;
			}
			else {
				std::cout << arr[i] << std::endl;
			}
		}
		std::cout << std::endl;
	}

	SmartArray& operator=(const SmartArray& other)
	{
		if (&other != this)
		{
			if (actual_size > 0)
			{
				delete[] arr;
				actual_size = other.actual_size;
				logical_size = other.logical_size;
				arr = new int[actual_size];
				for (int i = 0; i < logical_size; ++i)
				{
					arr[i] = other.arr[i];
				}
				return *this;
			}
		}
	};

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
		
		SmartArray new_array(2);
		new_array.addElement(44);
		new_array.addElement(34);

		arr.printArray();
		arr = new_array;
		arr.printArray();
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}