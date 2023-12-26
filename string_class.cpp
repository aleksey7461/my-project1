#include <iostream>  //основная библиотека input-output-stream
#include <string>    //нахуй не надо, мы и так эту бибилиотеку пишем
#include <cstring>   //для strlen(), идругой бесполезной хуйни

using namespace std;

class mystring {
private:
    char *str; //указатель на массив char, хранит символы, переданные в обьект
    int size;
    
public:
    //конструктор без параметров =)
    mystring() {
        str = nullptr;
        size = 0;
    }

    //конструктор с параметрами =), передача строки в обьект
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
    //нихуя блять он сука не работает
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

    //выводит в консоль строку, в лучшем случае необходима перегрузка оператора "<<"
    //поебать, и так работает
    void print() {
        cout << "object\t" << str << "\n";
    }

    //вывод длинны строки (хуйня сраная)
    int Size() {
        return size;
    }

    //другой вывод длинны строки (не хуйня, сам написал)
    int Length() {
        return strlen(str);
    }

    //перегрузка оператора равенства
    bool operator ==(const mystring & other) {
        if (this -> size != other.size)
            return false;
        
        for (int i = 0; i < this -> size; i++) {
            if (this -> str[i] != other.str[i])
                return false;
        }

        return true;
    }

    //перегрузка оператора неравенства
    bool operator !=(const mystring & other) {
        if (this -> size == other.size)
            return true;
        
        for (int i = 0; i < this -> size; i++) {
            if (this -> str[i] == other.str[i])
                return false;
        }

        return false;
    }

    //перегрузка опреатора индекса
    char& operator [](int index) {
        return this -> str[index];
    }

    //еще какая-то хуйня, без которой все охуенно работает
    mystring(mystring &&other) {
        this -> size = other.size;
        this -> str = other.str;
        other.str = nullptr;
    }
};

int main() {
    cout << "\n\n";

    mystring str1("qwe");
    mystring str2("rty");
    mystring res1("xyz");
/*
    bool equal = str1 != str2;
    if (equal)
        cout << "equal\t\ttrue\n\n";
    else
        cout << "equal\t\tfalse\n\n";
    cout << "-----------------\n";

    res1.print();
    cout << "\n";
    cout << "str1 size\t" << str1.Size() << "\n";
    cout << "str2 size\t" << str2.Size() << "\n";

    res1 = str1 + str2;
    cout << "-----------------\n";
    res1.print();
    cout << "\n";

    cout << "str1 size\t"  << str1.Size() << "\n";
    cout << "str2 size\t"  << str2.Size() << "\n";
    cout << "res1 size\t"  << res1.Size() << "\n";
    cout << "res1 length\t"  << res1.Length() << "\n";
*/
    
    res1 = str1 + str2;
    res1.print();
    cout << res1.Length();

    cout << "\n\n";
    return 0;
}
