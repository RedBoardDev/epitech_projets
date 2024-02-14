#pragma once

#include <iostream>
#include <vector>
#include <fstream>

class Board {
public:
    enum Cell {
        EMPTY,
        AI,
        PLAYER
    };

    Board() = default;
    ~Board() = default;

    void init();
    void init(size_t size);
    void init(size_t width, size_t height);

    size_t sizeHeight() const { return _sizeHeight; }
    size_t sizeWidth() const { return _sizeWidth; }
    void log(std::ofstream &file) const;

    Cell &operator()(size_t x, size_t y);
    Cell operator()(size_t x, size_t y) const;

private:
    std::vector<std::vector<Cell>> _board;

    size_t _sizeHeight = 0;
    size_t _sizeWidth = 0;
};
