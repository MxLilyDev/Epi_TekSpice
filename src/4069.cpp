/*
** EPITECH PROJECT, 2021
** 4069 Component
** File description:
** NanoTekSpice
*/

#include "4069.hpp"

nts::C_4069::C_4069(const std::string &value) {

}

nts::Tristate nts::C_4069::compute(std::size_t pin)
{

    return nts::TRUE;
}

void nts::C_4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pins[pin] = &other;
    pinss[pin] = otherPin;
}

void nts::C_4069::dump() const
{
	std::cout << "[4069]" << std::endl;
}

void nts::C_4069::simulate(std::size_t tick)
{
    nts::Inverter an;
    try {
        for (int a = 1; a < 13; a += 2) {
            a += (a == 7) ? 1 : 0;
            if (a < 7)
                pins.at(a + 1)->_value = an.getValues(pins.at(a)->getPinVal(pinss.at(a)));
            else
                pins.at(a)->_value = an.getValues(pins.at(a + 1)->getPinVal(pinss.at(a + 1)));
        }
    } catch (std::out_of_range const &e) {
    }
}

nts::Tristate nts::C_4069::getPinVal(std::size_t pin)
{
    nts::Inverter an;
    int a = (pin < 7) ? pin - 1 : pin + 1;
    try {
        return (an.getValues(pins.at(a)->getPinVal(pinss[a])));
    } catch (std::out_of_range const &e) {
        return (pins.at(pin)->getPinVal(pinss[pin]));
    }
}