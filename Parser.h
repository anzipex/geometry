/** 
 * @file Parser.h
 * @brief Описание класса Parser
 * @author a.akulin
 * @date October 31, 2019
 */

#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <map>

class Parser {
public:
    Parser(int argc, char** argv);
    ~Parser() = default;
    std::map<std::string, int> getFigures();
    std::vector<std::string> getFigureNames();

private:
    void printUsage();
    void parseArgs();
    static bool isFigure(std::string figure);
    static bool isDigit(std::string next);
    void checkNextFigureNotEnd(std::vector<std::string>::iterator next);
    void formFigureNames();

    std::vector<std::string> _figureNames;
    std::vector<std::string> _args;
    std::vector<std::string>::iterator _curFigure;
    std::map<std::string, int> _figures;
};

#endif /* PARSER_H */