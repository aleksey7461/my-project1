    #include <iostream>

    using namespace std;

    class point {
        private:

        bool cv() {
            return false;
        }
        public:

        void start() {
            bool vn = cv();
            if (vn)
                cout << "vjuhhhhh";
            else
                cout << "bee";
        }
    };

    int main() {
        point a;
        a.start();
        return 0;
    }
