#include "Board.hpp"

void Board::init()
{
    init(sizeWidth(), sizeHeight());
}

void Board::init(size_t size)
{
    init(size, size);
}

void Board::init(size_t width, size_t height)
{
    _board = std::vector<std::vector<Cell>>(height, std::vector<Cell>(width, Cell::EMPTY));
    _sizeHeight = height;
    _sizeWidth = width;
}

void Board::log(std::ofstream &file) const
{
    for (size_t i = 0; i < sizeHeight(); i++) {
        for (size_t j = 0; j < sizeWidth(); j++) {
            file << _board[i][j] << " ";
        }
        file << '\n';
    }
    file << std::endl;
}

Board::Cell &Board::operator()(size_t x, size_t y)
{
    if (x >= sizeWidth() || y >= sizeHeight())
        throw std::out_of_range("Board::operator(): out of range");
    return _board[y][x];
}

Board::Cell Board::operator()(size_t x, size_t y) const
{
    if (x >= sizeWidth() || y >= sizeHeight())
        throw std::out_of_range("Board::operator(): out of range");
    return _board[y][x];
}
