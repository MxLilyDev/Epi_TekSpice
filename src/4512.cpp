/*
** EPITECH PROJECT, 2021
** 4512 Component
** File description:
** NanoTekSpice
*/

#include "4512.hpp"

nts::C_4512::C_4512(const std::string &value) {

}

nts::Tristate nts::C_4512::compute(std::size_t pin) {
    return nts::TRUE;
}

void nts::C_4512::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pins[pin] = &other;
    pinss[pin] = otherPin;
}

void nts::C_4512::dump() const
{
	std::cout << "[4512]" << std::endl;
}

void nts::C_4512::simulate(std::size_t tick) {

}

nts::Tristate nts::C_4512::getPinVal(std::size_t pin) {
    return nts::TRUE;
}
