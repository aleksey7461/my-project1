#include <iostream>

using namespace std;

class point {
private:
    int x, y, z;

public:
    point() {
        x = 0;
        y = 0;
        cout << this << "\tconstructor1\n\n";
        this->setx(85);
    }
    point(int vx, int vy) {
        x = vx;
        y = vy;
        cout << this << "\tconstructor2\n\n";
    }
    int getx() {
        return x;
    }

    int gety() {
        return y;
    }

    void setx(int x) {
        this -> x = x;
    }

    void sety(int y) {
        this -> y = y;
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
    point a;
    a.setx(77);
    a.sety(98);

    point b(89, 65);
    b.getx();
    b.gety();

    point c;
    c.setx(7);
    c.sety(19);
    c.print();

    return 0;
}
