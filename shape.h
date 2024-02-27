#ifndef SHAPES_H
#define SHAPES_H
#include <iostream>
#include <string>
#include <map>

// Shape //
class Shape {

protected:
    const double PI;

public:
    Shape();
    ~Shape() {}
    virtual void display() = 0;
    virtual void update() = 0;
};

// 2D shapes //

class TwoDShape : public Shape {

public:
    virtual double area() = 0;
    virtual double perimeter()  = 0;
    void display();
    void update();
    ~TwoDShape();
};

// 3D shapes //

class ThreeDShape : public Shape {
public:
    virtual double volume() = 0;
    virtual double surfaceArea() = 0;
    void display();
    void update();
    ~ThreeDShape();
};

// Circle //

class Circle : public TwoDShape {
private:

    double radius;
    double centerX;
    double centerY;

public:
    Circle(double radius, double centerX, double centerY);
    double area();
    double perimeter() ;
    double getRadius() ;
    void setRadius(double radius);
    void display();
    void update();
    
};

// Rectangle //

class Rectangle : public TwoDShape {
private:
    double length;
    double width;

public:
    Rectangle(double length, double width);
    double area() ;
    double perimeter() ;
    double getLength() ;
    double getWidth() ;
    void setLength(double length);
    void setWidth(double width);
    void display();
    void update();
};

class Square : public TwoDShape {
private:
    double side;

public:
    Square(double side);
    double area();
    double perimeter();
    double getSide();
    void setSide(double side);
    void display();
    void update();
};

// Sphere //

class Sphere : public ThreeDShape {
private:
    double radius;
    double centerX;
    double centerY;
    double centerZ;
    Circle* pCircle;

public:
    Sphere(double radius, double centerX, double centerY,double CenterZ);
    double volume() ;
    double surfaceArea() ;
    double getRadius() ;
    void setRadius(double radius);
    void setCircle(Circle* circle);
    void display();
    void update();
};

// Cuboid //

class Cuboid : public ThreeDShape {
private:
    double length;
    double width;
    double height;
    double centerX;
    double centerY;
    double centerZ;
    Rectangle* pRectangle;

public:
    Cuboid(double length, double width, double height,double centerX,double centerY, double centerZ);
    double volume() ;
    double surfaceArea() ;
    double getLength() ;
    double getWidth() ;
    double getHeight();
    void setLength(double length);
    void setWidth(double width);
    void setHeight(double height);
    void setRectangle(Rectangle* rectangle);
    void display();
    void update();

};

class Cube : public ThreeDShape {
private:
    double side;
    double centerX;
    double centerY;
    double centerZ;
    Square* pSquare;

public:
    Cube(double side, double centerX, double centerY, double centerZ);
    double volume() ;
    double surfaceArea();
    double getSide();
    void setSide(double side);   
    void display() ;
    void update() ;
    void setSquare(Square* square);
};



#endif 
