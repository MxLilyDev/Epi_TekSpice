/*
** EPITECH PROJECT, 2021
** 4008 Component
** File description:
** NanoTekSpice
*/

#include "4008.hpp"

nts::C_4008::C_4008(const std::string &value) {

}

nts::Tristate nts::C_4008::compute(std::size_t pin) {
    return nts::TRUE;
}

void nts::C_4008::dump() const
{
	std::cout << "[4008]" << std::endl;
}

void nts::C_4008::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pins[pin] = &other;
    pinss[pin] = otherPin;
}

void nts::C_4008::simulate(std::size_t tick) {

}

nts::Tristate nts::C_4008::getPinVal(std::size_t pin) {
    return nts::TRUE;
}
