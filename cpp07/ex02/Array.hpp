#pragma once

#include <iostream>

template <typename T>
class Array 
{
    private:
        T            *_data;
        unsigned int _n;
    public:
        Array()
        {
            this->_data = NULL;
        }

        Array(const unsigned int &n)
        {
            this->_n = n;
            this->_data = new(std::nothrow) T[n];
            if (!this->_data)
                throw std::logic_error("Bad allocation");
        }

        Array(const Array &obj)
        {
            this->_data = NULL;
            *this = obj;
        }

        T &operator [](const unsigned int &index)
        {
            if (index < 0 || index > this->_n)
                throw(std::logic_error("Out of range"));
            else
                return _data[index];
        }

        const T &operator [](const unsigned int &index) const
        {
            if (index < 0 || index > this->_n)
                throw(std::logic_error("Out of range"));
            else
                return _data[index];
        }

        Array &operator =(const Array &rhs)
        {
            if (&rhs != this)
            {
                this->_n = rhs.size();
                if (this->_data != NULL)
                    delete [] this->_data;
                this->_data = new(std::nothrow) T[this->_n];
                if (!this->_data)
                    throw std::logic_error("Bad allocation");
                for (unsigned int i = 0; i < this->_n; i++)
                    this->_data[i] = rhs._data[i];
            }
            return (*this);
        }

        unsigned int size() const
        {
            return (_n);
        }

        ~Array()
        {
            if (this->_data)
                delete[] this->_data;
        }
};