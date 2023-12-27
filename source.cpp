#include <iostream>
#include <vector>
#include <string>

using namespace std;

class A {
private:
    string mes;
public:
    A() {
        cout << "constructor1 - A\n";
    }

    A(string mes) {
        this -> mes = mes;
        cout << "constructor2 - A\n";
    }

    void printMes() {
        cout << mes << "\n";
    }
};

class B : public A {
public:
    B() : A("new message") {

    }
};

int main() {
    cout << "\n--------------------\n\n";

    B value;
    value.printMes();

    cout << "\n--------------------\n\n";
    return 0;
}
