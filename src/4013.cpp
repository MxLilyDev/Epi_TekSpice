/*
** EPITECH PROJECT, 2021
** 4013 Component
** File description:
** NanoTekSpice
*/

#include "4013.hpp"

nts::C_4013::C_4013(const std::string &value)
{
}

nts::Tristate nts::C_4013::compute(std::size_t pin) {
    return nts::TRUE;
}

void nts::C_4013::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pins[pin] = &other;
    pinss[pin] = otherPin;
}

void nts::C_4013::dump() const
{
	std::cout << "[4013]" << std::endl;
}

void nts::C_4013::simulate(std::size_t tick)
{
}

nts::Tristate nts::C_4013::getPinVal(std::size_t pin) {
    return nts::TRUE;
}
