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
    Shape() = default;
    Shape(Color c); // after adding Shape(Color c) it becomes default constructor, this can be fixed by adding default constructor
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

protected:
    Color color;
};
