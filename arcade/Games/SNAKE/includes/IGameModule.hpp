#pragma once

#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include "IDisplayModule.hpp"

namespace Arcade {
    namespace Game {
        class IGameModule {
            public:
                /**
                 * @brief Get the resolution of the game
                 * 
                 * @return std::pair<int, int> 
                 */
                virtual std::pair<int, int> getResolution() const = 0;
                /**
                 * @brief start the game
                 * 
                 */
                virtual void start() = 0;
                /**
                 * @brief finish the game
                 * 
                 */
                virtual void end() = 0;
                /**
                 * @brief Get the score of the game
                 * 
                 * @return const size_t& 
                 */
                virtual const size_t &getScore() const = 0;
                /**
                 * @brief Set events get in IdisplayModule
                 * 
                 * @param e 
                 */
                virtual void setInputs(std::vector<Arcade::Graphics::IDisplayModule::Events> e) = 0;
                /**
                 * @brief Get the map of putPixel
                 * 
                 * @return const std::unordered_map<long, unsigned int>& 
                 */
                virtual const std::unordered_map<long, unsigned int> &getPixels() const = 0;
                /**
                 * @brief refresh the game
                 * 
                 */
                virtual void refresh() = 0;
                /**
                 * @brief reset the game
                 * 
                 */
                virtual void reset() = 0;
        };
    }
}
