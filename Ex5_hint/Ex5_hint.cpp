#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

class Solid {
public:
    virtual double GetVolume() = 0;
    virtual double GetSurface() = 0;
};

class Box :Solid {
private:
    double width;
    double height;
    double depth;

public:
    Box(
        double width,
        double height,
        double depth) {
        this->width = width;
        this->height = height;
        this->depth = depth;
    }
    double GetWidth() {
        return width;
    }
    double GetHeight() {
        return height;
    }
    double GetDepth() {
        return depth;
    }
    double GetVolume() {
        return width * height * depth;
    }
    double GetSurface() {
        return (width * height + height * depth + depth * width) * 2;
    }


};

class Cylinder :Solid {
private:
    double radius;
    double height;

public:
    Cylinder(
        double radius,
        double height){
        this->radius = radius;
        this->height = height;
    }
    double GetRadius() {
        return radius;
    }
    double GetHeight() {
        return height;
    }
    double GetVolume() {
        return (radius*radius)*M_PI*height;
    }
    double GetSurface() {
        return 2*M_PI*radius*(height+radius);
    }


};

class Cone :Solid {
private:
    double radius;
    double height;

public:
    Cone(
        double radius,
        double height) {
        this->radius = radius;
        this->height = height;
    }
    double GetBottom() {
        return bottom;
    }
    double GetHeight() {
        return height;
    }
    double GetVolume() {
        return ((radius * radius) * M_PI)*height/3;
    }
    double GetSurface() {
        double side = sqrt(height * height + radius * radius);
        return M_PI*radius*(radius+side);
    }


};

class Sphere :Solid {
private:
    double radius;

public:
    Sphere(
        double radius) {
        this->radius = radius;
    }
    double GetRadius() {
        return radius;
    }
    double GetVolume() {
        return (4.0 / 3) * M_PI * radius * radius * radius;
    }
    double GetSurface() {
        return 4 * M_PI * radius * radius;
    }


};
int main()
{
    Box box{ 3.0,4.0,5.0 };
    cout << "boxの体積=" << box.GetVolume() << endl;
    cout << "boxの表面積=" << box.GetSurface() << endl;
    Cylinder cylinder{ 2,2 };
    cout << "cylinderの体積=" << cylinder.GetVolume() << endl;
    cout << "cylinderの表面積=" << cylinder.GetSurface() << endl;
    Cone cone{ 2,2 };
    cout << "coneの体積=" << cone.GetVolume() << endl;
    cout << "coneの表面積=" << cone.GetSurface() << endl;
    Sphere sphere{ 2 };
    cout << "sphereの体積=" << sphere.GetVolume() << endl;
    cout << "sphereの表面積=" << sphere.GetSurface() << endl;
}