#include <iostream>
#include <string>

class BigInteger
{
    std::string value;
public:

    std::string getValue()
    {
        return value;
    }

    BigInteger() {};

    BigInteger(const std::string& str) : value(str)
    {
        for (int i = 0; i < value.length(); ++i)
        {
            this->value[i] = value[i];
        }
    }

    ~BigInteger()
    {
        std::cout << "Destructor called";
    }

    BigInteger(const BigInteger& other) : BigInteger(other.value) {}

    BigInteger(BigInteger&& other) noexcept : value(std::exchange(other.value, nullptr)) {}

    BigInteger& operator=(const BigInteger& other)
    {
        return *this = BigInteger(other);
    }

    BigInteger& operator=(BigInteger&& other) noexcept
    {
        std::swap(value, other.value);
        return *this;
    }

    BigInteger operator + (BigInteger& other)
    {
        std::string v = other.getValue();
        size_t l1 = value.length();
        size_t l2 = v.length();

        size_t length_sum = 0;
        if (l1 < l2)
        {
            length_sum = 1 + l2;
        }
        else
        {
            length_sum = 1 + l1;
        }

        int position = 0;
        std::string sum;
        sum.resize(length_sum);
        int d1 = 0, d2 = 0, d_sum = 0;
        for (size_t i = 0; i < length_sum; ++i)
        {
            if (i < l1)
            {
                d1 = static_cast <int>(value[l1 - i - 1]) - 48;
            }
            else
            {
                d1 = 0;
            }

            if (i < l2)
            {
                d2 = static_cast <int>(v[l2 - i - 1]) - 48;
            }
            else
            {
                d2 = 0;
            }

            d_sum = d1 + d2 + position;
            position = d_sum / 10;
            sum[length_sum - i - 1] = d_sum % 10 + '0';
        }

        if (sum[0] == '0')
        {
            sum = sum.substr(1, length_sum - 1);
        }

        return BigInteger(sum);
    }

    BigInteger operator * (BigInteger& other)
    {
        std::string v = other.getValue();
        size_t l1 = value.length();
        size_t l2 = v.length();

        if (l1 * l2 == 0)
        {
            return std::to_string(0);
        }

        size_t length_prod = l1 + l2;

        int* arr1 = new int[l1];
        int* arr2 = new int[l2];

        int** arr_prod = new int* [l2];
        for (int i = 0; i < l2; ++i)
        {
            arr_prod[i] = new int[length_prod]();
            arr2[i] = static_cast <int>(v[i]) - 48;
        }

        for (int i = 0; i < l1; ++i)
        {
            arr1[i] = static_cast <int>(value[i]) - 48;
        }

        for (size_t j = 0; j < l2; ++j)
        {
            for (size_t i = 0; i < l1; ++i)
            {
                if ((length_prod - 1) > (i + j))
                {
                    arr_prod[j][length_prod - 1 - i - j] += arr1[l1 - i - 1] * arr2[l2 - j - 1];
                    arr_prod[j][length_prod - 2 - i - j] += arr_prod[j][length_prod - 1 - i - j] / 10;
                    arr_prod[j][length_prod - 1 - i - j] = arr_prod[j][length_prod - 1 - i - j] % 10;
                }
            }
        }

        delete[] arr1;
        delete[] arr2;

        for (size_t i = 0; i < length_prod; ++i)
        {
            for (size_t j = 1; j < l2; ++j)
            {
                arr_prod[l2 - 1 - j][length_prod - 1 - i] += arr_prod[l2 - j][length_prod - 1 - i];
                arr_prod[l2 - 1 - j][length_prod - 2 - i] += arr_prod[l2 - 1 - j][length_prod - 1 - i] / 10;
                arr_prod[l2 - 1 - j][length_prod - 1 - i] = arr_prod[l2 - 1 - j][length_prod - 1 - i] % 10;
            }
        }

        std::string result;

        if (arr_prod[0][0] > 0)
        {
            result = arr_prod[0][0] + '0';
        }

        for (size_t i = 1; i < length_prod; ++i)
        {
            result.push_back(arr_prod[0][i] + '0');
        }

        for (size_t i = 0; i < l2; ++i)
        {
            delete[] arr_prod[i];
        }
        delete[] arr_prod;

        return result;
    }

    friend std::ostream& operator<<(std::ostream& ost, const BigInteger& big_int)
    {
        return ost << big_int.value;
    }
};

int main(int argc, char** argv)
{
    auto number1 = BigInteger("114575");
    auto number2 = BigInteger("78524");
    auto result = number1 + number2;
    std::cout << result;
    std::cout << std::endl;

    auto number3 = BigInteger("99");
    auto number4 = BigInteger("99");
    auto result2 = number3 * number4;
    std::cout << result2;
    std::cout << std::endl;

    return 0;
}