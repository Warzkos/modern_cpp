#pragma once

#include "Shape.hpp"

class Circle final : public Shape
{
public:
    Circle(double r);
    Circle(Color c);
    Circle(const Circle & other) = default;

    Circle(Circle&& src) noexcept = default;
    Circle& operator=(Circle&& src) noexcept = default; // rule of five says that if we implement one of the default operations we should define all other default operations

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    double getRadius() const;
    [[deprecated]] double getPi() const;
    void print() const override;

private:
    Circle() = delete; // doesn't allow to call default constructor

    double r_;
};
