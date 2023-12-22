#include <iostream>

using namespace std;

class point {
<<<<<<< HEAD
protected:

    int x, y, z;

    public:

    int getx() {
        return x;
    }
=======
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
>>>>>>> c++_classes_les_1

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
<<<<<<< HEAD

int main() {
    point a;
    a.sety(15);
    a.setx(10);
        
    int res = a.getx();

    cout << res;
=======
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
>>>>>>> c++_classes_les_1

    return 0;
}
