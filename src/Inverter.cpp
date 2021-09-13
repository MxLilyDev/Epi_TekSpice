/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** Inverter.cpp
*/

#include "Inverter.hpp"

nts::Inverter::Inverter()
{
}

nts::Inverter::~Inverter()
{
}

nts::Tristate nts::Inverter::getValues(nts::Tristate one)
{
    if (one == nts::Tristate::FALSE)
        return (nts::Tristate::TRUE);
    if (one == nts::Tristate::TRUE)
        return (nts::Tristate::FALSE);
    return (nts::Tristate::UNDEFINED);
}