/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** Inverter.hpp
*/

#pragma once

#include "IComponent.hpp"

namespace nts
{
    class Inverter {
        public:
            Inverter();
            ~Inverter();
            nts::Tristate getValues(nts::Tristate one);
    };
}