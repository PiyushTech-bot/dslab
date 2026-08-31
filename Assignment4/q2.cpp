#include <iostream>
using namespace std;

class Rectangle
{
private:
    float width;
    float height;

public:
    Rectangle(float w, float h)
    {
        if (w <= 0 || h <= 0)
        {
            cout << "Error! Negative values not allowed" << endl;
            width = height = 0;
        }
        else
        {
            width = w;
            height = h;
        }
    }
    float area()
    {
        return width * height;
    }
    float perimeter()
    {
        return 2 * (width + height);
    }
    bool is_square()
    {
        if (width == height)
        {
            return true;
        }
        else
            return false;
    }
};
int main()
{
    Rectangle r1(5.0, 5.0);
    Rectangle r2(4.0, 10.0);
    cout << "r1 Area" << r1.area() << endl;
    cout << "Is r1 a Square: " << boolalpha << r1.is_square() << endl;
    cout << "r2 Area" << r2.area() << endl;
    cout << "Is r2 a Square: " << boolalpha << r2.is_square() << endl;
    return 0;
}