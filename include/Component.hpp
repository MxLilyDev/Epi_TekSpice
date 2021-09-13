/*
** EPITECH PROJECT, 2021
** B-OOP-400-LYN-4-1-tekspice-prince.miyigbena
** File description:
** Component.hpp
*/

#pragma once

#include "IComponent.hpp"
#include "2716.hpp"
#include "4001.hpp"
#include "4008.hpp"
#include "4011.hpp"
#include "4013.hpp"
#include "4017.hpp"
#include "4030.hpp"
#include "4040.hpp"
#include "4069.hpp"
#include "4071.hpp"
#include "4081.hpp"
#include "4094.hpp"
#include "4512.hpp"
#include "4514.hpp"
#include "4801.hpp"
#include "Input.hpp"
#include "Output.hpp"
#include "Clock.hpp"
#include "True.hpp"
#include "False.hpp"

namespace nts
{
	class Component {
	public:
		Component();
		~Component() = default;

		std::unique_ptr<IComponent> createComponent(std::string const &type, std::string const &value) const;

	private:
        using createConnector = std::function<std::unique_ptr<IComponent>(Component const &, std::string const &)>;
        std::map<std::string, createConnector> connectors;
		std::unique_ptr<nts::IComponent> createFalse(std::string const &value) const;
		std::unique_ptr<nts::IComponent> createTrue(std::string const &value) const;
		std::unique_ptr<nts::IComponent> createClock(std::string const &value) const;
		std::unique_ptr<nts::IComponent> createInput(std::string const &value) const;
		std::unique_ptr<nts::IComponent> createOutput(std::string const &value) const;
		std::unique_ptr<IComponent> create2716(std::string const &value) const;
		std::unique_ptr<IComponent> create4001(std::string const &value) const;
		std::unique_ptr<IComponent> create4008(std::string const &value) const;
		std::unique_ptr<IComponent> create4011(std::string const &value) const;
		std::unique_ptr<IComponent> create4013(std::string const &value) const;
		std::unique_ptr<IComponent> create4017(std::string const &value) const;
		std::unique_ptr<IComponent> create4030(std::string const &value) const;
		std::unique_ptr<IComponent> create4040(std::string const &value) const;
		std::unique_ptr<IComponent> create4069(std::string const &value) const;
		std::unique_ptr<IComponent> create4071(std::string const &value) const;
		std::unique_ptr<IComponent> create4081(std::string const &value) const;
		std::unique_ptr<IComponent> create4094(std::string const &value) const;
		std::unique_ptr<IComponent> create4512(std::string const &value) const;
		std::unique_ptr<IComponent> create4514(std::string const &value) const;
		std::unique_ptr<IComponent> create4801(std::string const &value) const;
	};
}
