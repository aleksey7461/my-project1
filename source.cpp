#include <iostream>
#include <vector>
#include <string>

using namespace std;

class A {
public:
    A() {
        cout << "constructor - A\n";
    }
};

class B : public A {
public:
    B() {
        cout << "constructor - B\n";
    }
};

class C : public B {
public:
    C() {
        cout << "constructor - C\n";
    }
};

int main() {
    cout << "\n--------------------\n\n";

    C c;

    cout << "\n--------------------\n\n";
    return 0;
}
