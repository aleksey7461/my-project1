    #include <iostream>
    using namespace std;

    class myclass {
        private:
            int a1 = 10;
            int b1 = 15;
        public:
            void printa1() {
                cout << a1 << "\n";
            }

            void printb1() {
                cout << b1 << "\n";
            }
    };

    int main() {
        myclass a;
        a.printa1();
    }
