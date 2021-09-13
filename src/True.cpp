/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** True.hpp
*/

#include <iostream>
#include <string>
#include "True.hpp"

nts::True::True()
{
    _type = "true";
    _value = Tristate::TRUE;
}

nts::True::~True()
{
}

nts::Tristate nts::True::compute(std::size_t pin)
{
    return nts::FALSE;
}

void nts::True::setLink(std::size_t pin, nts::IComponent &other, size_t otherPin)
{
    if (pin != 1)
        throw std::invalid_argument("Bad Pin :/");
    linkedComponent = &other;
    linkedPin = otherPin;
    simulate(1);
}

void nts::True::dump() const
{
	std::cout << "[True]" << std::endl;
}

void nts::True::simulate(std::size_t tick)
{
    if (linkedComponent && linkedComponent->_type == "output")
        linkedComponent->_value = _value;
}

nts::Tristate nts::True::getPinVal(std::size_t pin)
{
    return (_value);
}