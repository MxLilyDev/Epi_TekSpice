/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** Circuit.hpp
*/

#pragma once

#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <utility>
#include <functional>
#include "Component.hpp"

namespace nts
{
    class Circuit {
        public:
            Circuit(char *filename);
            ~Circuit();
            void checkLine(std::string line);
            void display();
            std::map<std::string, int> generateTab();
            void goodChipset(std::string str, std::string stt);
            void goodLink(std::string str, std::string stt);
    		void getValue(std::string *sta, std::string *stb, std::string stt);
    		std::map<std::string, std::string> chipsets;
            std::map<std::string, std::string> links;
            std::vector<std::pair<std::string, std::shared_ptr<nts::IComponent>>> circuit;
            nts::IComponent *getIComponent(std::string str);
            std::map<std::string, int> _tab = generateTab();
            int chipset = 0;
            int link = 0;
    };
}