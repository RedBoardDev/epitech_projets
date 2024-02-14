#include <string>
#include <map>

#pragma once

namespace Arcade
{
    class Scoreboard
    {
        private:
            std::map<std::string, size_t> _playerScore;
        public:
            size_t _score;
            std::string _username;
            void setScoreForPlayer(std::string username, std::string gameName, int score);
            std::string getScoreForPlayer(const std::string &username, const std::string &gameName) const;
            std::vector<std::pair<std::string, int>> getScoreForGame(const std::string &gameName);
    };
}
