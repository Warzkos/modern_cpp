#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(double x);
    Square(Color c);
    Square(const Square & other) = default;

    Square(Square&& src) noexcept = default;
    Square& operator=(Square&& src) noexcept = default; // rule of five says that if we implement one of the default operations we should define all other default operations

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    void print() const override;

private:
    double getY() = delete; // should not have Y dimension
    Square() = delete;
};
