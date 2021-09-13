/*
** EPITECH PROJECT, 2020
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** Shell.cpp
*/

#include "Shell.hpp"

volatile sig_atomic_t stop;

Shell::Shell(Elements &elem) : _elem(elem)
{
}

Shell::~Shell()
{
}

void inthand(int signum) {
    stop = 1;
}

int Shell::checkShell(const std::string &cmd, nts::Circuit *circuit)
{
    if (cmd.compare("exit") == 0)
        return (-1);
    else if (cmd.compare("display") == 0)
        display(circuit);
    else if (cmd.compare("simulate") == 0) {
        _elem.inTicks();
        simulate(circuit);
    } else if (cmd.compare("loop") == 0)
        loop(circuit);
    else if (cmd.compare("dump") == 0)
        dump(circuit);
    else if (newValues(cmd, circuit) != 0)
        std::cout << "Error: Please choose: [display.simulate.loop.dump.input=value.exit]" << std::endl;
    return (0);
}

char Shell::myGetVal(nts::Tristate v)
{
    if (v == nts::Tristate::FALSE)
        return ('0');
    else if (v == nts::Tristate::TRUE)
        return ('1');
    else
        return ('U');
}

char Shell::GetMyVal(std::string str, nts::Circuit *circuit)
{
    std::vector<std::pair<std::string, std::shared_ptr<nts::IComponent>>>::iterator elem;

    for (elem = circuit->circuit.begin(); elem != circuit->circuit.end(); elem++)
        if (elem->first == str)
            return myGetVal(elem->second->_value);
}

void Shell::display(nts::Circuit *circuit)
{
    std::map<std::string, std::string>::iterator elem;
    std::cout << "tick: " << _elem.getTicks() << std::endl;
    std::cout << "input(s):" << std::endl;

    for (elem = circuit->chipsets.begin(); elem != circuit->chipsets.end(); elem++)
        if (elem->second == "input" || elem->second == "clock")
            std::cout << "  " << elem->first << ": " << GetMyVal(elem->first, circuit) << std::endl;
    std::cout << "output(s):" << std::endl;
    for (elem = circuit->chipsets.begin(); elem != circuit->chipsets.end(); elem++)
        if (elem->second == "output")
            std::cout << "  " << elem->first << ": " << GetMyVal(elem->first, circuit) << std::endl;
}

void Shell::simulate(nts::Circuit *circuit)
{
    std::vector<std::pair<std::string, std::shared_ptr<nts::IComponent>>>::iterator elem;
    for (elem = circuit->circuit.begin(); elem != circuit->circuit.end(); elem++)
        if (elem->second->_type == "input" || elem->second->_type == "clock")
            elem->second->simulate(_elem.getTicks());
    for (elem = circuit->circuit.begin(); elem != circuit->circuit.end(); elem++)
        if (elem->second->_type != "input" && elem->second->_type != "clock")
            elem->second->simulate(_elem.getTicks());
}

void Shell::loop(nts::Circuit *circuit)
{
    signal(SIGINT, inthand);
    while(!stop) {
        simulate(circuit);
        _elem.inTicks();
        display(circuit);
    }
}

void Shell::dump(nts::Circuit *circuit)
{
    std::vector<std::pair<std::string, std::shared_ptr<nts::IComponent>>>::iterator elem;
    for (elem = circuit->circuit.begin(); elem != circuit->circuit.end(); elem++)
        elem->second->dump();
}

nts::Tristate Shell::getVal(char v)
{
    if (v == '0')
        return (nts::Tristate::FALSE);
    else if (v == '1')
        return (nts::Tristate::TRUE);
    else
        return (nts::Tristate::UNDEFINED);
}

int Shell::newValues(const std::string &cmd, nts::Circuit *circuit)
{
    std::map<std::string, std::shared_ptr<nts::IComponent>>::iterator elem;
    std::string values;
    std::string input;

    if (cmd.find("=") != std::string::npos) {
        values = cmdToValue(cmd);
        if ((values.length() != 1) || ((values.compare("U") != 0) && (values.compare("0") != 0) && (values.compare("1") != 0)))
            return (-1);
        input = cmdToInput(cmd);
        if (!inputIsTrue(input, circuit))
            return (-1);
        circuit->getIComponent(input)->m_value = getVal(values[0]);
        circuit->getIComponent(input)->_w = 1;
        return (0);
    }
    return (-1);
}

std::string Shell::cmdToValue(const std::string &cmd)
{
    size_t pos;

    pos = cmd.find("=") + 1;
    if (pos != std::string::npos)
        return (cmd.substr(pos));
    return ("");
}

std::string Shell::cmdToInput(const std::string &cmd)
{
    size_t pos;

    pos = cmd.find("=");
    if (pos != std::string::npos)
        return (cmd.substr(0, pos));
    return ("");
}

bool Shell::inputIsTrue(std::string input, nts::Circuit *circuit)
{
    std::map<std::string, std::string>::iterator elem;

    for (elem = circuit->chipsets.begin(); elem != circuit->chipsets.end(); elem++)
        if (elem->first == input && (elem->second == "input" || elem->second == "clock"))
            return (true);
    return (false);
}