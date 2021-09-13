/*
** EPITECH PROJECT, 2021
** 4094 Component
** File description:
** NanoTekSpice
*/

#include "4094.hpp"

nts::C_4094::C_4094(const std::string &value) {

}

nts::Tristate nts::C_4094::compute(std::size_t pin) {
    return nts::TRUE;
}

void nts::C_4094::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pins[pin] = &other;
    pinss[pin] = otherPin;
}

void nts::C_4094::dump() const
{
	std::cout << "[4094]" << std::endl;
}

void nts::C_4094::simulate(std::size_t tick) {

}

nts::Tristate nts::C_4094::getPinVal(std::size_t pin) {
    return nts::TRUE;
}
