#include "iostream"
#include "math.h"

using namespace std;

class rect;

class polar
{

public:
    polar()
    {
    }
    float r, a;
    polar(float x = 0, float y = 0) : r(x), a(y) {}
    polar(rect &rec);
    void display()
    {
        cout << "r = " << r << " a = " << a << "\n";
    }
};

class rect
{
public:
    float x, y;
    rect() {}
    rect(float a = 0, float b = 0) : x(a), y(b) {}
    rect(polar &p)
    {
        x = p.r * cos(p.a);
        y = p.r * sin(p.a);
    }
    void display()
    {
        cout << "x = " << x << " y = " << y << "\n";
    }
};

polar::polar(rect &rec)
{
    r = sqrt(rec.x * rec.x + rec.y * rec.y);
    if (rec.y)
        a = atan(rec.x / rec.y); // atan(rec.y/rec.x)
    else
        a = 0;
}

int main()
{
    polar a(5, 5);
    a.display();
    rect p = a;
    p.display();

    rect b(0,9);
    b.display();
    polar p1 = b;
    p1.display();
    return 0;
}