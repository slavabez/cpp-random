//
// Created by slava on 01/10/17.
//

#include <iostream>
#include <set>

using namespace std;

struct Test {
    int id;
    string name;

public:
    Test(): id(0), name("") {};
    Test(int id, string name): id(id), name(move(name)) {};

    void print() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    bool operator < (const Test &other) const {
        return id < other.id;
    }
};

int main() {

    set<int> numbers;

    numbers.insert(1);
    numbers.insert(5);
    numbers.insert(3);
    numbers.insert(7);
    numbers.insert(1);



    for (auto &n: numbers){
        cout << n << ". ";
    }

    // Finding a value
    auto itFind = numbers.find(7);

    if (numbers.count(7)){
        cout << endl << "Found value: 7";
    }

    cout << endl;

    // Set with a struct
    set<Test> tests;

    tests.insert(Test(5, "Mike"));
    tests.insert(Test(7, "Dave"));
    tests.insert(Test(12, "Joe"));

    for (auto it = tests.begin(); it != tests.end(); it++){
        it->print();
    }


    return 0;
}