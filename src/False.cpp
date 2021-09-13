/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** True.hpp
*/

#include <iostream>
#include <string>
#include "False.hpp"

nts::False::False() {
    _type = "false";
    _value = Tristate::FALSE;
}

nts::False::~False() {
}

nts::Tristate nts::False::compute(std::size_t pin) {
    return nts::FALSE;
}

void nts::False::dump() const
{
	std::cout << "[False]" << std::endl;
}

void nts::False::setLink(std::size_t pin, nts::IComponent &other, size_t otherPin)
{
    if (pin != 1)
        throw std::invalid_argument("Bad Pin :/");
    linkedComponent = &other;
    linkedPin = otherPin;
    simulate(1);
}

void nts::False::simulate(std::size_t tick)
{
    if (linkedComponent && linkedComponent->_type == "output")
        linkedComponent->_value = _value;
}

nts::Tristate nts::False::getPinVal(std::size_t pin)
{
    return (_value);
}
