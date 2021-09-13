/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** Nor.cpp
*/

#include "Nor.hpp"

nts::Nor::Nor()
{
}

nts::Nor::~Nor()
{
}

nts::Tristate nts::Nor::getValues(nts::Tristate one, nts::Tristate two)
{
    nts::Inverter n;
    nts::Or a;
    return (n.getValues(a.getValues(one, two)));
}