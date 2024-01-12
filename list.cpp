#include <iostream>
#include <string>

using namespace std;

class List 
{
public:
    List();
    ~List();

    void insert(int val, int index);
    void remove(int index);

    void push_back(int data);
    void push_front(int data);

    void pop_back();
    void pop_front();

    void clear();

    int & operator [](const int index);

    int GetSize() { return Size; }

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
    clear();
}

void List::insert(int data, int index)
{
    if (index == 0) 
    {
        push_front(data);
    }
    else
    {
        Node *previous = this -> head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous -> Next;
        }

        previous -> Next = new Node(data, previous -> Next);
    }
    Size++;
}

void List::remove(int index)
{
    if (index == 0) 
    {
        pop_front();
    }
    else
    {
        Node *temp = this -> head;

        for (int i = 0; i < index - 1; i++)
        {
            temp = temp -> Next;
        }

        Node *toDelete = temp -> Next;
        temp -> Next = toDelete -> Next;
 
        delete toDelete;
    }
    Size--;
}

void List::push_back(int data) 
{
    if (head == nullptr) 
    {
        head = new Node(data);
    }

    else 
    {
        Node *current = head;
        while (current -> Next != nullptr) 
        {
            current = current -> Next;
        }

        current -> Next = new Node(data);
    }
    Size++;
}

void List::push_front(int data) 
{
    head = new Node(data, head);
    Size++;

}

void List::pop_back()
{
    if (head != nullptr) 
    {
        Node *current = head;
        while (current -> Next != nullptr) 
        {
            current = current -> Next;
        }

        delete current -> Next;
    }
    Size--;
}

void List::pop_front() 
{
    Node *temp = head;

    head = head -> Next;

    delete temp;

    Size--;
}

void List::clear() 
{
    while (Size) 
    {
        pop_front();
    }
}

int & List::operator[](const int index) 
{
    int counter = 0;
    int *s = new int(7);
    int &m = *s;

    Node *current = this -> head;

    while (counter < Size)
    {
        if (counter == index) 
        {
            return current -> data;
        }
        current = current -> Next;
        counter++;
    }
    return m;
}
 
int main() 
{
    cout << "\n------------------------\n\n";

    List lst;
    lst.push_back(7);
    lst.push_back(0);
    lst.push_back(18);

    for (int i = 0; i < lst.GetSize(); i++) {  
        cout << lst[i] << '\t';
    }

    lst.remove(1);
    cout << "\n\n";

    for (int i = 0; i < lst.GetSize(); i++) {  
        cout << lst[i] << '\t';
    }

    cout << "\n------------------------\n\n";
    return 0;
}
