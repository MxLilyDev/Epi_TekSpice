/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** main
*/

#include <iostream>
#include "File.hpp"
#include "Circuit.hpp"
#include "Shell.hpp"
#include "Elements.hpp"

int main(int ac, char **av)
{
    File file;
    std::string cmd;
    Elements elem;
    Shell shell(elem);
    int par = 0;

    if (ac != 2) {
        std::cout << "Usage: ./nanotekspice [filepath]"<< std::endl;
        return (84);
    }
    try {
        nts::Circuit circuit(av[1]);
        for (int i = 0; par == 0; i++) {
            std::cout << "> ";
            if (!std::getline(std::cin, cmd))
                return (0);
            par = shell.checkShell(cmd, &circuit);
        }
    } catch (...) {
        return (84);
    }
    return (0);
}
