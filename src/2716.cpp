/*
** EPITECH PROJECT, 2021
** 2716 Component
** File description:
** NanoTekSpice
*/

#include "2716.hpp"

nts::C_2716::C_2716(std::string const &value)
{
}

nts::Tristate nts::C_2716::compute(std::size_t pin)
{
    return (nts::TRUE);
}

void nts::C_2716::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pins[pin] = &other;
    pinss[pin] = otherPin;
}

void nts::C_2716::dump() const
{
    std::cout << "[2716]" << std::endl;
}

void nts::C_2716::simulate(std::size_t tick) {

}

nts::Tristate nts::C_2716::getPinVal(std::size_t pin) {
    return nts::TRUE;
}
