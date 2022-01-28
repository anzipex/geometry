#pragma once

#include <vector>
#include <map>

class Object {
public:
    explicit Object(std::map<std::string, int> figures);
    ~Object() = default;

    void draw();

private:
    void formPrimitiveNames();
    void moveWidthToCenter(int count);
    void setHeight();

    void square(int count);
    void rect(int count);
    void triangle(int count);
    void circle(int count);

    void drawSquare(int number) const;
    void drawRect(int number) const;
    void drawTriangle(int number) const;
    void drawCircle(int number) const;

    std::map<std::string, int> primitives_;
    std::vector<std::string> primitiveNames_;

    const int fixedSize_;
    int widthToCenter_;
    int widthShift_;

    int heightSquare_;
    int heightRect_;
    int heightTriangle_;
    int heightCircle_;
};
