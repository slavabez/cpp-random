//
// Created by slava on 01/10/17.
//

#include <iostream>
#include <iomanip>


int main(){

    unsigned char red = 0xAA;
    unsigned char green = 0xBB;
    unsigned char blue = 0xCC;
    unsigned char alpha = 0xDD;

    unsigned int color;

    color += red;
    color <<= 8;
    color += green;
    color <<= 8;
    color += blue;
    color <<= 4;
    color += alpha;

    std::cout << std::setw(8) << std::hex << color << std::endl;

    return 0;
}