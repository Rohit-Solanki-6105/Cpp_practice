#include <iostream>
#include <cmath>

// Base class
class Shape {
public:
    virtual double area() const = 0; // Pure virtual function
    virtual void display() const = 0; // Pure virtual function
    virtual ~Shape() {} // Virtual destructor
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    void display() const override {
        std::cout << "Circle - Radius: " << radius << ", Area: " << area() << std::endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }

    void display() const override {
        std::cout << "Rectangle - Length: " << length << ", Width: " << width << ", Area: " << area() << std::endl;
    }
};

// Derived class: Square
class Square : public Shape {
private:
    double side;

public:
    Square(double s) : side(s) {}

    double area() const override {
        return side * side;
    }

    void display() const override {
        std::cout << "Square - Side: " << side << ", Area: " << area() << std::endl;
    }
};

// Derived class: Triangle
class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double area() const override {
        return 0.5 * base * height;
    }

    void display() const override {
        std::cout << "Triangle - Base: " << base << ", Height: " << height << ", Area: " << area() << std::endl;
    }
};

int main() {
    // Example usage
    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);
    Square square(3.0);
    Triangle triangle(5.0, 8.0);

    // Using polymorphism
    Shape* shapes[] = { &circle, &rectangle, &square, &triangle };

    for (const auto& shape : shapes) {
        shape->display();
    }

    return 0;
}
