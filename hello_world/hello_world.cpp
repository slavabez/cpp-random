//
// Created by slava on 01/10/17.
//

#include <iostream>
#include <map>
#include <utility>

using namespace std;

struct Person {
    string name;
    int age;

    Person(): name(""), age(0){};

    Person(string name, int age): name(std::move(name)), age(age){};

    Person(const Person &another){
        cout << "Using the copy constructor" << endl;
        name = another.name;
        age = another.age;
    }

    // Overriding the < operator to allow it to be added as a key to a Map
    bool operator < (const Person &other) const {
        if (name == other.name){
            return age < other.age;
        } else {
            return name < other.name;
        }
    }

};

int main() {

    map<Person, int> people;

    people[Person("Mike", 20)] = 1;
    people[Person("Mike", 222)] = 222;
    people[Person("Olaf", 30)] = 2;
    people[Person("Geoff", 40)] = 3;

    for (auto &it : people) {
        cout << it.second << ", " << it.first.name << ", " << it.first.age << " years old" << endl;
    }

    return 0;
}