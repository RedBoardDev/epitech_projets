#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <map>
#include <vector>
#include "../includes/scoreboard.hpp"

#include <string>
#include <utility>

std::pair<std::string, std::string> splitString(const std::string &str) {
    std::string::size_type pos = str.find(':');
    if (pos == 0) return std::make_pair("", "");
    return std::make_pair(str.substr(0, pos), str.substr(pos + 1));
}

void Arcade::Scoreboard::setScoreForPlayer(std::string username, std::string gameName, int score) {
    std::string strTemp;
    bool userFound = false;
    struct stat st = {0};
    std::pair<std::string, std::string> playerScore;
    std::string str = username + ":" + std::to_string(score);
    gameName = gameName.substr(0, gameName.length() - 3);
    if (stat("scoreboard/", &st) == -1) mkdir("scoreboard/", 0777);
    std::ifstream filein("scoreboard/" + gameName + ".sb");
    std::ofstream fileout("scoreboard/temp.sb");

    while (std::getline(filein, strTemp)) {
        playerScore = splitString(strTemp);
        if (playerScore.first == username) {
            strTemp = (std::stoi(playerScore.second) < score ? str : strTemp);
            userFound = true;
        }
        fileout << strTemp << "\n";
    }
    if (!userFound) fileout << str << "\n";
    filein.close();
    fileout.close();

    remove(("scoreboard/" + gameName + ".sb").c_str());
    rename("scoreboard/temp.sb", ("scoreboard/" + gameName + ".sb").c_str());
}

std::string Arcade::Scoreboard::getScoreForPlayer(const std::string &username, const std::string &gameName) const {
    std::string strTemp;
    std::ifstream filein("scoreboard/" + gameName + ".sb");

    while (std::getline(filein, strTemp)) {
        if (strTemp.substr(0, strTemp.find(':')) == username)
            return strTemp.substr(strTemp.find(':') + 1, strTemp.size());
    }
    filein.close();
    return "";
}

std::vector<std::pair<std::string, int>> Arcade::Scoreboard::getScoreForGame(const std::string &gameName) {
    int score;
    std::string strTemp;
    std::ifstream filein("scoreboard/" + gameName + ".sb");
    std::vector<std::pair<std::string, int>> scores;

    while (std::getline(filein, strTemp)) {
        score = std::stoi(strTemp.substr(strTemp.find(':') + 1, strTemp.size()));
        scores.push_back(std::make_pair(strTemp.substr(0, strTemp.find(':')), score));
    }
    if (scores.size() < 2) return scores;
    for (size_t i = 0; i < scores.size() - 1; ++i) {
        for (size_t j = i + 1; j < scores.size(); ++j) {
            if (scores[i].second < scores[j].second) {
                std::swap(scores[i], scores[j]);
            }
        }
    }
    return scores;
}
