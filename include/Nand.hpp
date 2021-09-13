/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** Nand.hpp
*/

#pragma once

#include "IComponent.hpp"
#include "And.hpp"
#include "Inverter.hpp"

namespace nts
{
    class Nand {
        public:
            Nand();
            ~Nand();
            nts::Tristate getValues(nts::Tristate one, nts::Tristate two);
    };
}