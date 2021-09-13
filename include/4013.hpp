/*
** EPITECH PROJECT, 2021
** 4013 Component
** File description:
** NanoTekSpice
*/

#pragma once

#include "IComponent.hpp"

namespace nts
{
	class C_4013 : public IComponent {
        public:
            C_4013(std::string const &value);
            ~C_4013() = default;

            Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            nts::Tristate getPinVal(std::size_t pin) override;
            void dump() const override;

        private:
            std::unordered_map<std::size_t, nts::IComponent *> pins;
            std::map<std::size_t, int> pinss;
	};
}