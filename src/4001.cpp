/*
** EPITECH PROJECT, 2021
** 4001 Component
** File description:
** NanoTekSpice
*/

#include "4001.hpp"

nts::C_4001::C_4001(std::string const &value)
{
}

nts::Tristate nts::C_4001::compute(std::size_t pin) {
    return nts::TRUE;
}

void nts::C_4001::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pins[pin] = &other;
    pinss[pin] = otherPin;
}

void nts::C_4001::dump() const
{
	std::cout << "[4001]" << std::endl;
}

void nts::C_4001::simulate(std::size_t tick)
{
    nts::Nor an;
    try {
        for (int a = 1; a < 13; a += 3) {
            a += (a == 7) ? 1 : 0;
            if (a == 1 || a == 8)
                pins.at(a + 2)->_value = an.getValues(pins.at(a)->getPinVal(pinss.at(a)), pins.at(a + 1)->getPinVal(pinss.at(a + 1)));
            else
                pins.at(a)->_value = an.getValues(pins.at(a + 1)->getPinVal(pinss.at(a + 1)), pins.at(a + 2)->getPinVal(pinss.at(a + 2)));
        }
    } catch (std::out_of_range const &e) {
    }
}

nts::Tristate nts::C_4001::getPinVal(std::size_t pin)
{
    nts::Nor an;
    int a = (pin == 3 || pin == 10) ? pin - 2 : pin + 1;
    try {
        return (an.getValues(pins.at(a)->getPinVal(pinss.at(a)), pins.at(a + 1)->getPinVal(pinss.at(a + 1))));
    } catch (std::out_of_range const &e) {
        return (pins.at(pin)->getPinVal(pinss.at(pin)));
    }
}