/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** File.hpp
*/

#pragma once

#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>

class File {
    public:
        File();
        ~File();
        int open(std::string fileName);
};