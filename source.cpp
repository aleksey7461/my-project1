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
class myclass {
private:
    int* date;
public:
    myclass(int v) {
        date = new int[v];

        for (int i = 0; i < v; i++) {
            date[i] = rand() % 50;
        }
        cout << "object date " << date[0] << "\tconstructor\n";
    }

    ~myclass() {
        cout << "object date " << date[2] << "\tdestructor\n";
    }
};

void function() {
    cout << "function begin running\n";
    myclass a(6);
    cout << "function end running\n";
}

int main() {
    function();

    return 0;
}
