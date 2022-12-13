#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;

class Solid {
public:
    virtual double GetVolume() = 0;
    virtual double GetSurface() = 0;
    virtual double GetSolidSize() = 0;
};

class Package {
private:
    double size;
    int kuronekoPackageSize[8] = { 60,80,100,120,140,160,180,200 };
    int japanpostPackageSize[7] = { 60,80,100,120,140,160,170 };
public:
    Package(double size) {
        this->size = size;
    }
    void GetPackageSize() {
        int kuroneko, japanpost;
        for (int i = 0; i < _countof(kuronekoPackageSize); i++) {
            if (size <= kuronekoPackageSize[i]) {
                kuroneko = kuronekoPackageSize[i];
                break;
            }
            else {
                kuroneko = 0;
            }
        }
        for (int i = 0; i < _countof(japanpostPackageSize); i++) {
            if (size <= japanpostPackageSize[i]) {
                japanpost = japanpostPackageSize[i];
                break;
            }
            else {
                japanpost = 0;
            }
        }
        cout << "荷物サイズ = " << size << endl;
        if (kuroneko == 0 && japanpost == 0) {
            cout << "ヤマト運輸 は このサイズは送れません" << "\n日本郵便(ゆうパック) は このサイズは送れません" << endl;
        }
        else if (kuroneko == 0) {
            cout << "ヤマト運輸 は このサイズは送れません" << "\n日本郵便(ゆうパック) は" << japanpost << endl;
        }
        else if (japanpost == 0) {
            cout << "ヤマト運輸 は " << kuroneko << "\n日本郵便(ゆうパック) は このサイズは送れません" << endl;
        }
        else {
            cout << "ヤマト運輸 は" << kuroneko << "\n日本郵便(ゆうパック) は " << japanpost << endl;
        }
    }
};
class Box :public Solid {
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
    double GetSolidSize() {
        return width + height + depth;
    }


};

class Cylinder :public Solid {
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
    double GetSolidSize() {
        return (4*radius) + height;
    }
    

};

class Cone :public Solid {
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
    double GetRadius() {
        return radius;
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
    double GetSolidSize() {
        return (4 * radius) + height;
    }


};

class Sphere :public Solid {
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
    double GetSolidSize() {
        return (6 * radius);
    }
    

};
int main()
{
    Box box{ 30,40,50 };
    cout << "boxの体積=" << box.GetVolume() << endl;
    cout << "boxの表面積=" << box.GetSurface() << endl;
    Cylinder cylinder{ 20,20 };
    cout << "cylinderの体積=" << cylinder.GetVolume() << endl;
    cout << "cylinderの表面積=" << cylinder.GetSurface() << endl;
    Cone cone{ 30,30 };
    cout << "coneの体積=" << cone.GetVolume() << endl;
    cout << "coneの表面積=" << cone.GetSurface() << endl;
    Sphere sphere{ 20 };
    cout << "sphereの体積=" << sphere.GetVolume() << endl;
    cout << "sphereの表面積=" << sphere.GetSurface() << endl;
    Package package[]{ box.GetSolidSize(),cylinder.GetSolidSize(),cone.GetSolidSize(),sphere.GetSolidSize() };
    for (int i = 0; i < _countof(package); i++) {
        package[i].GetPackageSize();
    }
}