#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Character {
public: 
    Character() {
        cout << "Character constructor\n";
    }

    int HP;
};

class Orc : public virtual Character {
public:
    Orc() {
        cout << "Orc constructor\n";
    }
};

class Warrior : public virtual Character {
public:
    Warrior() {
        cout << "Warrior constructor\n";
    }
};

class OrcWarrior : public Orc, public Warrior {
public:
    OrcWarrior() {
        cout << "OrcWarrior constructor\n";
    }
};

int main() {
    cout << "\n--------------------\n\n";

    OrcWarrior a;
    
    cout << "\n--------------------\n\n";
    return 0;
}
