#include <iostream>

using namespace std;

class point {
private:
    int x, y, z;

public:
    point() {
        x = 0;
        y = 0;
    }
    point(int vx, int vy) {
        x = vx;
        y = vy;
    }
    int getx() {
        return x;
    }

    int gety() {
        return y;
    }

    void setx(int x1) {
        x = x1;
    }

    void sety(int y1) {
        y = y1;
    }

    void print() {
        cout << "x = " << x << "\ty = " << y << "\n \n";
    }
};

int main() {
    point a;
    a.print();

    point b(75, 191);
    b.print();

    return 0;
}
