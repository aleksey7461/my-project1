    #include <iostream>

    using namespace std;

    class point {
        private:
        int x;
        protected:
        int y;
        int z;
        public:
        void print() {
            cout << "x = " << x << " y = " << y << " z = " << z << "\n";
        }
    };

    int main() {
        point a;
        a.print();
        return 0;
    }
