#pragma once
#include "../includes/IGameModule.hpp"
#include <memory>
#include <chrono>

#define NOW std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()


namespace Arcade {
    namespace Game {
        enum State {
            on,
            off,
            paused
        };

        class SNAKE: public Arcade::Game::IGameModule {
            public:
                enum Direction {
                    LEFT,
                    RIGHT,
                    TOP,
                    BOTTOM
                };

                SNAKE();
                virtual ~SNAKE();
                std::pair<int, int> getResolution() const;
                void start();
                void end();
                const size_t &getScore() const;
                void setInputs(std::vector<Arcade::Graphics::IDisplayModule::Events>);
                const std::unordered_map<long, unsigned int> &getPixels() const;
                void refresh();
                void reset();

            private:
                class SnakePart {
                    public:
                        SnakePart(std::pair<int, int> pos, bool head);
                        SnakePart(const std::unique_ptr<SnakePart> &obj);
                        ~SnakePart();
                        void refresh();
                        Direction getDir() const;
                        void setDir(Direction);
                        std::pair<int, int> getPos() const;
                        void setNextDir(Direction);
                        Direction getNextDir() const;
                        int getWait() const;

                    private:
                        std::pair<int, int>pos;
                        Direction dir;
                        Direction next;
                        bool head;
                        int wait;
                };

                std::pair<int, int> WinSize = std::pair<int, int>(1920, 1080);
                State GameState;
                size_t Score;
                std::vector<Arcade::Graphics::IDisplayModule::Events> Events;
                std::unordered_map<long, unsigned int> fbr;
                std::vector<std::unique_ptr<SnakePart>> Snake;

                int timerStart;

                size_t timer;
                size_t timer_tot;
                size_t refreshTime = 100;

                size_t timerPause;
                size_t timerUnPause;


                std::pair<int, int>apple;
                void drawRect(std::pair<int, int>, std::pair<int, int>, unsigned int color);
        };

    }

}
