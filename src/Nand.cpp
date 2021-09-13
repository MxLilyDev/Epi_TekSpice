/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** Nand.cpp
*/

#include "Nand.hpp"

nts::Nand::Nand()
{
}

nts::Nand::~Nand()
{
}

nts::Tristate nts::Nand::getValues(nts::Tristate one, nts::Tristate two)
{
    nts::And a;
    nts::Inverter n;
    return (n.getValues(a.getValues(one, two)));
}