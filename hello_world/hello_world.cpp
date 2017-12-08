//
// Created by slava on 01/10/17.
//

#include <iostream>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

struct Test {
    string name;

public:

    explicit Test(string name) : name(std::move(name)) {};

    ~Test();

    void print() {
        cout << name << endl;
    }

};

Test::~Test() = default;

int main() {

    // Stacks are last-in-first-out (LIFO) collections
    // Queues are first-in-first-out (FIFO) collections
    queue<Test> testQueue;

    testQueue.push(Test("Smith"));
    testQueue.push(Test("Alex"));
    testQueue.push(Test("Jon"));



    while(!testQueue.empty()){
        Test &test = testQueue.front();
        test.print();

        testQueue.pop();
    }


    return 0;
}