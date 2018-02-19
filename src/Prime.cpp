#include <iostream>
#include "PrimeChecker.hpp"
int main(int /*argc*/, char** /*argv*/) {
    PrimeChecker pc;
    std::cout << "Hello World = " << pc.isPrime(43) << std::endl;
    return 0;
}
