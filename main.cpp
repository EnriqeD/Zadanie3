#include <iostream>
#include "MergeSorter.h" 

template <typename T>
void printArray(T* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // --- Test INT ---
    std::cout << "--- Test dla typu INT ---" << std::endl;
    int tabInt[] = { 38, 27, 43, 3, 9, 82, 10 };
    int sizeInt = sizeof(tabInt) / sizeof(tabInt[0]);

    std::cout << "Przed: ";
    printArray(tabInt, sizeInt);

    MergeSorter<int> sorterInt;
    sorterInt.sort(tabInt, sizeInt);

    std::cout << "Po:    ";
    printArray(tabInt, sizeInt);
    std::cout << std::endl;

    // --- Test DOUBLE ---
    std::cout << "--- Test dla typu DOUBLE ---" << std::endl;
    double tabDouble[] = { 3.14, 1.41, 2.71, 0.58, 1.73, 0.99 };
    int sizeDouble = sizeof(tabDouble) / sizeof(tabDouble[0]);

    std::cout << "Przed: ";
    printArray(tabDouble, sizeDouble);

    MergeSorter<double> sorterDouble;
    sorterDouble.sort(tabDouble, sizeDouble);

    std::cout << "Po:    ";
    printArray(tabDouble, sizeDouble);

    return 0;
}