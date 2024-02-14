#include "Parsing.hpp"

static void testEndLine(FileParser &fp) {
    std::string buff;
    try {
        buff = fp.extractStr();
    } catch(const std::exception& e) {
        return;
    }
    throw FileParser::Error(fp.currentLine(), fp.fileName(), "Unknown expression: " + buff);
}

static void addComponent(Circuit &ci, FileParser &fp, const std::string &type) {
    std::string name = fp.extractStr();
    try {
        ci.addComponent(name, type);
    } catch (const std::exception &e) {
        throw FileParser::Error(fp.currentLine(), fp.fileName(), e.what());
    }
}

static void addLink(Circuit &ci, FileParser &fp, std::string first) {
    std::string second = fp.extractStr();

    std::size_t pin1 = std::stoi(first.substr(first.find(':') + 1));
    std::size_t pin2 = std::stoi(second.substr(second.find(':') + 1));

    first = first.substr(0, first.find(':'));
    second = second.substr(0, second.find(':'));

    if (first == "" || pin1 <= 0)
        throw FileParser::Error(fp.currentLine(), fp.fileName(), "Unable to parse first link");
    if (second == "" || pin2 <= 0)
        throw FileParser::Error(fp.currentLine(), fp.fileName(), "Unable to parse second link");
    try {
        ci.setLink(first, pin1, second, pin2);
    } catch (const std::exception &e) {
        throw FileParser::Error(fp.currentLine(), fp.fileName(), e.what());
    }
}

void nts::parseFile(std::string fileName, Circuit &ci) {
    FileParser fp(fileName);

    bool chipsetsPassed = false;
    bool linksPassed = false;

    while (true) {
        try {
            fp.next();
        } catch(const std::exception &e) {
            break;
        }
        std::string buff;
        try {
            buff = fp.extractStr();
        } catch(const FileParser::Warning &e) {
            continue;
        }
        if (buff == ".chipsets:")
            chipsetsPassed = true;
        else if (buff == ".links:") {
            if (!chipsetsPassed)
                throw FileParser::Error(fp.currentLine(), fp.fileName(), "Links declared before chipset");
            linksPassed = true;
        } else if (chipsetsPassed && !linksPassed)
            addComponent(ci, fp, buff);
        else if (chipsetsPassed && linksPassed)
            addLink(ci, fp, buff);
        else
            throw FileParser::Error(fp.currentLine(), fp.fileName(), "Unknown expression: " + buff);
        testEndLine(fp);
    }
    if (!linksPassed)
        throw FileParser::Error(fp.currentLine(), fp.fileName(), "Links not set");
}
