#include "Matrix.h"

using namespace std;
namespace algebra
{

    template <typename T>
    Matrix<T>::Matrix() : data(nullptr), size(0) {}

    template <typename T>
    Matrix<T>::Matrix(size_t size) : size(size)
    {
        data = new T[size];
    }

    template <typename T>
    Matrix<T>::Matrix(const Matrix& other) : size(other.size)
    {
        data = new T[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    template <typename T>
    Matrix<T>::Matrix(Matrix&& other) noexcept : data(other.data), size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
    }

    template <typename T>
    Matrix<T>::~Matrix()
    {
        delete[] data;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            T* newData = new T[other.size];
            for (size_t i = 0; i < other.size; ++i)
            {
                newData[i] = other.data[i];
            }
            delete[] data;
            data = newData;
            size = other.size;
        }
        return *this;
    }

    template <typename T>
    Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            size = other.size;

            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    template <typename T>
    T& Matrix<T>::operator[](size_t index)
    {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    template <typename T>
    const T& Matrix<T>::operator[](size_t index) const
    {
        if (index >= size)
        {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    template <typename T>
    ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
    {
        for (size_t i = 0; i < matrix.size; ++i)
        {
            os << matrix.data[i] << " ";
        }
        return os;
    }

    template <typename T>
    istream& operator>>(std::istream& is, Matrix<T>& matrix)
    {
        for (size_t i = 0; i < matrix.size; ++i)
        {
            is >> matrix.data[i];
        }
        return is;
    }

    template <typename T>
    void Matrix<T>::fill(Generator& generator)
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = static_cast<T>(generator.generate());
        }
    }

    template <typename T>
    size_t Matrix<T>::getSize() const
    {
        return size;
    }

    template class Matrix<int>;
    template ostream& algebra::operator<<<int>(ostream& os, const algebra::Matrix<int>& matrix);
    template istream& algebra::operator>><int>(istream& is, algebra::Matrix<int>& matrix);

}