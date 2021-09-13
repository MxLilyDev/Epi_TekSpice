/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** IComponent.hpp
*/

#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <map>
#include <unordered_map>
#include <string>
#include <functional>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    class IComponent {
        public:
            virtual ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual nts::Tristate getPinVal(std::size_t pin) = 0;
            Tristate _value = Tristate::UNDEFINED;
            Tristate m_value = Tristate::UNDEFINED;
            int _w = 0;
            std::string _type = "";
    };
}