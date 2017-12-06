//
// Created by slava on 01/10/17.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {

    // Vectors are template classes
    vector<string> strings;

    strings.emplace_back("one");
    strings.emplace_back("two");
    strings.emplace_back("three");



    for (auto it = strings.begin(); it != strings.end(); it++){
        cout << *it << ", size in bites: " << sizeof(*it)  << endl;
    }


    return 0;
}