/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Output.hpp
*/

#include "Output.hpp"

nts::Output::Output(std::string const &value)
{
    _type = "output";
    _value = Tristate::UNDEFINED;
    setValue(value);
}

void nts::Output::setValue(std::string const &value)
{
    if (value[0] == 'U')
        _value = Tristate::UNDEFINED;
    else if (value[0] == '1')
        _value = Tristate::TRUE;
    else if (value[0] == '0')
        _value = Tristate::FALSE;
}

void nts::Output::setLink(size_t pin, IComponent &other, size_t otherPin)
{
    if (pin != 1)
        throw std::invalid_argument("Bad Pin :/");
    linkedComponent = &other;
    linkedPin = otherPin;
}

nts::Output::~Output() {
}

nts::Tristate nts::Output::compute(std::size_t pin) {
    return nts::FALSE;
}

void nts::Output::dump() const
{
	std::cout << "[Output]" << std::endl;
}

void nts::Output::simulate(std::size_t tick)
{
}

nts::Tristate nts::Output::getPinVal(std::size_t pin) {
    return nts::TRUE;
}
