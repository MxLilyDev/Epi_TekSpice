/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** And.cpp
*/

#include "And.hpp"

nts::And::And()
{
}

nts::And::~And()
{
}

nts::Tristate nts::And::getValues(nts::Tristate one, nts::Tristate two)
{
	if (one == nts::Tristate::TRUE && two == nts::Tristate::TRUE) {
		return nts::Tristate::TRUE;
	}
	else if (one == nts::Tristate::FALSE || two == nts::Tristate::FALSE) {
		return nts::Tristate::FALSE;
	}
	return nts::Tristate::UNDEFINED;
}