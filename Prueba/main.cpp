#include <iostream>
#include "Archivo1/math_utils.h"
#include "Archivo2/text_utils.h"

int main() {
    std::cout << "Addition: 5 + 3 = " << add(5, 3) << std::endl;
    std::cout << "Subtraction: 5 - 3 = " << subtract(5, 3) << std::endl;
    std::cout << "Concatenation: 'Hello' + ' World' = " << concatenate("Hello", " World") << std::endl;
    return 0;
}