#include "Core.hpp"

Core::Core():
    _functions({
        {"START", &Core::start},
        {"TURN", &Core::turn},
        {"BEGIN", &Core::begin},
        {"BOARD", &Core::board},
        {"INFO", &Core::info},
        {"END", &Core::end},
        {"ABOUT", &Core::about},
        {"RECTSTART", &Core::rectstart},
        {"RESTART", &Core::restart}
    })
{}

void Core::loop()
{
    std::string cmd;
    while (std::getline(std::cin, cmd)) {
        try {
            route(cmd);
        } catch (const EndException &e) {
            std::cout << "DEBUG " << e.what() << std::endl;
            break;
        }
    }
}

void Core::route(const std::string &cmd)
{
    std::stringstream ss(cmd);
    std::string inst;
    ss >> inst;
    if (_functions.find(inst) != _functions.end())
        (this->*_functions.at(inst))(ss);
    else
        std::cout << "UNKNOWN " << "\"Unknown command " << inst <<  "\"" << std::endl;
}

void Core::start(std::stringstream &ss)
{
    size_t size = 0;
    ss >> size;
    if (size) {
        _brain.initEmptyBoard(size);
        std::cout << "OK" << std::endl;
    } else
        std::cout << "ERROR size must be > 0" << std::endl;
}

void Core::turn(std::stringstream &ss)
{
    size_t x, y = 0;
    ss >> x;
    ss.ignore(1);
    ss >> y;
    _brain.playerTurn(x, y);
    _brain.makeNextMove();
}

void Core::begin(std::stringstream &ss)
{
    _brain.makeNextMove();
}

void Core::board(std::stringstream &ss)
{
    std::string line;
    while (std::getline(std::cin, line)) {
        if (line == "DONE")
            break;
        std::stringstream ss(line);
        size_t x, y, field = 0;
        ss >> x;
        ss.ignore(1);
        ss >> y;
        ss.ignore(1);
        ss >> field;
        _brain.updateCell(x, y, static_cast<Board::Cell>(field));
    }
    _brain.makeNextMove();
}

void Core::info(std::stringstream &ss)
{
    std::string key;
    ss >> key;
    if (key == "timeout_turn") {
        int timeoutTurn;
        ss >> timeoutTurn;
        _brain.setTimeoutTurn(timeoutTurn);
    } else if (key == "timeout_match") {
        int timeoutMatch;
        ss >> timeoutMatch;
        _brain.setTimeoutMatch(timeoutMatch);
    } else if (key == "max_memory") {
        int maxMemory;
        ss >> maxMemory;
        _brain.setMaxMemory(maxMemory);
    } else if (key == "time_left") {
        int timeLeft;
        ss >> timeLeft;
        _brain.setTimeLeft(timeLeft);
    } else if (key == "game_type") {
        int gameType;
        ss >> gameType;
        _brain.setGameType(static_cast<Brain::GameType>(gameType));
    } else if (key == "rule") {
        int rule;
        ss >> rule;
        _brain.setRule(rule);
    } else if (key == "evaluate") {
        size_t x, y = 0;
        ss >> x;
        ss.ignore(1);
        ss >> y;
        _brain.setMousePos(x, y);
    } else if (key == "folder") {
        std::string folder;
        ss >> folder;
        _brain.setFolder(folder);
    }
}

void Core::end(std::stringstream &ss)
{
    throw EndException();
}

void Core::about(std::stringstream &ss)
{
    std::cout << "name=\"EpitechGomokuAi\", version=\"1.0\", author=\"Mazettt, Redboard, Loutchau\", country=\"France\"" << std::endl;
}

void Core::rectstart(std::stringstream &ss)
{
    size_t width, height = 0;
    ss >> width;
    ss.ignore(1);
    ss >> height;
    _brain.initEmptyBoard(width, height);
    std::cout << "OK" << std::endl;
}

void Core::restart(std::stringstream &ss)
{
    _brain.initEmptyBoard();
    std::cout << "OK" << std::endl;
}
