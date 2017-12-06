//
// Created by slava on 01/10/17.
//

#include <iostream>
#include <map>

using namespace std;

int main() {

    map<string, int> ages;

    ages["Mike"] = 40;
    ages["Raj"] = 30;
    ages["Vicky"] = 50;

    ages["Mike"] = 70;

    ages.insert(make_pair("Peter", 100));

    if (ages.find("Sue") != ages.end()){
        cout << "Found Sue" << endl;
    } else {
        cout << "Did not find Sue" << endl;
    }

    for(auto it = ages.begin(); it != ages.end(); it++){
        cout << it->first << ", " << it->second << endl;
    }

    cout << "Size of the whole map: " << ages.size() << endl;

    return 0;
}