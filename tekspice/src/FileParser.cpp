#include "FileParser.hpp"

FileParser::FileParser(const std::string &fileName) {
    _stream.open(fileName);
    _fileName = fileName;
    _fileLine = 0;
}

FileParser::~FileParser() {}

void FileParser::next() {
    if (!_stream.good())
        throw Error(_fileLine, _fileName, "Input failed");
    if (!getline(_stream, _line))
        throw Error(_fileLine, _fileName, "End of input");
    ++_fileLine;
    _comment = false;
    if (_line == "")
        next();
    _ss.clear();
    _ss.str(_line);
}

std::string FileParser::extractStr() {
    if (_comment)
        throw Warning(_fileLine, _fileName, "End of line");

    std::string str = extract<std::string>();
    std::size_t f = str.find('#');

    if (f == 0) {
        _comment = true;
        throw Warning(_fileLine, _fileName, "End of line");
    } else if (f != std::string::npos) {
        _comment = true;
        return str.substr(0, f);
    }
    return str;
}

const std::string &FileParser::fileName() const {
    return _fileName;
}

const std::size_t &FileParser::currentLine() const {
    return _fileLine;
}

FileParser::Error::Error(std::size_t line, const std::string &filename, const std::string &msg) {
    _msg = filename + ":" + std::to_string(line) + ": ERROR " + msg;
}

const char *FileParser::Error::what() const noexcept {
    return _msg.c_str();
}

FileParser::Warning::Warning(std::size_t line, const std::string &filename, const std::string &msg) {
    _msg = filename + ":" + std::to_string(line) + ": ERROR " + msg;
}

const char *FileParser::Warning::what() const noexcept {
    return _msg.c_str();
}
