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

        class NIBBLER: public Arcade::Game::IGameModule {
            public:
                enum Direction {
                    LEFT,
                    RIGHT,
                    TOP,
                    BOTTOM
                };

                NIBBLER();
                virtual ~NIBBLER();
                std::pair<int, int> getResolution() const;
                void start();
                void end();
                const size_t &getScore() const;
                void setInputs(std::vector<Arcade::Graphics::IDisplayModule::Events>);
                const std::unordered_map<long, unsigned int> &getPixels() const;
                void refresh();
                void reset();

            private:
                class NibblerPart {
                    public:
                        NibblerPart(std::pair<int, int> pos, bool head);
                        NibblerPart(const std::unique_ptr<NibblerPart> &obj);
                        ~NibblerPart();
                        void refresh(std::vector<std::pair<int, int>> path);
                        Direction getDir() const;
                        void setDir(Direction);
                        std::pair<int, int> getPos() const;
                        void setNextDir(Direction);
                        Direction getNextDir() const;
                        int getWait() const;
                        void checkIfNextStepIsValid();

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
                std::vector<std::unique_ptr<NibblerPart>> Nibbler;

                int timerStart;

                size_t timer;
                size_t timer_tot;
                size_t refreshTime = 100;

                size_t timerPause;
                size_t timerUnPause;

                size_t time;

                int level;

                std::vector<std::pair<int, int>> apple;
                std::vector<std::pair<int, int>> path;
                void drawRect(std::pair<int, int>, std::pair<int, int>, unsigned int color);
                void drawWall(void);
                void drawAllApple(std::vector<std::pair<int, int>> apple);
                void drawAllPath(std::vector<std::pair<int, int>> apple);
                void checkIfAppleIsEat(std::vector<std::pair<int, int>> apple);
                int checkIfPath(std::vector<std::pair<int, int>> path, Direction, std::pair<int, int>);
                void nextLevel(std::vector<std::pair<int, int>> apple);
                int checkIfCurPosIsPath(std::pair<int, int>, std::vector<std::pair<int, int>> path);

                Direction nxtDir;
        };

    }

}
