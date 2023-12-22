    #include <iostream>

    using namespace std;

    class point {
        private:

        int x, y, z;

        public:

        int getx() {
            return x;
        }

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

    int main() {
        point a;
        a.sety(15);
        a.setx(10);
        
        int res = a.getx();

        cout << res;

        return 0;
    }
