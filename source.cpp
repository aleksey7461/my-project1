#include <iostream>
#include <string>

using namespace std;

template<class T>
class List 
{
public:
    List();
    ~List();

    void insert(T data, int index);
    void remove(int index);

    void push_back(T data);
    void push_front(T data);

    void pop_back();
    void pop_front();

    void clear();

    int & operator [](const int index);

    int GetSize() { return Size; }

private:
    template<class>
    struct Node 
    {
        Node *Next;
   //     Node *Prev;
        T data;

        Node(T data = T(), Node *Next = nullptr)
        {
            this -> data = data;
            this -> Next = Next;
        }
    };

    Node<T> *head;
 //   Node<T> *tail;
    int Size;
};

template<class T>
List<T>::List() 
{
    Size = 0;
    head = nullptr;
}

template<class T>
List<T>::~List() 
{
    clear();
}

template<class T>
void List<T>::insert(T data, int index)
{
    if (index == 0) 
    {
        push_front(data);
    }
    else
    {
        Node<T> *previous = this -> head;

        for (int i = 0; i < index - 1; i++)
        {
            previous = previous -> Next;
        }

        previous -> Next = new Node(data, previous -> Next);
    }
    Size++;
}

template<class T>
void List<T>::remove(int index)
{
    if (index == 0) 
    {
        pop_front();
    }
    else
    {
        Node<T> *temp = this -> head;

        for (int i = 0; i < index - 1; i++)
        {
            temp = temp -> Next;
        }

        Node<T> *toDelete = temp -> Next;
        temp -> Next = toDelete -> Next;
 
        delete toDelete;
    }
    Size--;
}

template<class T>
void List<T>::push_back(T data) 
{
    if (head == nullptr) 
    {
        head = new Node<T> (data);
    }

    else 
    {
        Node<T> *current = head;
        while (current -> Next != nullptr)
        {
            current = current -> Next;
        }

        current -> Next = new Node<T> (data);
    }
    Size++;
}

template<class T>
void List<T>::push_front(T data) 
{
    head = new Node(data, head);
    Size++;

}

template<class T>
void List<T>::pop_back()
{
    if (head != nullptr) 
    {
        Node<T> *current = head;
        while (current -> Next != nullptr) 
        {
            current = current -> Next;
        }

        delete current -> Next;
    }
    Size--;
}

template<class T>
void List<T>::pop_front() 
{
    Node<T> *temp = head;

    head = head -> Next;

    delete temp;

    Size--;
}

template<class T>
void List<T>::clear() 
{
    while (Size) 
    {
        pop_front();
    }
}

template<class T>
int & List<T>::operator[](const int index) 
{
    int counter = 0;
    int *s = new int(7);
    int &m = *s;

    Node<T> *current = this -> head;

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

    List<int> lst;
    lst.push_front(7);
    lst.insert(99, 1);
    lst.insert(65, 2);
    lst.insert(101, 1);
    lst.push_back(0);
    

    for (int i = 0; i < lst.GetSize(); i++) {  
        cout << lst[i] << '\n';
    }

    lst.pop_back();
    cout << "\n\n";

    for (int i = 0; i < lst.GetSize(); i++) {  
        cout << lst[i] << '\n';
    }

    lst.pop_front();
    cout << "\n\n";

    for (int i = 0; i < lst.GetSize(); i++) {  
        cout << lst[i] << '\n';
    }

    lst.remove(2);
    cout << "\n\n";

    for (int i = 0; i < lst.GetSize(); i++) {  
        cout << lst[i] << '\n';
    }

    cout << "\n------------------------\n\n";
    return 0;
}
