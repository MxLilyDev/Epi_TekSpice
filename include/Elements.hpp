/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** Elements.hpp
*/

#pragma once

class Elements {
    protected:
        int tick;
    public:
        Elements();
        ~Elements();
        int getTicks();
        void inTicks();
};