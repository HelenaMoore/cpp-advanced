#include <exception>
#include <iostream>

template <class T>
class Vector
{
private:
    T* arr = nullptr;
    int m_size = 0;
    int m_capacity = 0;

public:

    Vector()
    {
        this->m_capacity = 1;
        this->m_size = m_size;
        this->arr = new T[m_capacity]();
    }

    Vector(const Vector& copy)
    {
        m_size = copy.m_size;
        m_capacity = copy.m_capacity;
        delete[]arr;
        arr = new T[m_capacity];

        for (int i = 0; i < m_size; ++i)
        {
            arr[i] = copy.arr[i];
        }
    }

    Vector& operator=(const Vector& other)
    {
        if (&other != this)
        {
            m_size = other.m_size;
            m_capacity = other.m_capacity;
            delete[]arr;
            arr = new T[m_capacity];

            for (int i = 0; i < m_size; ++i)
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    T at(int index)
    {
        if (index < 0)
        {
            throw std::runtime_error("Индекс не может быть меньше нуля!");
        }
        else if (index > m_capacity - 1)
        {
            throw std::runtime_error("Превышен максимально допустимый индекс элемента!");
        }
        else if (index > m_size - 1)
        {
            throw std::runtime_error("Элемента с таким индексом нет!");
        }
        else 
        {
            return arr[index];
        }
    }

    void expandCapacity()
    {
        m_capacity *= 2;
        T* temp = arr;
        arr = new T[m_capacity];
        for (int i = 0; i < m_size; ++i)
        {
            arr[i] = temp[i];
        }
        delete[]temp;
    }

    void push_back(const T& value)
    {
        if (m_capacity == m_size)
        {
            expandCapacity();
        }
        arr[m_size] = value;
        ++m_size;
    }

    int size() const
    {
        return m_size;
    }

    int capacity() const
    {
        return m_capacity;
    }

    ~Vector()
    {
        delete[] arr;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    try
    {
        Vector<int> v;
        v.push_back(8);
        v.push_back(2);
        v.push_back(5);

        std::cout << "Размер: " << v.size() << std::endl;
        std::cout << "Вместимость: " << v.capacity() << std::endl;
        std::cout << "Последний элемент в векторе: " << v.at(v.size() - 1) << std::endl;

        v.push_back(0);
        v.push_back(16);
        v.push_back(54);
        v.push_back(8);
        v.push_back(1);

        std::cout << std::endl;
        std::cout << "Размер: " << v.size() << std::endl;
        std::cout << "Вместимость: " << v.capacity() << std::endl;
        std::cout << "Последний элемент в векторе: " << v.at(v.size() - 1) << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
