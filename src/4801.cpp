/*
** EPITECH PROJECT, 2021
** 4801 Component
** File description:
** NanoTekSpice
*/

#include "4801.hpp"

nts::C_4801::C_4801(const std::string &value) {

}

nts::Tristate nts::C_4801::compute(std::size_t pin) {
    return nts::TRUE;
}

void nts::C_4801::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pins[pin] = &other;
    pinss[pin] = otherPin;
}

void nts::C_4801::dump() const
{
	std::cout << "[4801]" << std::endl;
}

void nts::C_4801::simulate(std::size_t tick) {

}

nts::Tristate nts::C_4801::getPinVal(std::size_t pin) {
    return nts::TRUE;
}
