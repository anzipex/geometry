/** 
 * @file Object.h
 * @brief Class description Object
 * @author a.akulin
 * @date October 7, 2019
 */

#ifndef OBJECT_H
#define OBJECT_H

#include <vector>
#include <map>

class Object {
public:
    Object(std::map<std::string, int> getFigures, std::vector<std::string> getFigureNames);
    ~Object() = default;
    void draw();

private:
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
    
    int _width;
    int _height;
    int _widthToCenter;
    int _widthShift;
    
    int _heightSquare;
    int _heightRect;
    int _heightTriangle;
    int _heightCircle;
};

#endif /* OBJECT_H */