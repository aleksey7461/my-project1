#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
class Student {
private:
    int ID;
    static int Count;

public:

    Student () {
        Count++;
        ID = Count;
    }

    int getID() {
        return ID;
    }

    int getCount() {
        return Count;
    }

    static void changeID (Student & student, int ID) {
        student.ID = ID;
    }
    
};

int Student::Count = 0;

class Apple;
class Human;

class Human {
public: 
    void takeApple(Apple &apple);

    void eatApple(Apple &apple);
};

class Apple {
private:
    int weight;
    string color;

    friend Human;

public:

    static int count;


    Apple(int weight, string color) {
        this -> weight = weight;
        this -> color = color;
        count++;
    }
};

int Apple::count = 0;


class human1 {
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
private:
    int x, y, z;
    friend void changex(point &val);

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

    point operator +(const point & other) {
        point temp;
        temp.x = this -> x + other.x;
        temp.y = this -> y + other.y;

        return temp;
    }

    point operator -(const point & other) {
        point temp;
        temp.x = this -> x - other.x;
        temp.y = this -> y - other.y;

        return temp;
    }
/*
    int getx() {
        return x;
    }

    int gety() {
        return y;
    }
*
    void setx(int x) {
        this -> x = x;
    }

    void sety(int y) {
        this -> y = y;
    }

    void print() {
        cout << "x = " << x << "\ty = " << y << "\n \n";
    }

    point & operator ++() {
        this -> x++;
        this -> y += 1;
        return *this;
    }

    point operator ++(int val) {
        point temp(*this);

        this -> x++;
        this -> y++;

        return temp;
    }

    point & operator --() {
        this -> x--;
        this -> y -= 1;
        return *this;
    }

    point operator --(int val) {
        point temp(*this);

        this -> x--;
        this -> y--;

        return temp;
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

class source {
private:

public:
    source();
    ~source();

    void print();
};

source::source()
{
}

source::~source()
{
}

void source::print() {
    cout << "hi bitch";
}

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

void changex(point &val) {
    val.x = -1;
}
*/
/*
class Image {
private:
    static const int size = 5;

    class Pixel {
    private:
        int r, g, b;
    
    public:
        Pixel(int r, int g, int b) {
            this -> r = r;
            this -> b = b;
            this -> g = g;
        }

        string getInfo() {
            return "Pixel: r = " + to_string(r) + "\t g = " + to_string(g) + "\t b = " + to_string(b);
        }
    };

    Pixel pix[size] {
        Pixel(0, 19, 81),
        Pixel(71, 94, 65),
        Pixel(187, 5, 1),
        Pixel(224, 3, 8),
        Pixel(56, 97, 7)
    };
public:
    void getImageInfo() {
        for (int i = 0; i < size; i++) {
            cout << pix[i].getInfo() << "\n";
        }
    }

};*/
/*
class Cap {
private:
    string color = "Red";

public: 
    string getCol() {
        return color;
    }
};

class Human {
private:
    class Brain {
    private:
        int a, b, c;

    public:
        void Think() {
            cout << "Human-Brain::Think\n";
        }
    };

    Brain brain;
    Cap cap;

public:
    void Think() {
        brain.Think();
    }

    void inspectCap() {
        cout << "My Cap\t" << cap.getCol();
    }
};

class Model {
private:
    Cap cap;
public:
    void inspectModel() {
        cout << "\ncap\t" << cap.getCol() << "\tmodel\n";
    }
};
*/

class Human {
private:
    string name = "Eban'ko";

public:
    string getName() {
        return name;
    }
};

class Student : public Human {
public:
    string group = "cx";
    void Learn() {
        cout << "I am learning\n";
    }

};

class Professor : public Human {
public:
    string subject;

};

class ExStudent : public Student{
private:

public:
    void Learn() {
        cout << "Extra Student\n";
    }
};

int main() {
    cout << "\n--------------------\n\n";

    Student a;
    a.Learn();
    ExStudent b;
    b.Learn();
    cout << b.getName() << "\n";

    cout << "\n--------------------\n\n";
    return 0;
}
/*
void Human::takeApple(Apple & apple) {
    cout << "takeApple has been called\n" << "weight \t" << apple.weight << "\ncolor \t" << apple.color << "\n";
}

void Human::eatApple(Apple & apple) {
    apple.weight = 150;
}
*/
 