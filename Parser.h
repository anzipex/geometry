#pragma once

#include <vector>
#include <map>

class Parser {
public:
    Parser(int argc, char** argv);
    ~Parser() = default;
    std::map<std::string, int> getFigures() const;
    std::vector<std::string> getFigureNames() const;

private:
    static void printUsage();
    void parseArgs();
    static bool isFigure(std::string figure);
    static bool isDigit(std::string next);
    void checkNextFigureNotEnd(std::vector<std::string>::iterator next);

    std::vector<std::string> _args;
    std::vector<std::string>::iterator _curFigure;
    std::map<std::string, int> _figures;
};
