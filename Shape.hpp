#pragma once

enum Color : unsigned char
{
    RED,
    GREEN,
    BLUE,
};

class Shape
{
public:
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

protected:
    Color color;
};
