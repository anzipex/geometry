#pragma once

#include <vector>
#include <map>

class Parser {
public:
    Parser(int argc, char** argv);
    ~Parser() = default;

    std::map<std::string, int> getFigures() const;

private:
    static void printUsage();
    void parseArgs();
    static bool isPrimitive(const std::string &name);
    static bool isDigit(std::string next);
    void checkNextFigureNotLast(std::vector<std::string>::iterator next);

    std::vector<std::string> args_;
    std::vector<std::string>::iterator curPrimitive_;
    std::map<std::string, int> primitives_;
};
