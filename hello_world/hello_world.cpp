//
// Created by slava on 01/10/17.
//

#include <iostream>
#include <list>

using namespace std;

int main() {

    list<int> numbers;

    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_front(5);

    auto eraseIt = numbers.begin();

    eraseIt = numbers.erase(eraseIt);

    cout << "Element: " << *eraseIt << endl;

    for(auto it = numbers.begin(); it != numbers.end();){
        if (*it == 2){
            numbers.insert(it, 1234);
        }

        if (*it == 1){
            it = numbers.erase(it);
        } else {
            it++;
        }
    }

    for(auto it = numbers.begin(); it != numbers.end(); it++){
        cout << *it << endl;
    }

    return 0;
}