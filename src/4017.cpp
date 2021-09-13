/*
** EPITECH PROJECT, 2021
** 4017 Component
** File description:
** NanoTekSpice
*/

#include "4017.hpp"

nts::C_4017::C_4017(const std::string & value){

}

void nts::C_4017::setLink(std::size_t pin, IComponent & other, std::size_t otherPin)
{
    pins[pin] = &other;
    pinss[pin] = otherPin;
}

void nts::C_4017::dump() const
{
	std::cout << "[4017]" << std::endl;
}

nts::Tristate nts::C_4017::compute(std::size_t pin) {
    return nts::TRUE;
}

void nts::C_4017::simulate(std::size_t tick) {

}

nts::Tristate nts::C_4017::getPinVal(std::size_t pin) {
    return nts::TRUE;
}
