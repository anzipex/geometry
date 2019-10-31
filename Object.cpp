/** 
 * @file Object.cpp
 * @brief Реализация класса Object
 * @author a.akulin
 * @date October 7, 2019
 */

#include <iostream>
#include <string> 
#include <math.h>
#include <GL/glut.h>
#include "Object.h"

Object::Object(std::vector<std::string> args) :
_width(50),
_height(50),
_widthToCenter(0),
_widthShift(150),
_heightSquare(0),
_heightRect(0),
_heightTriangle(0),
_heightCircle(0),
_figureNames(),
_args(args),
_curFigure(),
_figures() {
    parseArgs();
    getFigureNames();
    setHeight();
}

void Object::printUsage() {
    std::cout << "Usage: ./geometry square n rect n triangle n circle n" << std::endl;
}

void Object::parseArgs() {
    for (_curFigure = std::begin(_args); _curFigure != std::end(_args); ++_curFigure) {
        if (isFigure(*_curFigure)) {
            checkNextFigureNotEnd(std::next(_curFigure));
        } else {
            std::cerr << "'" << (*_curFigure) << "'" << " is invalid figure" << std::endl;
            printUsage();
        }
    }
}

bool Object::isFigure(std::string figure) {
    return (figure == "square" || figure == "rect" || figure == "triangle" || figure == "circle");
}

bool Object::isDigit(std::string next) {
    for (char& c : next) {
        if (!isdigit(c) || isalpha(c)) {
            return false;
        };
    }
    return true;
}

void Object::checkNextFigureNotEnd(std::vector<std::string>::iterator next) {
    if (next != std::end(_args) && !isFigure(*next)) {
        if (isDigit(*next)) {
            _figures.insert({*_curFigure, std::stoi(*next)});
        }
        *(++_curFigure);
    }
}

void Object::getFigureNames() {
    std::string prev;
    for (int i = 0; i < _args.size(); ++i) {
        if (isFigure(_args[i])) {
            if (_args[i] != prev) {
                _figureNames.push_back(_args[i]);
            }
            prev = _args[i];
        }
    }
}

void Object::moveWidthToCenter(int count) {
    if (count >= 2) {
        _widthToCenter = (_widthShift / 3 + ((_widthShift / 3) / 2)) * (count - 1);
    } else {
        _widthToCenter = 0;
    }
}

void Object::setHeight() {
    if (_figureNames.size() == 2) {
        if (_figureNames.front() == "square") {
            _heightSquare = 50;
        } else if (_figureNames.front() == "rect") {
            _heightRect = 50;
        } else if (_figureNames.front() == "triangle") {
            _heightTriangle = 50;
        } else if (_figureNames.front() == "circle") {
            _heightCircle = 50;
        }

        if (_figureNames.back() == "square") {
            _heightSquare = -50;
        } else if (_figureNames.back() == "rect") {
            _heightRect = -50;
        } else if (_figureNames.back() == "triangle") {
            _heightTriangle = -50;
        } else if (_figureNames.back() == "circle") {
            _heightCircle = -50;
        }
    }

    if (_figureNames.size() == 3) {
        if (_figureNames.front() == "square") {
            _heightSquare = 100;
        } else if (_figureNames.front() == "rect") {
            _heightRect = 100;
        } else if (_figureNames.front() == "triangle") {
            _heightTriangle = 100;
        } else if (_figureNames.front() == "circle") {
            _heightCircle = 100;
        }

        if (_figureNames.back() == "square") {
            _heightSquare = -100;
        } else if (_figureNames.back() == "rect") {
            _heightRect = -100;
        } else if (_figureNames.back() == "triangle") {
            _heightTriangle = -100;
        } else if (_figureNames.back() == "circle") {
            _heightCircle = -100;
        }
    }

    if (_figureNames.size() == 4) {
        if (_figureNames.front() == "square") {
            _heightSquare = 200;
        } else if (_figureNames.front() == "rect") {
            _heightRect = 200;
        } else if (_figureNames.front() == "triangle") {
            _heightTriangle = 200;
        } else if (_figureNames.front() == "circle") {
            _heightCircle = 200;
        }

        if (_figureNames.at(1) == "square") {
            _heightSquare = 60;
        } else if (_figureNames.at(1) == "rect") {
            _heightRect = 60;
        } else if (_figureNames.at(1) == "triangle") {
            _heightTriangle = 60;
        } else if (_figureNames.at(1) == "circle") {
            _heightCircle = 60;
        }

        if (_figureNames.at(2) == "square") {
            _heightSquare = -60;
        } else if (_figureNames.at(2) == "rect") {
            _heightRect = -60;
        } else if (_figureNames.at(2) == "triangle") {
            _heightTriangle = -60;
        } else if (_figureNames.at(2) == "circle") {
            _heightCircle = -60;
        }

        if (_figureNames.back() == "square") {
            _heightSquare = -210;
        } else if (_figureNames.back() == "rect") {
            _heightRect = -210;
        } else if (_figureNames.back() == "triangle") {
            _heightTriangle = -210;
        } else if (_figureNames.back() == "circle") {
            _heightCircle = -210;
        }
    }
}

void Object::draw() {
    for (const auto& f : _figures) {
        if (f.first == "square") {
            square(f.second);
        } else if (f.first == "rect") {
            rect(f.second);
        } else if (f.first == "triangle") {
            triangle(f.second);
        } else if (f.first == "circle") {
            circle(f.second);
        }
    }
}

void Object::square(int count) {
    moveWidthToCenter(count);
    glBegin(GL_QUADS);
    for (int i = 0; i < count; ++i) {
        int number = i + 1;
        drawSqaure(number);
    }
    glEnd();
}

void Object::drawSqaure(int number) {
    const int numberDegree = number - 1;
    glVertex2f(_width + _widthShift * numberDegree - _widthToCenter, _height + _heightSquare);
    glVertex2f(-_width + _widthShift * numberDegree - _widthToCenter, _height + _heightSquare);
    glVertex2f(-_width + _widthShift * numberDegree - _widthToCenter, -_height + _heightSquare);
    glVertex2f(_width + _widthShift * numberDegree - _widthToCenter, -_height + _heightSquare);
}

void Object::rect(int count) {
    moveWidthToCenter(count);
    glBegin(GL_QUADS);
    for (int i = 0; i < count; ++i) {
        int number = i + 1;
        drawRect(number);
    }
    glEnd();
}

void Object::drawRect(int number) {
    const int rectWidth = _width + (_width / 3.33);
    const int rectHeight = _height / 1.5;
    const int numberDegree = number - 1;
    glVertex2f(rectWidth + _widthShift * numberDegree - _widthToCenter, rectHeight + _heightRect);
    glVertex2f(-rectWidth + _widthShift * numberDegree - _widthToCenter, rectHeight + _heightRect);
    glVertex2f(-rectWidth + _widthShift * numberDegree - _widthToCenter, -rectHeight + _heightRect);
    glVertex2f(rectWidth + _widthShift * numberDegree - _widthToCenter, -rectHeight + _heightRect);
}

void Object::triangle(int count) {
    moveWidthToCenter(count);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < count; ++i) {
        int number = i + 1;
        drawTriangle(number);
    }
    glEnd();
}

void Object::drawTriangle(int number) {
    const int numberDegree = number - 1;
    glVertex3f(-_width + _widthShift * numberDegree - _widthToCenter, -_height + _heightTriangle, 0);
    glVertex3f(0 + _widthShift * numberDegree - _widthToCenter, _height + _heightTriangle, 0);
    glVertex3f(_width + _widthShift * numberDegree - _widthToCenter, -_height + _heightTriangle, 0);
}

void Object::circle(int count) {
    moveWidthToCenter(count);
    for (int i = 0; i < count; ++i) {
        int number = i + 1;
        drawCircle(number);
    }
}

void Object::drawCircle(int number) const {
    const int numberDegree = number - 1;
    const int centerX = 0 + _widthShift * numberDegree - _widthToCenter;
    const int centerY = 0 + _heightCircle;
    const int triangleAmount = 100;
    const float twicePi = 2.0f * M_PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY);
    for (int i = 0; i <= triangleAmount; i++) {
        glVertex2f(
                   centerX + ((_width + 1) * cos(i * twicePi / triangleAmount)),
                   centerY + ((_height - 1) * sin(i * twicePi / triangleAmount))
                   );
    }
    glEnd();
}