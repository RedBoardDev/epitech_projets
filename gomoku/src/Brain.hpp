#pragma once

#include <fstream>
#include <filesystem>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <array>
#include <string>
#include <optional>
#include "Board.hpp"

using coords = std::pair<size_t, size_t>;

class Brain {
public:
    enum GameType {
        HUMAN_OPPONENT,
        AI_OPPONENT,
        TOURNAMENT,
        NETWORK_TOURNAMENT
    };
    enum Rule {
        FIVE_IN_A_ROW = 1 << 0,
        CONTINUOUS_GAME = 1 << 1,
        RENJU = 1 << 2,
        CARO = 1 << 3,
    };

    Brain();
    ~Brain();

    void makeNextMove();
    void initEmptyBoard();
    void initEmptyBoard(size_t size);
    void initEmptyBoard(size_t width, size_t height);
    void playerTurn(size_t x, size_t y);
    void updateCell(size_t x, size_t y, Board::Cell field);

    void setTimeoutTurn(int timeoutTurn) { _timeoutTurn = timeoutTurn; }
    void setTimeoutMatch(int timeoutMatch) { _timeoutMatch = timeoutMatch; }
    void setMaxMemory(int maxMemory) { _maxMemory = maxMemory; }
    void setTimeLeft(int timeLeft) { _timeLeft = timeLeft; }
    void setGameType(GameType gameType) { _gameType = gameType; }
    void setRule(Rule rule) { _rule |= rule; }
    void setRule(int rule) { _rule = rule; }
    void setMousePos(size_t x, size_t y) { _mousePos = {x, y}; }
    void setFolder(const std::string &folder);

private:
    void play(const coords &move);
    std::vector<coords> getAllAdjacentCells() const;

    int checkPattern(const coords &move, int dx, int dy, std::pair<std::string, int> pattern) const;
    int checkPatterns(const coords &move) const;

    Board _board;
    const std::unordered_map<std::string, int> _patterns;

    int _timeoutTurn = 0;
    int _timeoutMatch = 0;
    int _maxMemory = 0;
    int _timeLeft = 0;
    GameType _gameType = HUMAN_OPPONENT;
    int _rule = 0;
    std::pair<size_t, size_t> _mousePos = {0, 0};
    std::string _folder;

    std::ofstream _logFile;
};
