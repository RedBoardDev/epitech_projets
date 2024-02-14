#pragma once

#include "components/IComponent.hpp"
#include "components/AComponent.hpp"
#include <memory>
#include <map>

class Circuit
{
    private:
        size_t _tick;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _input;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _output;
        std::map<std::string, std::unique_ptr<nts::IComponent>> _other;

    public:
        Circuit();
        nts::IComponent &getComponent(const std::string name);
        void addComponent(std::string name, std::string type);
        void setLink(std::string name, std::size_t pin, std::string otherName, std::size_t otherPin);
        void display(void);
        void changeInputValue(std::string name, std::string value);
        void simulate(void);
        void loop(void);
        std::size_t size(void);

    class NotFoundException: public std::exception {
        public:
            NotFoundException(std::string w);
            const char *what() const noexcept override;

        private:
            std::string _w;
    };
};
