/** 
 * @file Parser.cpp
 * @brief Class implementation Parser
 * @author a.akulin
 * @date October 31, 2019
 */

#include <iostream>
#include "Parser.h"

Parser::Parser(int argc, char** argv) :
_args(),
_curFigure(),
_figures() {
    std::vector<std::string> args;
    for (int i = 1; i < argc; ++i) {
        args.push_back(argv[i]);
    }
    _args = args;
    parseArgs();
}

void Parser::printUsage() {
    std::cout << "Usage: ./geometry square n rect n triangle n circle n" << std::endl;
}

void Parser::parseArgs() {
    for (_curFigure = std::begin(_args); _curFigure != std::end(_args); ++_curFigure) {
        if (isFigure(*_curFigure)) {
            checkNextFigureNotEnd(std::next(_curFigure));
        } else {
            std::cerr << "'" << (*_curFigure) << "'" << " is invalid figure" << std::endl;
            printUsage();
        }
    }
}

bool Parser::isFigure(std::string figure) {
    return (figure == "square" || figure == "rect" || figure == "triangle" || figure == "circle");
}

bool Parser::isDigit(std::string next) {
    for (char& c : next) {
        if (!isdigit(c) || isalpha(c)) {
            return false;
        };
    }
    return true;
}

void Parser::checkNextFigureNotEnd(std::vector<std::string>::iterator next) {
    if (next != std::end(_args) && !isFigure(*next)) {
        if (isDigit(*next)) {
            _figures.insert({*_curFigure, std::stoi(*next)});
        }
        *(++_curFigure);
    }
}

std::map<std::string, int> Parser::getFigures() const {
    return _figures;
}