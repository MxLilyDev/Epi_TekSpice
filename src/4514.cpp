/*
** EPITECH PROJECT, 2021
** 4514 Component
** File description:
** NanoTekSpice
*/

#include "4514.hpp"

nts::C_4514::C_4514(const std::string &value) {

}

nts::Tristate nts::C_4514::compute(std::size_t pin) {
    return nts::TRUE;
}

void nts::C_4514::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pins[pin] = &other;
    pinss[pin] = otherPin;
}

void nts::C_4514::dump() const
{
	std::cout << "[4514]" << std::endl;
}

void nts::C_4514::simulate(std::size_t tick) {

}

nts::Tristate nts::C_4514::getPinVal(std::size_t pin) {
    return nts::TRUE;
}
