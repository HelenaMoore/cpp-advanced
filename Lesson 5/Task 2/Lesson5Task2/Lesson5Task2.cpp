#include <iostream>

template <class T>
class Table
{
private:
    T** table = nullptr;
    int rows = 0;
    int cols = 0;

public:  
    
    Table(int rows_number, int cols_number) : rows(rows_number), cols(cols_number)
    {
        table = new T * [rows];
        for (int i = 0; i < rows; ++i)
        {
            table[i] = new T[cols]{};
        }
    }

    Table(const Table&) = delete; //компилятор выдаёт ошибку C2280 при создании экземпляра, строка 101: auto test = Table<int>(2, 3);
    Table& operator=(const Table&) = delete;

    /*
    А с конструктором копирования и оператором присваивания работает:
    _________________________________________________________________

    Table(const Table& copy)
    {
        rows = copy.rows;
        cols = copy.cols;

        table = new T * [rows];
        for (int i = 0; i < rows; ++i)
        {
            table[i] = new T[cols];
        }

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                table[i][j] = copy.table[i][j];
            }
        }
    };
    
    Table& operator=(const Table& other)
    {
        if (&other != this)
        {
            for (int i = 0; i < rows; ++i)
            {
                delete[] table[i];
            }
            delete[] table;

            rows = other.rows;
            cols = other.cols;

            table = new T * [rows];
            for (int i = 0; i < rows; ++i)
            {
                table[i] = new T[cols];
            }

            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    table[i][j] = other.table[i][j];
                }
            }
        }
        return *this;
    };
    __________________________________________________________________
    */

    const T* operator[](int index) const { return table[index]; }
    T* operator[](int index) { return table[index]; }

    int size() const
    {
        return rows * cols;
    }

    ~Table()
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] table[i];
        }
        delete[] table;
    }
};

int main(int argc, char** argv)
{
    auto test = Table<int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0];

    return 0;
}