/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** Shell.hpp
*/

#pragma once

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include "Circuit.hpp"
#include "Elements.hpp"
#include "IComponent.hpp"

class Shell {
    public:
        Shell(Elements &);
        ~Shell();
        int checkShell(const std::string &cmd, nts::Circuit *circuit);
        void display(nts::Circuit *circuit);
        void simulate(nts::Circuit *circuit);
        void loop(nts::Circuit *circuit);
        void dump(nts::Circuit *circuit);
        nts::Tristate getVal(char v);
        char myGetVal(nts::Tristate v);
        int newValues(const std::string &cmd, nts::Circuit *circuit);
        std::string cmdToValue(const std::string &cmd);
        std::string cmdToInput(const std::string &cmd);
        char GetMyVal(std::string str, nts::Circuit *circuit);
        bool inputIsTrue(std::string input, nts::Circuit *circuit);

    private:
        Elements &_elem;
};