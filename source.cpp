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
    int size;
public:
    myclass(int s) {
        this -> size = s;
        this -> date = new int[s];

        for (int i = 0; i < s; i++) {
            date[i] = i;
        }
        cout << "constructor has been calld\t" << this << "\n\n";
    }
    myclass(const myclass &other) {
        this -> size = other.size;
        this -> date = new int [other.size];

        for (int i = 0; i < other.size; i++) {
            this -> date[i] = other.date[i];
        }
        cout << "copy constructor has been calld\t" << this << "\n\n";
    }
    ~myclass() {
        cout << "destructor has been calld\t" << this << "\n\n";
        delete[] date;
    }
};

void function() {
    cout << "function begin running\n";
    myclass a(6);
    cout << "function end running\n";
}

void foo(myclass val) {
    cout << "foo has been calld\n";
}

myclass foo2() {
    cout << "foo2 has been calld\n";
    myclass t(2);
    return t;
}

int main() {
    myclass a(10);
    myclass b(a);
    //foo2();
    return 0;
}
