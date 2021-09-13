/*
** EPITECH PROJECT, 2021
** 4040 Component
** File description:
** NanoTekSpice
*/

#pragma once

#include "IComponent.hpp"

namespace nts
{
	class C_4040 : public IComponent {
        public:
            C_4040(std::string const &value);
            ~C_4040() = default;

            Tristate compute(std::size_t pin = 1) override;
            void simulate(std::size_t tick) override;
            nts::Tristate getPinVal(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() const override;

        private:
            std::unordered_map<std::size_t, nts::IComponent *> pins;
            std::map<std::size_t, int> pinss;
	};
}
