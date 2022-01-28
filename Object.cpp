#include <cmath>
#include <utility>
#include <GL/glut.h>
#include "Object.h"

Object::Object(std::map<std::string, int> figures) :
primitives_(std::move(figures)),
primitiveNames_(),
fixedSize_(50),
widthToCenter_(0),
widthShift_(150),
heightSquare_(0),
heightRect_(0),
heightTriangle_(0),
heightCircle_(0) {
    formPrimitiveNames();
    setHeight();
}

void Object::formPrimitiveNames() {
    for (auto& p : primitives_) {
        primitiveNames_.push_back(p.first);
    }
}

void Object::moveWidthToCenter(int count) {
    if (count >= 2) {
        widthToCenter_ = (widthShift_ / 3 + ((widthShift_ / 3) / 2)) * (count - 1);
    } else {
        widthToCenter_ = 0;
    }
}

void Object::setHeight() {
    if (primitiveNames_.size() == 2) {
        if (primitiveNames_.front() == "square") {
            heightSquare_ = 50;
        } else if (primitiveNames_.front() == "rect") {
            heightRect_ = 50;
        } else if (primitiveNames_.front() == "triangle") {
            heightTriangle_ = 50;
        } else if (primitiveNames_.front() == "circle") {
            heightCircle_ = 50;
        }

        if (primitiveNames_.back() == "square") {
            heightSquare_ = -50;
        } else if (primitiveNames_.back() == "rect") {
            heightRect_ = -50;
        } else if (primitiveNames_.back() == "triangle") {
            heightTriangle_ = -50;
        } else if (primitiveNames_.back() == "circle") {
            heightCircle_ = -50;
        }
    }

    if (primitiveNames_.size() == 3) {
        if (primitiveNames_.front() == "square") {
            heightSquare_ = 100;
        } else if (primitiveNames_.front() == "rect") {
            heightRect_ = 100;
        } else if (primitiveNames_.front() == "triangle") {
            heightTriangle_ = 100;
        } else if (primitiveNames_.front() == "circle") {
            heightCircle_ = 100;
        }

        if (primitiveNames_.back() == "square") {
            heightSquare_ = -100;
        } else if (primitiveNames_.back() == "rect") {
            heightRect_ = -100;
        } else if (primitiveNames_.back() == "triangle") {
            heightTriangle_ = -100;
        } else if (primitiveNames_.back() == "circle") {
            heightCircle_ = -100;
        }
    }

    if (primitiveNames_.size() == 4) {
        if (primitiveNames_.front() == "square") {
            heightSquare_ = 200;
        } else if (primitiveNames_.front() == "rect") {
            heightRect_ = 200;
        } else if (primitiveNames_.front() == "triangle") {
            heightTriangle_ = 200;
        } else if (primitiveNames_.front() == "circle") {
            heightCircle_ = 200;
        }

        if (primitiveNames_.at(1) == "square") {
            heightSquare_ = 60;
        } else if (primitiveNames_.at(1) == "rect") {
            heightRect_ = 60;
        } else if (primitiveNames_.at(1) == "triangle") {
            heightTriangle_ = 60;
        } else if (primitiveNames_.at(1) == "circle") {
            heightCircle_ = 60;
        }

        if (primitiveNames_.at(2) == "square") {
            heightSquare_ = -60;
        } else if (primitiveNames_.at(2) == "rect") {
            heightRect_ = -60;
        } else if (primitiveNames_.at(2) == "triangle") {
            heightTriangle_ = -60;
        } else if (primitiveNames_.at(2) == "circle") {
            heightCircle_ = -60;
        }

        if (primitiveNames_.back() == "square") {
            heightSquare_ = -210;
        } else if (primitiveNames_.back() == "rect") {
            heightRect_ = -210;
        } else if (primitiveNames_.back() == "triangle") {
            heightTriangle_ = -210;
        } else if (primitiveNames_.back() == "circle") {
            heightCircle_ = -210;
        }
    }
}

void Object::draw() {
    for (const auto& f : primitives_) {
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
    for (size_t i = 0; i < count; ++i) {
        int number = i + 1;
        drawSquare(number);
    }
    glEnd();
}

void Object::drawSquare(int number) const {
    const int degree = number - 1;
    glVertex2f(fixedSize_ + widthShift_ * degree - widthToCenter_, fixedSize_ + heightSquare_);
    glVertex2f(-fixedSize_ + widthShift_ * degree - widthToCenter_, fixedSize_ + heightSquare_);
    glVertex2f(-fixedSize_ + widthShift_ * degree - widthToCenter_, -fixedSize_ + heightSquare_);
    glVertex2f(fixedSize_ + widthShift_ * degree - widthToCenter_, -fixedSize_ + heightSquare_);
}

void Object::rect(int count) {
    moveWidthToCenter(count);
    glBegin(GL_QUADS);
    for (size_t i = 0; i < count; ++i) {
        int number = i + 1;
        drawRect(number);
    }
    glEnd();
}

void Object::drawRect(int number) const {
    const int width = fixedSize_ + (fixedSize_ / 3.33);
    const int height = fixedSize_ / 1.5;
    const int degree = number - 1;
    glVertex2f(width + widthShift_ * degree - widthToCenter_, height + heightRect_);
    glVertex2f(-width + widthShift_ * degree - widthToCenter_, height + heightRect_);
    glVertex2f(-width + widthShift_ * degree - widthToCenter_, -height + heightRect_);
    glVertex2f(width + widthShift_ * degree - widthToCenter_, -height + heightRect_);
}

void Object::triangle(int count) {
    moveWidthToCenter(count);
    glBegin(GL_TRIANGLES);
    for (size_t i = 0; i < count; ++i) {
        int number = i + 1;
        drawTriangle(number);
    }
    glEnd();
}

void Object::drawTriangle(int number) const {
    const int degree = number - 1;
    glVertex3f(-fixedSize_ + widthShift_ * degree - widthToCenter_,-fixedSize_ + heightTriangle_, 0);
    glVertex3f(0 + widthShift_ * degree - widthToCenter_, fixedSize_ + heightTriangle_, 0);
    glVertex3f(fixedSize_ + widthShift_ * degree - widthToCenter_, -fixedSize_ + heightTriangle_, 0);
}

void Object::circle(int count) {
    moveWidthToCenter(count);
    for (size_t i = 0; i < count; ++i) {
        int number = i + 1;
        drawCircle(number);
    }
}

void Object::drawCircle(int number) const {
    const int degree = number - 1;
    const int centerX = 0 + widthShift_ * degree - widthToCenter_;
    const int centerY = 0 + heightCircle_;
    const int triangleAmount = 100;
    const float twicePi = 2.0f * M_PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY);
    for (size_t i = 0; i <= triangleAmount; ++i) {
        glVertex2f(centerX + ((fixedSize_ + 1) * std::cos(i * twicePi / triangleAmount)),
            centerY + ((fixedSize_ - 1) * std::sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}
