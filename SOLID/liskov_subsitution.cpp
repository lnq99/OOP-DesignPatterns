#include <iostream>


using namespace std;

class Rectangle {
protected:
    int width, height;
public:
    Rectangle(int width, int height) : width(width), height(height) {}

    int getWidth() const {
        return width;
    }

    virtual void setHeight(int height) {
        Rectangle::height = height;
    }

    int area() const { return width * height; }
};

class Square : public Rectangle {
public:
    Square(int size) : Rectangle(size, size) {}

    void setHeight(int height) override {
        this->width = this->height = height;
    }
};

struct RectangleFactory {
    static Rectangle create_rectangle(int w, int h);

    static Rectangle create_square(int size);
};

void test(Rectangle &r) {
    int w = r.getWidth();
    r.setHeight(10);
    cout << "expected area = " << (w * 10) << ", got " << r.area() << endl;
}

int main() {
    Rectangle r(2, 3);
    test(r);

    // Violate Liskov substitution principle
    // Solution: use factory
    Square s(5);
    test(s);

    return 0;
}