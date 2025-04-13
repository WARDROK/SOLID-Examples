#include <iostream>
#include <vector>
#include <memory>
#include <numbers> // C++20 header for mathematical constants

class Shape
{
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height) : width_(width), height_(height) {};

    double area() const override
    {
        return width_ * height_;
    }

private:
    double width_, height_;
};

class Circle : public Shape
{
public:
    Circle(double radius) : radius_(radius) {};

    double area() const override
    {
        // -std=c++20
        return std::numbers::pi * radius_;
    }

private:
    double radius_;
};

void printArea(const Shape &shape)
{
    std::cout << "Area: " << shape.area() << std::endl;
}

int main()
{
    Rectangle rect(3.5, 2.0);
    Circle circle(5.0);

    // Liskov Substitution Principle:
    // Objects of type Rectangle and Circle, which are subtypes of Shape,
    // can be passed to the printArea function.
    printArea(rect);
    printArea(circle);

    return 0;
}