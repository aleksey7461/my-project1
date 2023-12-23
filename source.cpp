#include <iostream>
#include <vector>
#include <string>

using namespace std;

class human {
private:
    int age, height, weight;
    string name, lastname;
public:
    void getname() {
        cout << "your name is " << name << "\n";
    }

    void getparam() {
        cout << "your age is\t" << age << "\n";
        cout << "your weight is\t" << weight << "\n";
        cout << "your heght is\t" << height << "\n";
    }

    void setparam(int w, int a, int h) {
        cout << "weight\t";
        cin >> w;
        cout << "\nage\t";
        cin >> a;
        cout << "\nheght\t";
        cin >> h;

        weight = w;
        height = h;
        age = a;
    }
};

class point {


=======
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

    bool operator ==(const point & other) {
            return this -> x == other.x && this -> y == other.y;
    }

    bool operator !=(const point & other) {
            return !(this -> x == other.x && this -> y == other.y);
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

    myclass & operator = (const myclass &other) {
        cout << "operator = " << this << "\n\n";

        this -> size = other.size;

        if (this -> date != nullptr) {
            delete[] this -> date;
        }

        this -> date = new int[other.size];

        for (int i = 0; i < other.size; i++) {
            this -> date[i] = other.date[i];
        }

        return *this;
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
    point a(5, 1);
    point b(5, 2);

    bool res = a != b;
    cout << res;

    return 0;
}
