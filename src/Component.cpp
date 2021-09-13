/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Component Class
*/

#include "Component.hpp"

nts::Component::Component()
{
	connectors["2716"] = &Component::create2716;
	connectors["4001"] = &Component::create4001;
	connectors["4008"] = &Component::create4008;
	connectors["4011"] = &Component::create4011;
	connectors["4013"] = &Component::create4013;
	connectors["4017"] = &Component::create4017;
	connectors["4030"] = &Component::create4030;
	connectors["4040"] = &Component::create4040;
	connectors["4069"] = &Component::create4069;
	connectors["4071"] = &Component::create4071;
	connectors["4081"] = &Component::create4081;
	connectors["4094"] = &Component::create4094;
	connectors["4512"] = &Component::create4512;
	connectors["4514"] = &Component::create4514;
    connectors["4801"] = &Component::create4801;
	connectors["input"] = &Component::createInput;
	connectors["output"] = &Component::createOutput;
	connectors["clock"] = &Component::createClock;
	connectors["true"] = &Component::createTrue;
	connectors["false"] = &Component::createFalse;
}

std::unique_ptr<nts::IComponent> nts::Component::createComponent(std::string const &type, std::string const &value) const
{
    auto it{ connectors.find(type) };
    if (it != connectors.end())
    	return it->second(*this, value);
    throw std::invalid_argument("Unknow this component");
}

std::unique_ptr<nts::IComponent> nts::Component::createInput(std::string const &value) const
{
	return std::make_unique<Input>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::createOutput(std::string const &value) const
{
	return std::make_unique<Output>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::createClock(std::string const &value) const
{
	return std::make_unique<Clock>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::createTrue(std::string const &value) const
{
	return std::make_unique<True>();
}

std::unique_ptr<nts::IComponent> nts::Component::createFalse(std::string const &value) const
{
	return std::make_unique<False>();
}

std::unique_ptr<nts::IComponent> nts::Component::create2716(std::string const &value) const
{
	return std::make_unique<C_2716>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::create4001(std::string const &value) const
{
	return std::make_unique<C_4001>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::create4008(std::string const &value) const
{
	return std::make_unique<C_4008>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::create4011(std::string const &value) const
{
	return std::make_unique<C_4011>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::create4013(std::string const &value) const
{
	return std::make_unique<C_4013>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::create4017(std::string const &value) const
{
	return std::make_unique<C_4017>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::create4030(std::string const &value) const
{
	return std::make_unique<C_4030>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::create4040(std::string const &value) const
{
	return std::make_unique<C_4040>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::create4069(std::string const &value) const
{
	return std::make_unique<C_4069>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::create4071(std::string const &value) const
{
	return std::make_unique<C_4071>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::create4081(std::string const &value) const
{
	return std::make_unique<C_4081>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::create4094(std::string const &value) const
{
	return std::make_unique<C_4094>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::create4512(std::string const &value) const
{
	return std::make_unique<C_4512>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::create4514(std::string const &value) const
{
	return std::make_unique<C_4514>(value);
}

std::unique_ptr<nts::IComponent> nts::Component::create4801(std::string const &value) const
{
	return std::make_unique<C_4801>(value);
}