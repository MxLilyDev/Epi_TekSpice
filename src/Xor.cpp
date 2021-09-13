/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** XXor.cpp
*/

#include "Xor.hpp"

nts::Xor::Xor()
{
}

nts::Xor::~Xor()
{
}

nts::Tristate nts::Xor::getValues(nts::Tristate one, nts::Tristate two)
{
	if (one == nts::Tristate::UNDEFINED || two == nts::Tristate::UNDEFINED) {
		return nts::Tristate::UNDEFINED;
	}
	else if (one != two) {
		return nts::Tristate::TRUE;
	}
	return nts::Tristate::FALSE;
}