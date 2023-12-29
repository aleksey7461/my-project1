#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Point {
public:
    int x, y, z;

    Point() {
        x = 0;
        y = 0;
        z = 0;
    }

    Point(int x, int y, int z) {
        this -> x = x; 
        this -> y = y;
        this -> z = z;
    }
};

ostream& operator <<(ostream& os, const Point& point) {
    os << point.x << " " << point.y << " " << point.z;
    return os;
}

istream& operator >>(istream& is, Point& point) {
    is >> point.x >> point.y >> point.z;
    return is;
}

int main() {
    cout << "\n--------------------\n\n";

    string path = "MyTestFile.txt";
    string text;
    
    Point a;

    fstream fs;
    fs.open(path, fstream::in | fstream::out);
    
    if (!fs.is_open()) {
        cout << "FAILED\n";
    }
    else {
        fs >> a;
        cout << a << "\n";
        cout << "\nDONE\n";
    }

    fs.close();
    
    cout << "\n--------------------\n\n";
    return 0;
}
;
