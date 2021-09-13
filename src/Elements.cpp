/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** Elements.cpp
*/

#include "Elements.hpp"

Elements::Elements() : tick(0)
{
}

Elements::~Elements()
{
}


int Elements::getTicks()
{
    return (this->tick);
}

void Elements::inTicks()
{
    this->tick++;
}