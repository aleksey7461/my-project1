#include <iostream>

using namespace std;

class List 
{
public:
    List();
    ~List();

    void push_back(int data);
    int GetSize() { return Size; }
    int& operator [](const int index);

private:
    struct Node 
    {
        Node *Next;
        int data;

        Node(int data = int(), Node *Next = nullptr)
        {
            this -> data = data;
            this -> Next = Next;
        }
    };

    Node *head;
    int Size;
};

List::List() 
{
    Size = 0;
    head = nullptr;
}

List::~List() 
{

}

void List::push_back(int data) 
{
    if (head == nullptr) 
    {
        head = new Node(data);
    }

    else 
    {
        Node *current = this -> head;
        while (current -> Next != nullptr) 
        {
            current = current -> Next;
        }

        current -> Next = new Node(data);
    }
    Size++;
}

int main() {
    cout << "\n--------------------\n\n";

    List lst;
    lst.push_back(9);
    lst.push_back(8);
    lst.push_back(7);

    cout << lst[2] << "\n";
 
    cout << "\n--------------------\n\n";
    return 0;
}

int & List::operator[](const int index) 
{
    int counter = 0;
    int *s = new int(0);

    Node *current = this -> head;

    while (current != nullptr)
    {
        if (counter == index) 
        {
            return current -> data;
        }
        current = current
        counter++;
    }
    return *s;
}
 
