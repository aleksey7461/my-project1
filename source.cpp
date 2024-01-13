#include <iostream>
#include <vector>
#include <list>

typedef std::vector<int> vint;

using namespace std;

template<class T>
void Print_l(const list<T> &lst)
{
    for (auto i = lst.cbegin(); i != lst.cend(); ++i)
    {
        cout << *i << '\n';
    }
}

int main() {
    cout << "\n--------------------\n\n";

    list<int> lst = {1, 2, 3, 5, 4};
    list<int>::iterator it = lst.begin();

    cout << *it << '\t';

    it++;
    cout << *it << '\t';

    ++it;
    cout << *it << '\t';

    Print_l(lst);
 
    cout << "\n--------------------\n\n";
    return 0;
}
