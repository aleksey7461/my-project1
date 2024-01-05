#include <iostream>
#include <string>
#include <fstream>
#include <memory>

using namespace std;

template <class T>
class SmartPointer {
public:
    SmartPointer(T *ptr) {
        this -> ptr = ptr;
        cout << "Constructor\n";
    }

    ~SmartPointer() {
        delete ptr;
        cout << "Destructor\n";
    }

    T& operator *() {
        return *ptr;
    }

private:
    T *ptr;
};

int main() {
    cout << "\n--------------------\n\n";


    int SIZE = 3;

    shared_ptr<int[]> ptr(new int[SIZE] {1, 2, 3});

    for (int i = 0; i < SIZE; i++) {
        cout << ptr[i] << '\t';
    }
    cout << "\n";
 
    cout << "\n--------------------\n\n";
    return 0;
}
