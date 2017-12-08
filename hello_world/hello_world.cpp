//
// Created by slava on 01/10/17.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Test {
    int id;
    string name;

public:
    Test(int id, string name): id(id), name(std::move(name)) {};

    void print() {
        cout << this->id << ": " << this->name << endl;
    }

    /*bool operator < (const Test& other) const {
        if (name == other.name){
            return id < other.id;
        } else {
            return name < other.name;
        }

    }*/

    friend bool comp(const Test &a, const Test &b);
};

bool comp(const Test &a, const Test &b){
    return a.name < b.name;
}

int main() {

    vector<Test> tests;

    tests.emplace_back(1, "Mike");
    tests.emplace_back(10, "Sue");
    tests.emplace_back(5, "Raj");
    tests.emplace_back(15, "Hussain");

    sort(tests.begin(), tests.end(), comp);

    for (auto &test : tests) {
        test.print();
    }


    return 0;
}