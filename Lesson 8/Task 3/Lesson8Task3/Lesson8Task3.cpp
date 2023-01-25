#include <iostream>

class SomeClass
{
private:
    int m_value = 0;
public:
    SomeClass(int value) : m_value(value) {};
    int get_value() { return m_value; }
};

template <class T>
class UniquePtr
{
private:
    T* ptr;

public:
    UniquePtr(T* p = nullptr)
    {
        ptr = p;
    }
   
    T* release()
    {
        T* raw_ptr = ptr;
        ptr = nullptr;
        return raw_ptr;
    }

    T& operator*() { return *ptr; }

    UniquePtr(const UniquePtr&) = delete;

    UniquePtr& operator=(const UniquePtr&) = delete;

    ~UniquePtr() { delete ptr; }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    
    SomeClass* obj = new SomeClass(10);
    UniquePtr<SomeClass> un_ptr1(obj);
    SomeClass* p = un_ptr1.release();
    std::cout << "un_ptr1 высвободил указатель на значение: " << p->get_value() << std::endl;

    UniquePtr<int> un_ptr2(new int(15));
    std::cout << "un_ptr2 указывает на значение: " << *un_ptr2 << std::endl; 

    return 0;
}