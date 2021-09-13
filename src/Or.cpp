/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** Or.cpp
*/

#include "Or.hpp"

nts::Or::Or()
{
}

nts::Or::~Or()
{
}

nts::Tristate nts::Or::getValues(nts::Tristate one, nts::Tristate two)
{
	if (one == nts::Tristate::TRUE || two == nts::Tristate::TRUE) {
		return nts::Tristate::TRUE;
	}
	else if (one == nts::Tristate::UNDEFINED || two == nts::Tristate::UNDEFINED) {
		return nts::Tristate::UNDEFINED;
	}
	return nts::Tristate::FALSE;
}