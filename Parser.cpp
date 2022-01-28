#include <iostream>
#include "Parser.h"

Parser::Parser(int argc, char** argv) :
args_(),
curPrimitive_(),
primitives_() {
    std::vector<std::string> args;
    for (int i = 1; i < argc; ++i) {
        args.emplace_back(argv[i]);
    }
    args_ = args;
    parseArgs();
}

void Parser::printUsage() {
    std::cout << "Usage: ./geometry square n rect n triangle n circle n" << std::endl;
}

void Parser::parseArgs() {
    for (curPrimitive_ = std::begin(args_); curPrimitive_ != std::end(args_); ++curPrimitive_) {
        if (isPrimitive(*curPrimitive_)) {
            checkNextFigureNotLast(std::next(curPrimitive_));
        } else {
            std::cerr << "'" << (*curPrimitive_) << "'" << " is invalid figure" << std::endl;
            printUsage();
        }
    }
}

bool Parser::isPrimitive(const std::string &name) {
    return (name == "square" || name == "rect" || name == "triangle" || name == "circle");
}

bool Parser::isDigit(std::string next) {
    for (char &c : next) {
        if (!isdigit(c) || isalpha(c)) {
            return false;
        };
    }
    return true;
}

void Parser::checkNextFigureNotLast(std::vector<std::string>::iterator next) {
    if (next != std::end(args_) && !isPrimitive(*next)) {
        if (isDigit(*next)) {
            primitives_.insert({*curPrimitive_, std::stoi(*next)});
        }
        *(++curPrimitive_);
    }
}

std::map<std::string, int> Parser::getFigures() const {
    return primitives_;
}
