/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** Nor.hpp
*/

#pragma once

#include "IComponent.hpp"
#include "Or.hpp"
#include "Inverter.hpp"

namespace nts
{
    class Nor {
        public:
            Nor();
            ~Nor();
            nts::Tristate getValues(nts::Tristate one, nts::Tristate two);
    };
}