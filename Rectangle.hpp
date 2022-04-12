#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    Rectangle(double x, double y);
    Rectangle(Color c);
    Rectangle(const Rectangle & other) = default;

    Rectangle(Rectangle&& src) noexcept = default;
    Rectangle& operator=(Rectangle&& src) noexcept = default; // rule of five says that if we implement one of the default operations we should define all other default operations

    double getArea() const override;
    double getPerimeter() const override;
    double getX() const; // nie mozna oznaczyc jako final. Tylko metody wirtualne moga byc final.
    double getY() const;
    void print() const override;

private:
    Rectangle() = delete;

    double x_;
    double y_;
};
