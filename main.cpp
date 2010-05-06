#include <iostream>
#include "Image.h"
#include "Test.h"

int main (int argc, char * const argv[]) {
    ShadeKit::Vector3 v(1.0, 2.0, 3.0);
    std::cout << v << "\n";
    
    ShadeKit::Test::runAll();
    
    return 0;
}
