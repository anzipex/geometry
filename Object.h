#pragma once

#include <vector>
#include <map>

class Object {
public:
    Object(std::map<std::string, int> figures);
    ~Object() = default;
    void draw();

private:
    void formFigureNames();
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

    std::map<std::string, int> _figures;
    std::vector<std::string> _figureNames;

    const int _fixedSize;
    int _widthToCenter;
    int _widthShift;

    int _heightSquare;
    int _heightRect;
    int _heightTriangle;
    int _heightCircle;
};
