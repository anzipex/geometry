/** 
 * @file Object.h
 * @brief Описание класса Object
 * @author a.akulin
 * @date October 7, 2019
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <map>

class Object {
public:
    Object(std::vector<std::string> args);
    ~Object() = default;
    void draw();

private:
    static void printUsage();
    void parseArgs();
    static bool isFigure(std::string figure);
    static bool isDigit(std::string next);
    void checkNextFigureNotEnd(std::vector<std::string>::iterator next);
    void getFigureNames();
    void moveWidthToCenter(int count);
    void setHeight();
    void square(int count);
    void drawSqaure(int number);
    void rect(int count);
    void drawRect(int number);
    void triangle(int count);
    void drawTriangle(int number);
    void circle(int count);
    void drawCircle(int number) const;

    int _width;
    int _height;
    int _widthToCenter;
    int _widthShift;
    
    int _heightSquare;
    int _heightRect;
    int _heightTriangle;
    int _heightCircle;

    std::vector<std::string> _figureNames;
    std::vector<std::string> _args;
    std::vector<std::string>::iterator _curFigure;
    std::map<std::string, int> _figures;
};

#endif /* OBJECT_H */