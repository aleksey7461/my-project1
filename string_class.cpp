#include <iostream>  //основная библиотека input-output-stream
#include <string>    //нахер не надо
#include <cstring>   //для strlen()

using namespace std;

class mystring {
private:
    char *str; //указатель на массив char, хранит символы, переданные в обьект
    int size;
    
public:
    //конструктор без параметров
    mystring() {
        str = nullptr;
        size = 0;
    }

    //конструктор с параметрами, передача строки в обьект
    mystring(const char *str) {
        size = strlen(str); //strlen (cstring) получает кол-во символов в строке

        // память под массив со строкой
        //+1 для null terminator
        this -> str = new char[size + 1];

        //копирование символов строки в массив
        for (int i = 0; i < size; i++) {
            this -> str[i] = str[i];
        }
        //закрытие строки null terminator
        this -> str[size] = '\0';
    }
    //деструктор, освобождение ресурсов, занятых обьектом
    ~mystring() {
        delete[] this -> str;
    }

    //конструктор копирования, необходим для создания копии обьекта, но в другой области памяти
    mystring(const mystring &other) {
        int length = strlen(other.str);
        this -> str = new char[length + 1];

        for (int i = 0; i < length; i++) {
            this -> str[i] = other.str[i];
        }

        this -> str[length] = '\0';
    }

    //перегрузка оператора присваивания
    mystring& operator =(const mystring &other) {

        //также как и в конструкторе, за исключением того, что нужно освободить
        //ресурсы обьекта если до копирования строки он уже содержал код;
        //+ стандартный синтаксис перегрузки оператора "="

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

    //перегрузка оператора сложения, необходима для конкатенации строк
    mystring operator+ (const mystring &other) {

        //создание пустого обьекта где будет храниться результат конкатенации строк, 
        //и который будет результатом работы перегруженного оператора "+"
        mystring newstr;

        //получаем кол-во символов в строках для конкатенации
        int thislength = strlen(this -> str);
        int otherlength = strlen(other.str);

        size = thislength + otherlength;

        //выделяем место в памяти под новую строку
        newstr.str = new char[size + 1];

        //копирование данных из обеих конкатенируемых строк в новую
        int i = 0;
        for (; i < thislength; i++) {
            newstr.str[i] = this -> str[i];
        }

        for (int j = 0; j < otherlength; j++, i++) {
            newstr.str[i] = other.str[j];
        }
        newstr.str[thislength + otherlength] = '\0';

        //возвращаем результат конкатенации
        return newstr;
    }

    //выводит в консоль строку, в лучшем случае необходима перегрузка оператора "<<", но похер, и так работает
    void print() {
        cout << str;
    }

    int Size() {
        return size;
    }

    int Length() {
        return strlen(str);
    }

    bool operator ==(const mystring & other) {
        if (this -> size != other.size)
            return false;
        
        for (int i = 0; i < this -> size; i++) {
            if (this -> str[i] != other.str[i])
                return false;
        }

        return true;
    }
};

int main() {
    mystring str1("x");
    mystring str2("x");

    cout << str1.Size() << "\n";
    cout << str2.Size() << "\n";

    mystring res1;
    res1 = str1 + str2;

    cout << res1.Length() << "\n";

    bool equal = str1.operator==(str2);
    if (equal)
        cout << "true\n";
    else
        cout << "false\n";
    return 0;
}
