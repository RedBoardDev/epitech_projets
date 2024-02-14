/*
** EPITECH PROJECT, 2022
** B-PDG-300-MLH-3-1-PDGD13-thomas.ott
** File description:
** Algorithm.hpp
*/

#pragma once

template <typename T>
void swap(T &var1, T &var2)
{
    T temp = var1;
    var1 = var2;
    var2 = temp;
}

template <typename T>
const T min(const T &var1, const T &var2)
{
    return var1 < var2 ? var1 : var2;
}

template <typename T>
const T &max(const T &var1, const T &var2)
{
    return (var1 < var2 ? var2 : var1);
}

template <typename T>
const T &clamp(const T &var1, const T &var2, const T &var3)
{
    if (var1 < var2)
        return var2;
    if (var3 < var1)
        return var3;
    return var1;
}
