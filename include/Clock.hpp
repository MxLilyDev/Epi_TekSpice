/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Clock.hpp
*/

#pragma once

#include <string>
#include "IComponent.hpp"

namespace nts
{
	class Clock : public IComponent {
		public:
			Clock(std::string const &value);
			~Clock() override;

            Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, IComponent &other, size_t otherPin) override;
            void dump() const override;
            void setValue(std::string const &value);
			nts::Tristate getPinVal(std::size_t pin);
            void simulate(std::size_t tick);

        private:
            IComponent *linkedComponent = nullptr;
            size_t linkedPin = 1;
            std::map<std::size_t, nts::IComponent &> pins;
            std::map<std::size_t, int> pinss;
	};
}
