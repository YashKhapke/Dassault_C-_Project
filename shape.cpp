#include "shape.h"
#include<bits/stdc++.h>
using namespace std;

//// Shape ////

Shape::Shape() : PI(3.1415) {}
    
//// 2d shape ////

TwoDShape::~TwoDShape() {}
void TwoDShape::update() {}
void TwoDShape::display() {}
//// 3d shape ////
void ThreeDShape::update() {}
void ThreeDShape::display() {}

ThreeDShape::~ThreeDShape() {}


//// Circle ////

Circle::Circle(double radius,double x,double y)
{
    this->radius = radius;
    centerX = x;
    centerY = y;
}

double Circle::area() {
    return PI * radius * radius;
}

double Circle::perimeter(){
    return 2 * PI * radius;
}

double Circle::getRadius(){
    return radius;
}

void Circle::setRadius(double radius) {
    this->radius = radius;
}

void Circle::display() {
    cout << "Type: Circle\n";
    cout << "Radius: " << radius << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}

void Circle::update() {
    double newRadius;
    cout << "Enter the new radius: ";
    cin >> newRadius;
    setRadius(newRadius);
}

//// Rectangle ////

Rectangle::Rectangle(double length, double width) {
    this->length = length;
    this->width = width;
}

double Rectangle::area()  {
    return length * width;
}

double Rectangle::perimeter()  {
    return 2 * (length + width);
}

double Rectangle::getLength()  {
    return length;
}

double Rectangle::getWidth()  {
    return width;
}

void Rectangle::setLength(double length) {
    this->length = length;
}

void Rectangle::setWidth(double width) {
    this->width = width;
}

void Rectangle::display() {
    cout << "Type: Rectangle\n";
    cout << "Length: " << length << ", Width: " << width << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}
void Rectangle::update() {
    double newLength, newWidth;
    cout << "Enter the new length: ";
    cin >> newLength;
    setLength(newLength);
    cout << "Enter the new width: ";
    cin >> newWidth;
    setWidth(newWidth);
}

// Square //

Square::Square(double side) {
    this->side = side;
}

double Square::area() {
    return side * side;
}

double Square::perimeter() {
    return 4 * side;
}

double Square::getSide() {
    return side;
}

void Square::setSide(double side) {
    this->side = side;
}

void Square::display() {
    cout << "Type: Square\n";
    cout << "Length: " <<side  << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}

void Square::update() {
    double newSide;
    std::cout << "Enter the new side length: ";
    std::cin >> newSide;
    setSide(newSide);
}

////  Sphere   ////

Sphere::Sphere(double radius, double centerX, double centerY,double centerZ) {
    this->radius = radius;
    this->centerX = centerX;
    this->centerY = centerY;
    this->centerZ = centerZ;
    this->pCircle = new Circle(radius, centerX, centerY);
}

double Sphere::volume()  {
    return (4.0 / 3.0) * PI * radius * radius * radius;
}

double Sphere::surfaceArea()  {
    return 4 * PI * radius * radius;
}

double Sphere::getRadius()  {
    return radius;
}

void Sphere::setRadius(double radius) {
    this->radius = radius;
    pCircle->setRadius(radius);
}
void Sphere::setCircle(Circle* circle) {
    pCircle = circle;
}

void Sphere::display() {
    cout << "Type: Sphere\n";
    cout << "Radius: " << radius << endl;
    cout << "Volume: " << volume() << endl;
    cout << "Surface Area: " << surfaceArea() << endl;
}
void Sphere::update() {
    double newRadius;
    cout << "Enter the new radius: ";
    cin >> newRadius;
    setRadius(newRadius);
}


//// Cuboid ////

Cuboid::Cuboid(double length, double width, double height, double centerX, double centerY, double centerZ) {
    this->length = length;
    this->width = width;
    this->height = height;
    this->centerX = centerX;
    this->centerY = centerY;
    this->centerZ = centerZ;
    this->pRectangle= new Rectangle(length,width);
  
}

double Cuboid::volume()  {
    return length * width * height;
}

double Cuboid::surfaceArea()  {
    return 2 * (length * width + length * height + width * height);
}

double Cuboid::getLength()  {
    return length;
}

double Cuboid::getWidth()  {
    return width;
}

double Cuboid::getHeight()  {
    return height;
}

void Cuboid::setLength(double length) {
    this->length = length;
    pRectangle->setLength(length);
}

void Cuboid::setWidth(double width) {
    this->width = width;
    pRectangle->setWidth(width);
}

void Cuboid::setHeight(double height) {
    this->height = height;
   
}

void Cuboid::setRectangle(Rectangle* rectangle) {
    pRectangle = rectangle;
}

void Cuboid::display()  {
    cout << "Type: Cuboid\n";
    cout << "Length: " << length << ", Width: " << width << ", Height: " << height << endl;
    cout << "Volume: " << volume() << endl;
    cout << "Surface Area: " << surfaceArea() << endl;
}

void Cuboid::update() {
    double newLength, newWidth, newHeight;
    cout << "Enter the new length: ";
    cin >> newLength;
    setLength(newLength);
    cout << "Enter the new width: ";
    cin >> newWidth;
    setWidth(newWidth);
    cout << "Enter the new height: ";
    cin >> newHeight;
    setHeight(newHeight);
}


// Cube //

Cube::Cube(double side, double centerX, double centerY, double centerZ) {
    this->side = side;
    this->centerX = centerX;
    this->centerY = centerY;
    this->centerZ = centerZ;
    this->pSquare = new Square(side);
}

double Cube::volume() {
    return side * side * side;
}

double Cube::surfaceArea() {
    return 6 * side * side;
}

double Cube::getSide() {
    return side;
}

void Cube::setSide(double side) {
    this->side = side;
    pSquare->setSide(side);
}
void Cube::setSquare(Square* square) {
    pSquare = square;
}
void Cube::display() {
    cout << "Type: Cube\n";
    cout << "Length: " << side <<endl;
    cout << "Volume: " << volume() << endl;
    cout << "Surface Area: " << surfaceArea() << endl;
}

void Cube::update() {
    double newSide;
    std::cout << "Enter the new side length: ";
    std::cin >> newSide;
    setSide(newSide);
}