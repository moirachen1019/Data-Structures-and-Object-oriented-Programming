#include <cstdlib>
#include <iostream>
#define PI 3.14
using namespace std;

class Shape {
protected:
    float volume;

public:
    Shape() { volume = 0; }
    virtual void computeVolume() = 0;
    //pure virtual function，代表Shape是abstract class，無法創造 Shape 的物件，只有他的subclass才能
    void printVolume() //non-virtual，繼承此class的children不能更改它
    {
        cout << volume << endl; //經過每個children不同定義的計算體積後回傳的體積在此印出
    }
};
class Cuboid : public Shape
{
public:
    Cuboid(float a, float b, float c) {
        length = a;
        width = b;
        height = c;
    }
    virtual void computeVolume() override {
        volume = length * width * height; //cuboid : length * width * height
    }
private:
    float length, width, height;
};
class Pyramid : public Shape
{
public:
    Pyramid(float a, float b) {
        base = a;
        height = b;
    }
    virtual void computeVolume() override {
        volume = base * height / 3; //pyramid : area of base * height / 3
    }
private:
    float base, height;
};
class Sphere : public Shape
{
    // Add code here
public:
    Sphere(float a) {
        radius = a;
    }
    virtual void computeVolume() override {
        volume = (4 * radius * radius * radius * PI) / 3; //sphere : 4/3 * radius^3 * 3.14
    }
private:
    float radius;
    // Add code here
};

int main()
{
    float a, b, c;
    Shape* shape; //宣告shape指標

    cin >> a >> b >> c; // Enter the height and width of Rectangle
    Cuboid cub(a, b, c);

    cin >> a >> b; // Enter the bottom and height of Triangle
    Pyramid pyr(a, b);

    cin >> a; // Enter the radius of Circle
    Sphere sph(a);

    shape = &cub; //shape指標指向cub的地址
    shape->computeVolume(); // -> access a member function or variable of an object through a "pointer"
                                                    //with a regular variable or reference, you use the " . "
    shape->printVolume();

    shape = &pyr;
    shape->computeVolume();
    shape->printVolume();

    shape = &sph;
    shape->computeVolume();
    shape->printVolume();

    return 0;
}
