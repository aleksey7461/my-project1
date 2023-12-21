    #include <iostream>
    
    #define debug

    using namespace std;

    int main() {
    #ifndef debug
        cout << "begin\n";
    #endif 
        for (int i = 0; i < 5; i++) {
            cout << i << "\n";
        }
    #ifndef debug
        cout << "end\n";
    #else 
        cout << "debug able";
    #endif
    }
