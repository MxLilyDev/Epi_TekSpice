/*
** EPITECH PROJECT, 2021
** 4040 Component
** File description:
** NanoTekSpice
*/

#include "4040.hpp"

nts::C_4040::C_4040(const std::string &value) {

}

nts::Tristate nts::C_4040::compute(std::size_t pin) {
    return nts::TRUE;
}

void nts::C_4040::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pins[pin] = &other;
    pinss[pin] = otherPin;
}

void nts::C_4040::dump() const
{
	std::cout << "[4040]" << std::endl;
}

void nts::C_4040::simulate(std::size_t tick) {

}

nts::Tristate nts::C_4040::getPinVal(std::size_t pin) {
    return nts::TRUE;
}
