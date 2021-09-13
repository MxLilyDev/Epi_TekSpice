/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Clock.hpp
*/

#include "Clock.hpp"

nts::Clock::Clock(std::string const &value)
{
    _type = "clock";
    setValue(value);
    m_value = _value;
}

nts::Clock::~Clock()
{
}

void nts::Clock::setValue(std::string const &value)
{
    if (value[0] == 'U')
        _value = Tristate::UNDEFINED;
    else if (value[0] == '1')
        _value = Tristate::TRUE;
    else if (value[0] == '0')
        _value = Tristate::FALSE;
}

void nts::Clock::setLink(size_t pin, IComponent &other, size_t otherPin)
{
    if (pin != 1)
        throw std::invalid_argument("Bad Pin :/");
    linkedComponent = &other;
    linkedPin = otherPin;
}

void nts::Clock::dump() const
{
	std::cout << "[Clock]" << std::endl;
}

nts::Tristate nts::Clock::compute(std::size_t pin)
{
    return nts::FALSE;
}

void nts::Clock::simulate(std::size_t tick)
{
    if (_w == 1) {
        _value = m_value;
    } else if (_value == nts::Tristate::TRUE) {
		_value = nts::Tristate::FALSE;
	} else if (_value == nts::Tristate::FALSE) {
		_value = nts::Tristate::TRUE;
    }
    m_value = _value;
    if (linkedComponent && linkedComponent->_type == "output")
        linkedComponent->_value = _value;
    _w = 0;
}

nts::Tristate nts::Clock::getPinVal(std::size_t pin)
{
    return (_value);
}