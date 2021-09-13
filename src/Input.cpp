/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Input.hpp
*/

#include "Input.hpp"

nts::Input::Input(std::string const &value)
{
    _type = "input";
    setValue(value);
    m_value = _value;
}

nts::Input::~Input() {
}

void nts::Input::setValue(std::string const &value)
{
    if (value[0] == 'U')
        _value = Tristate::UNDEFINED;
    else if (value[0] == '1')
        _value = Tristate::TRUE;
    else if (value[0] == '0')
        _value = Tristate::FALSE;
}

void nts::Input::setLink(size_t pin, IComponent &other, size_t otherPin)
{
    if (pin != 1)
        throw std::invalid_argument("Bad Pin :/");
    linkedComponent = &other;
    linkedPin = otherPin;
}

void nts::Input::dump() const
{
	std::cout << "[Input]" << std::endl;
}

nts::Tristate nts::Input::compute(std::size_t pin)
{
    return nts::FALSE;
}

void nts::Input::simulate(std::size_t tick)
{
    _value = m_value;
    if (linkedComponent->_type == "output")
        linkedComponent->_value = _value;
}

nts::Tristate nts::Input::getPinVal(std::size_t pin)
{
    return (_value);
}