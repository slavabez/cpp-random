//
// Created by slava on 01/10/17.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {

    // Vectors are template classes
    vector<double> numbers(0);

    cout << "Size: " << numbers.size() << ", bytes: " << sizeof(numbers) << endl;

    auto capacity = numbers.capacity();

    cout << "Capacity: " << capacity << endl;

    for(int i=0; i < 10000; i++){
        if (numbers.capacity() != capacity){
            capacity = numbers.capacity();
            cout << "New capacity: " << capacity << ", because exceeded size: " << numbers.size() << ", bytes: " << numbers.size() << endl;
        }
        numbers.emplace_back(i);
    }

    cout << "Final capacity: " << capacity << ", size: " << numbers.size() << ", bytes: " << numbers.size() << endl;

    return 0;
}