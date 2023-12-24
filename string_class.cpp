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
        this -> str = new char[length + 1];

        for (int i = 0; i < length; i++) {
            this -> str[i] = str[i];
        }

        this -> str[length] = '\0';
    }

    ~mystring() {
        delete[] this -> str;
    }

    mystring(const mystring &other) {
        int length = strlen(other.str);
        this -> str = new char[length + 1];

        for (int i = 0; i < length; i++) {
            this -> str[i] = other.str[i];
        }

        this -> str[length] = '\0';

    }

    mystring& operator =(const mystring &other) {
        if (this -> str != nullptr) {
            delete[] str;
        }

        int length = strlen(other.str);
        this -> str = new char[length + 1];

        for (int i = 0; i < length; i++) {
            this -> str[i] = other.str[i];
        }

        this -> str[length] = '\0';

        return *this;
    }

    mystring operator+ (const mystring &other) {
        mystring newstr;

        int thislength = strlen(this -> str);
        int otherlength = strlen(other.str);

        newstr.str = new char[thislength + otherlength + 1];

        int i = 0;
        for (; i < thislength; i++) {
            newstr.str[i] = this -> str[i];
        }

        for (int j = 0; j < otherlength; j++, i++) {
            newstr.str[i] = other.str[j];
        }
        newstr.str[thislength + otherlength] = '\0';

        return newstr;
    }

    void print() {
        cout << str;
    }
};

int main() {
    mystring str1("sex ");
    mystring str2("anal");
    mystring res1;
    res1 = str1 + str2;
    res1.print();
    return 0;
}
