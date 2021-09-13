/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** File.cpp
*/

#include "File.hpp"

File::File()
{
}

File::~File()
{
}

int File::open(std::string fileName)
{
    std::ifstream file;

    file.open(fileName);
    if (!file)
        std::cerr << "NanoTekSpices: " << fileName << ": No such file or directory" << std::endl;
    else
        std::cout << file.rdbuf();
    file.close();
    return (0);
}