#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Weapon {
public:
    virtual void Shoot() = 0;

    void Foo() {
        cout << "foo, huinya\n";
    }
};

class Gun : public Weapon {
public:
    void Shoot() override {
        cout << "shoot\n";
    }
};

class SubmachineGun : public Gun {
public:
    void Shoot() override {
        cout << "shoot *3 \n";
    }
};

class Boom : public Weapon {
public:
    void Shoot() override {
        cout << "Big Boom\n";
    }
};

class Knife : public Weapon {
public:
    void Shoot() override {
        cout << "eb tvou mat' nahui!\n";
    }
};

class Player {
private:

public:
    void Shoot(Weapon *weapon) {
        weapon -> Shoot();
    }
};

int main() {
    cout << "\n--------------------\n\n";

    Knife knife;
    knife.Foo();

    Player a;
    a.Shoot(&knife);

    cout << "\n--------------------\n\n";
    return 0;
}
