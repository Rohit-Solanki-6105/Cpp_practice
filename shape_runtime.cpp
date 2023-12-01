#include <iostream>
#include <cmath>
using namespace std;

// Base class
class Shape {
public:
    virtual double area() const = 0; // Pure virtual function
    virtual void display() const = 0; // Pure virtual function
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
        cout << "Circle - Radius: " << radius << ", Area: " << area() << endl;
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
        cout << "Rectangle - Length: " << length << ", Width: " << width << ", Area: " << area() << endl;
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
        cout << "Square - Side: " << side << ", Area: " << area() << endl;
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
        cout << "Triangle - Base: " << base << ", Height: " << height << ", Area: " << area() << endl;
    }
};

int main() {
    // Using runtime polymorphism
    Shape *shape;
    
    cout<<"Enter option\n"
		<<"1. for circle\n"
		<<"2. for square\n"
		<<"3. for rectangle\n"
		<<"4. for Triangle\n>";
    int op;
    	cin>>op;
    	
    switch(op){
    	case 1:
    		cout<<"Enter radius: ";
    		double r;
    			cin>>r;
    		shape = new Circle(r);
			cout<<"Area: "<<shape->area();
			break; 
    	case 2:
    		cout<<"Enter Side: ";
    		double s;
    			cin>>s;
    		shape = new Square(s);
			cout<<"Area: "<<shape->area();
			break;
    	case 3:
    		cout<<"Enter Length and Width: ";
    		double l,w;
    			cin>>l>>w;
    		shape = new Rectangle(l,w);
			cout<<"Area: "<<shape->area();
			break;
    	case 4:
    		cout<<"Enter Base and Height: ";
    		double b, h;
    			cin>>b>>h;
    		shape = new Triangle(b, h);
			cout<<"Area: "<<shape->area();
			break;
	}

    return 0;
}
