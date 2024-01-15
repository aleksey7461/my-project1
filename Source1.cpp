#include <iostream>
#include <set>

using namespace std;


int main() {
    cout << "\n--------------------\n\n";

    set<int> mySet = {1, -5, 82, -17, 0};

    mySet.insert(0);
    mySet.insert(1);
    mySet.insert(3);
    mySet.insert(-4);

    for (auto &item : mySet)
    {
        cout << item << '\n';
    }

    auto it = mySet.find(0);
    cout << *it << '\n';
 
    cout << "\n--------------------\n\n";
    return 0;
}
