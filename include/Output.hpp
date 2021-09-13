/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** Output.hpp
*/

#pragma once

#include <string>
#include "IComponent.hpp"

namespace nts
{
	class Output : public IComponent {
		public:
			Output(std::string const &value);
			~Output() override;

			Tristate compute(std::size_t pin = 1) override;
			void setLink(std::size_t pin, IComponent &other, size_t otherPin) override;
			void dump() const override;
			nts::Tristate getPinVal(std::size_t pin);
			void simulate(std::size_t tick);
            void setValue(std::string const &value);

		private:
			IComponent *linkedComponent;
			size_t linkedPin;
            std::map<std::size_t, nts::IComponent &> pins;
            std::map<std::size_t, int> pinss;
	};
}
