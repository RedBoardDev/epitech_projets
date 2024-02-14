#include "Brain.hpp"

#define DEBUG std::cout << "DEBUG "
using Cell = Board::Cell;

//** Coordinate x corresponds to the column number, y corresponds to the row number **//
//** In other words, x is the horizontal axis (width), y is the vertical axis (height) **//

Brain::Brain():
    _patterns({
        // attacks
        {"X1111",  3000000},
        {"1X111",  500000},
        {"11X11",  3000000 / 2}, // symmetric
        {"X1110",  30000},
        {"X1112",  3000},
        {"X1101",  1200},
        {"X1011",  1200},
        {"X110",   400},
        {"X112",   50},
        {"X10",    30},
        {"X12",    20},
        {"X22210", 30000},
        {"X2201",  3000},
        {"X2011",  3000},

        // blocks
        {"X22220", 500000},
        {"2X222",  300000},
        {"X22221", 250000},
        {"22X22",  250000 / 2}, // symmetric
        {"02X220", 160000},
        {"02X221", 1500},
        {"022X21", 1500},
        {"X2220",  160000},
        {"X2200",  1200},
        {"X2221",  1500},
        {"2X02",   1500},
        {"X220",   300},
        {"X221",   40},
        {"X222",   40}
    })
{}

Brain::~Brain()
{
    if (_logFile.is_open())
        _logFile.close();
}

void Brain::makeNextMove()
{
    std::vector<coords> cells = getAllAdjacentCells();
    int bestScore = -1;
    coords bestMove = {-1, -1};

    if (cells.empty()) {
        play({_board.sizeWidth() / 2, _board.sizeHeight() / 2});
        return;
    }

    for (const auto &move : cells) {
        int score = checkPatterns(move);
        if (score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
    }
    play(bestMove);
}

void Brain::initEmptyBoard()
{
    _board.init();
}

void Brain::initEmptyBoard(size_t size)
{
    _board.init(size);
}

void Brain::initEmptyBoard(size_t width, size_t height)
{
    _board.init(width, height);
}

void Brain::playerTurn(size_t x, size_t y)
{
    _board(x, y) = Board::Cell::PLAYER;
}

void Brain::updateCell(size_t x, size_t y, Board::Cell field)
{
    _board(x, y) = field;
}

void Brain::setFolder(const std::string &folder)
{
    _folder = folder;
    if (_logFile.is_open())
        _logFile.close();
    _logFile.open(_folder + "/latest.log", std::ios::app);
}

void Brain::play(const coords &move)
{
    _board(move.first, move.second) = Board::Cell::AI;
    std::cout << move.first << "," << move.second << std::endl;
}

std::vector<coords> Brain::getAllAdjacentCells() const
{
    std::vector<coords> cells;

    for (size_t y = 0; y < _board.sizeHeight(); y++) {
        for (size_t x = 0; x < _board.sizeWidth(); x++) {
            if (_board(x, y) != Cell::EMPTY)
                continue;
            bool found = false;
            for (char i = -1; i <= 1 && !found; ++i) {
                for (char j = -1; j <= 1 && !found; ++j) {
                    try {
                        if (_board(x + i, y + j) != Cell::EMPTY && (i != 0 || j != 0)) {
                            cells.push_back({x, y});
                            found = true;
                        }
                    } catch (const std::exception &e) {(void)e;}
                }
            }
        }
    }
    return cells;
}

int Brain::checkPattern(const coords &move, int dx, int dy, std::pair<std::string, int> pattern) const
{
    size_t pos = pattern.first.find('X');
    if (pos == std::string::npos)
        return 0;
    pattern.first[pos] = '0';
    std::string line;
    size_t new_x = move.first - dx * pos;
    size_t new_y = move.second - dy * pos;
    for (; new_x >= 0 && new_x < _board.sizeWidth() && new_y >= 0 && new_y < _board.sizeHeight(); new_x += dx, new_y += dy)
        line += std::to_string(_board(new_x, new_y));
    if (line.find(pattern.first) == 0)
        return pattern.second;
    return 0;
}

int Brain::checkPatterns(const coords &move) const
{
    int score = 0;
    for (const auto &pattern : _patterns) {
        score += checkPattern(move, -1, -1, pattern);
        score += checkPattern(move, -1, 0, pattern);
        score += checkPattern(move, -1, 1, pattern);
        score += checkPattern(move, 1, -1, pattern);
        score += checkPattern(move, 1, 0, pattern);
        score += checkPattern(move, 1, 1, pattern);
        score += checkPattern(move, 0, -1, pattern);
        score += checkPattern(move, 0, 1, pattern);
    }
    return score;
}