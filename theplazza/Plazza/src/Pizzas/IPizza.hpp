/*
** EPITECH PROJECT, 2022
** B-CCP-400-MLH-4-1-theplazza-thomas.ott
** File description:
** Pizza.hpp
*/

#pragma once
#include <iostream>
#include <vector>

namespace Plazza {
    class IPizza {
        public:
            enum Ingredients {
                INGR_BICHE,
                INGR_TOMATO,
                INGR_GRUYERE,
                INGR_HAM,
                INGR_EGGPLANTS,
                INGR_MUSHROOMS,
                INGR_GOAT_CHEESE,
                INGR_STEAK,
                INGR_CHIEF_LOVE
            };
            enum PizzaType
            {
                UNKNOWN_TYPE = 0,
                Regina = 1,
                Margarita = 2,
                Americana = 4,
                Fantasia = 8
            };
            enum PizzaSize
            {
                UNKNOWN_SIZE = 0,
                S = 1,
                M = 2,
                L = 4,
                XL = 8,
                XXL = 16
            };
            virtual ~IPizza() = default;
            virtual const PizzaSize &getSize() const = 0;
            virtual PizzaType getType() const = 0;
            virtual const int &getBakedTime() const = 0;
            virtual const std::vector<Plazza::IPizza::Ingredients> &getIngredients() const = 0;
    };
}
