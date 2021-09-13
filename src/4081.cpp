/*
** EPITECH PROJECT, 2021
** 4081 Component
** File description:
** NanoTekSpice
*/

#include "4081.hpp"

nts::C_4081::C_4081(const std::string &value) {

}

nts::Tristate nts::C_4081::compute(std::size_t pin) {
    return nts::TRUE;
}

void nts::C_4081::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pins[pin] = &other;
    pinss[pin] = otherPin;
}

void nts::C_4081::dump() const
{
	std::cout << "[4081]" << std::endl;
}

void nts::C_4081::simulate(std::size_t tick)
{
    nts::And an;
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

nts::Tristate nts::C_4081::getPinVal(std::size_t pin)
{
    nts::And an;
    int a = (pin == 3 || pin == 10) ? pin - 2 : pin + 1;
    try {
        return (an.getValues(pins[a]->getPinVal(pinss[a]), pins[a + 1]->getPinVal(pinss[a + 1])));
    } catch (std::out_of_range const &e) {
        return (pins.at(pin)->getPinVal(pinss[pin]));
    }
}