/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** Circuit.cpp
*/

#include "Circuit.hpp"

nts::Circuit::Circuit(char *filename)
{
    std::ifstream circuitfile(filename);
    std::string line, lol;

    if (circuitfile.is_open()) {
        while (getline(circuitfile, line)) {
            if (line.find('#') != std::string::npos)
                line = line.substr(0, line.find('#'));
            std::istringstream lin(line);
            lin >> lol;
            if (line != "" && line[0] != '#' && lol.length() != 0)
                nts::Circuit::checkLine(line);
        }
        if ((link == 0 || chipset == 0) || (chipsets.empty() == true))
            throw std::invalid_argument("Bad Syntax in the file :/");
        circuitfile.close();
    } else
        throw std::invalid_argument("Unable to open file");
}

nts::Circuit::~Circuit()
{
}

void nts::Circuit::checkLine(std::string line)
{
    std::string str, stt, sta, stb, st;
    std::istringstream linee(line);
    Component component;

    if (line == ".chipsets:" && chipset == 0) {
        chipset = 1;
        return;
    }
    if (line == ".links:" && link == 0 && chipset == 1) {
        link = 1;
        return;
    }
    if ((line != ".chipsets:" && chipset == 0) || (line == ".chipsets:" && chipset != 0) || (line == ".links:" && link != 0))
        throw std::invalid_argument("Bad Syntax in the file :/");
    if (chipset == 1 && link == 0) {
        linee >> str;
        linee >> stt;
        if (str.length()) {
            goodChipset(str, stt);
            getValue(&sta, &stb, stt);
            chipsets[sta] = str;
            circuit.push_back({sta, component.createComponent(str, stb)});
        }
        return;
    }
    if (chipset == 1 && link == 1) {
        linee >> str;
        linee >> stt;
        if (str.length()) {
            goodLink(str, stt);
            links[stt] = str;
        }
        return;
    }
    throw std::invalid_argument("Bad Syntax in the file :/");
}

void nts::Circuit::getValue(std::string *sta, std::string *stb, std::string stt)
{
    size_t a = stt.find('(');
    if (a != std::string::npos) {
        *sta = stt.substr(0, a);
        *stb = stt.substr(a+1, a+1);
        (*stb)[1] = '\0';
    } else {
        *sta = stt;
        *stb = "U";
    }
}

void nts::Circuit::display()
{
    std::cout << "chipsets" << std::endl;
    for(auto elem : chipsets) {
        std::cout << elem.first << ": " << elem.second << std::endl;
    }
    std::cout << "links" << std::endl;
    for(auto elem : links) {
        std::cout << elem.first << ": " << elem.second << std::endl;
    }
}

void nts::Circuit::goodChipset(std::string str, std::string stt)
{
    std::string s = "input output clock true false 4011 4030 4071 4081 4069 4008 4013 4017 4040 4094 4512 4514 4801 2716";
    if (s.find(str) == std::string::npos)
        throw std::invalid_argument("Bad Type of Chipset in the file :/");
    for(auto elem : chipsets) {
        if (elem.first == stt)
            throw std::invalid_argument("Name of chipset is already use :/");
    }
}

std::map<std::string, int> nts::Circuit::generateTab()
{
    std::map<std::string, int> tab;
    tab.insert(std::pair<std::string, int>("input", 1));
    tab.insert(std::pair<std::string, int>("output", 1));
    tab.insert(std::pair<std::string, int>("clock", 1));
    tab.insert(std::pair<std::string, int>("true", 1));
    tab.insert(std::pair<std::string, int>("false", 1));
    tab.insert(std::pair<std::string, int>("4001", 13));
    tab.insert(std::pair<std::string, int>("4011", 14));
    tab.insert(std::pair<std::string, int>("4030", 14));
    tab.insert(std::pair<std::string, int>("4071", 13));
    tab.insert(std::pair<std::string, int>("4081", 14));
    tab.insert(std::pair<std::string, int>("4069", 14));
    tab.insert(std::pair<std::string, int>("4008", 16));
    tab.insert(std::pair<std::string, int>("4013", 14));
    tab.insert(std::pair<std::string, int>("4017", 15));
    tab.insert(std::pair<std::string, int>("4040", 16));
    tab.insert(std::pair<std::string, int>("4094", 16));
    tab.insert(std::pair<std::string, int>("4512", 16));
    tab.insert(std::pair<std::string, int>("4514", 24));
    tab.insert(std::pair<std::string, int>("4801", 24));
    tab.insert(std::pair<std::string, int>("2716", 24));
    return tab;
}

nts::IComponent *nts::Circuit::getIComponent(std::string str)
{
    std::vector<std::pair<std::string, std::shared_ptr<nts::IComponent>>>::iterator elem;

    for (elem = circuit.begin(); elem != circuit.end(); elem++)
        if (elem->first == str)
            return (elem->second.get());
    return (NULL);
}

void nts::Circuit::goodLink(std::string str, std::string stt)
{
    int s = 0, t = 0;
    std::string ss = "input output clock true false 4001 4011 4030 4071 4081 4069 4008 4013 4017 4040 4094 4512 4514 4801 2716";
    std::string i1 = str.substr(str.find(':') + 1), i2 = stt.substr(stt.find(':') + 1);
    std::string lin1 = str.substr(0, str.find(':'));
    std::string lin2 = stt.substr(0, stt.find(':'));
    nts::IComponent *tt;
    for(auto elem : chipsets) {
        if (elem.first == lin1 && std::stoi(i1) <= _tab[elem.second])
            s += 1;
        if (elem.first == lin2 && std::stoi(i2) <= _tab[elem.second])
            t += 1;
    }
    if (s != 1)
        throw std::invalid_argument("Unknow component name " + lin1 + " with that pin");
    if (t != 1)
        throw std::invalid_argument("Unknow component name " + lin2 + " with that pin");
    if (ss.find(chipsets[lin2]) != std::string::npos) {
        tt = getIComponent(lin1);
        getIComponent(lin2)->setLink(std::stoi(i2), *tt, std::stoi(i1));
    }
    if (ss.find(chipsets[lin1]) != std::string::npos) {
        tt = getIComponent(lin2);
        getIComponent(lin1)->setLink(std::stoi(i1), *tt, std::stoi(i2));
    }
}