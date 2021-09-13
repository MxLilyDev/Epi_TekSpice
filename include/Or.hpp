/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** Or.hpp
*/

#pragma once

#include "IComponent.hpp"

namespace nts
{
    class Or {
        public:
            Or();
            ~Or();
            nts::Tristate getValues(nts::Tristate one, nts::Tristate two);
    };
}