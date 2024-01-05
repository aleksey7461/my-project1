#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>

using namespace std;

void Foo(int *pa) {
    (*pa)++;
}

int main() {
    cout << "\n--------------------\n\n";

    int a = 0;
    cout << a << '\n';
    Foo(&a);
    cout << a << '\n';
    
    cout << "\n--------------------\n\n";
    return 0;
}
