#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class mystring {
private:
    char *str;
public:
    mystring() {
        str = nullptr;
    }
    mystring(const char *str) {
        int length = strlen(str);
        cout << length;
    }
    ~mystring() {

    }
};

int main() {
    mystring str("sex");
    return 0;
}
