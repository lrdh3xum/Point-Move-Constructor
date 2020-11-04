#include <iostream>

class Point
{
private:

    int* x;
    int* y;

public:
    Point() = default;

    Point(const int xx, const int yy)
    {
        x = new int;
        y = new int;

        *x = xx;
        *y = yy;
    }

    // Move constructor
    Point(Point&& obj) noexcept : x{ obj.x }, y{ obj.y }
    {
        std::cout << "Moved." << std::endl;
        std::cout << *obj.x << "\t" << *obj.y << "\n\n";
        obj.x = nullptr;
        obj.y = nullptr;
    }

    ~Point()
    {
        std::cout << "Destructor" << std::endl;
        delete x;
        delete y;
    }

    void getX() { std::cout << *x; }
    void getY() { std::cout << *y; }
};



int main()
{
    Point p2 = std::move(Point(15, 17));

    return 0;
}
