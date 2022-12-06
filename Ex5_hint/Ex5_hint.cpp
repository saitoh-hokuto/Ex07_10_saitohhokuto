#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

/// <summary>
/// 物体の定義
/// </summary>
class Solid {
public:
    virtual double GetVolume() = 0;
    virtual double GetSurface() = 0;
};

/// <summary>
/// 箱型
/// </summary>
class Box :Solid {
private:
    double width;
    double height;
    double depth;

public:
    Box(
        double width,   //幅
        double height,  //高さ
        double depth) {//奥行
        this->width = width;
        this->height = height;
        this->depth = depth;
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
    double GetVolume() {
        return (radius * radius) * M_PI * height;
    }
    double GetSurface() {
        return 2 * M_PI * radius * (height + radius);
    }


};

class Sphere :Solid {
private:
    double radius;

public:
    Sphere(
        double radius,) {
        this->radius = radius;
        this->height = height;
    }
    double GetVolume() {
        return (radius * radius) * M_PI * height;
    }
    double GetSurface() {
        return 2 * M_PI * radius * (height + radius);
    }


};
int main()
{
    Box box{ 3,5,2.5 };
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