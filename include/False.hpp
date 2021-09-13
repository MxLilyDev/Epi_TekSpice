/*
** EPITECH PROJECT, 2021
** NanoTekSpice
** File description:
** False.hpp
*/

#pragma once

#include <string>
#include "IComponent.hpp"

namespace nts
{
    class False : public IComponent {
        public:
            False();
            ~False() override;

            Tristate compute(std::size_t pin = 1) override;
            void setLink(std::size_t pin, IComponent &other, size_t otherPin) override;
            void simulate(std::size_t tick);
			nts::Tristate getPinVal(std::size_t pin);
            void dump() const override;

        private:
            IComponent *linkedComponent = nullptr;
            size_t linkedPin = 1;
            std::map<std::size_t, nts::IComponent &> pins;
            std::map<std::size_t, int> pinss;
    };
}
