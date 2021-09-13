/*
** EPITECH PROJECT, 2021
** 4001 Component
** File description:
** NanoTekSpice
*/

#pragma once

#include "IComponent.hpp"
#include "Nor.hpp"

namespace nts
{
	class C_4001 : public IComponent {
        public:
            C_4001(std::string const &value);
            ~C_4001() override = default;

            Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void simulate(std::size_t tick) override;
            nts::Tristate getPinVal(std::size_t pin) override;
            void dump() const override;

        private:
            std::unordered_map<std::size_t, nts::IComponent *> pins;
            std::map<std::size_t, int> pinss;
	};
}



