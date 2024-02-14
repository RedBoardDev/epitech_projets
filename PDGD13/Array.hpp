/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD13-thomas.ott
** File description:
** Array.hpp
*/

#pragma once

#include <iostream>
#include <functional>
#include <stdexcept>

template <typename Type, std::size_t _size>
class Array
{
    public:
        Type _arr [_size];
        Type &operator[](std::size_t pos);
        const Type& operator[](std::size_t index) const;
        std::size_t size() const { return (_size); };
        void forEach(const std::function<void(const Type&)>& task) const;
        template <typename U>
        Array<U, _size> convert(const std::function<U(const Type&)>&converter) const;
};

template <typename Type, std::size_t _size>
Type &Array<Type, _size>::operator[](std::size_t pos)
{
    if (pos >= _size)
        throw std::out_of_range("Out of range");
    return (this->_arr[pos]);
}

template <typename Type, std::size_t _size>
const Type& Array<Type, _size>::operator[](std::size_t index) const {
    if (index >= _size) {
        throw std::out_of_range("Out of range");
    }
    return this->_arr[index];
}

template <typename Type, std::size_t _size>
void Array<Type, _size>::forEach(const std::function<void(const Type&)>& task) const
{
    size_t i = 0;

    while (i < _size) {
        task(this->_arr[i]);
        ++i;
    }
}

template <typename Type, size_t _size>
template <typename U>
Array<U, _size> Array<Type, _size>::convert(const std::function<U(const Type&)>&converter) const
{
    Array<U, _size> newArr = {};
    size_t i = 0;

    while (i < _size) {
        newArr[i] = converter(_arr[i]);
        ++i;
    }
    return (newArr);
}

template <typename Type, size_t _size>
std::ostream &operator<<(std::ostream &os, const Array<Type, _size> &d) {
    size_t i = 0;

    os << "[";
    while (i < d.size()) {
        os << d[i];
        if (i < d.size() - 1)
            os << ", ";
        ++i;
    }
    os << "]";
    return (os);
};
