#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

constexpr unsigned long fibonacci(int n){
    if(n<=1)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

using Collection = vector<shared_ptr<Shape>>;

auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second)
{
    if(first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20 = [](shared_ptr<Shape> s)
{
    if(s)
        return (s->getPerimeter() > 20);
    return false;
};

auto areaLessThanX = [x=10](shared_ptr<Shape> s) -> auto
{
    if(s)
        return (s->getArea() < x);
    return false;
}; // lambda with a capture in capture list can not be converted to function pointer

auto printCollectionElements(const Collection& collection)
{
    for(const auto & it : collection)
        if(it)
            it->print();
}

auto printAreas(const Collection& collection)
{
    for(const auto & it : collection)
        if(it)
            cout << it->getArea() << std::endl;
}

auto findFirstShapeMatchingPredicate(const Collection& collection,
                                     function<bool(shared_ptr<Shape>)> predicate, // changed function pointer to std::function
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

int main()
{
    constexpr unsigned long fib = fibonacci(45);
    cout << fib << endl;
    // time without constexpr: ~7,2s
    // time with constexpr: ~0,01s - instantly

    Collection shapes = {
            make_shared<Circle>(2.0),
            make_shared<Circle>(3.0),
            nullptr,
            make_shared<Circle>(4.0),
            make_shared<Rectangle>(10.0, 5.0),
            make_shared<Square>(3.0),
            make_shared<Circle>(4.0),
            make_shared<Circle>(RED),
            make_shared<Rectangle>(GREEN),
            make_shared<Square>(BLUE)
    }; // added circle, rectangle and square initialized by Color parameter

    /* initialized with initializer list above
    shapes.push_back(make_shared<Circle>(2.0));
    shapes.push_back(make_shared<Circle>(3.0));
    shapes.push_back(nullptr);
    shapes.push_back(make_shared<Circle>(4.0));
    shapes.push_back(make_shared<Rectangle>(10.0, 5.0));
    shapes.push_back(make_shared<Square>(3.0));
    shapes.push_back(make_shared<Circle>(4.0));
    */

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than x=10");

    return 0;
}

