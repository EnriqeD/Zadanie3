/**
 * @file main.cpp
 * @brief Plik główny (entry point) programu testującego algorytm Merge Sort.
 * * Plik ten zawiera funkcję main, która demonstruje działanie klasy MergeSorter
 * na dwóch różnych typach danych: liczbach całkowitych (int) oraz
 * liczbach zmiennoprzecinkowych (double).
 */

#include <iostream>
#include "MergeSorter.h" 

 /**
  * @brief Pomocnicza funkcja szablonowa do wyświetlania zawartości tablicy.
  * * Wypisuje elementy tablicy na standardowe wyjście (std::cout), oddzielając
  * je spacjami i kończąc nową linią.
  * * @tparam T Typ danych w tablicy. Typ ten musi obsługiwać operator
  * przesunięcia bitowego w lewo (<<) dla strumienia wyjściowego.
  * @param array Wskaźnik do tablicy, która ma zostać wyświetlona.
  * @param size Liczba elementów w tablicy.
  */
template <typename T>
void printArray(T* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Główna funkcja programu.
 * * Realizuje następujący scenariusz testowy:
 * 1. Tworzy i inicjalizuje tablicę liczb całkowitych (int).
 * 2. Sortuje ją przy użyciu instancji MergeSorter<int>.
 * 3. Tworzy i inicjalizuje tablicę liczb zmiennoprzecinkowych (double).
 * 4. Sortuje ją przy użyciu instancji MergeSorter<double>.
 * * Wyniki przed i po sortowaniu są wypisywane na konsolę w celu weryfikacji.
 * * @return Zwraca 0, jeśli program zakończył się poprawnie.
 */
int main() {
    // --- Test INT ---
    std::cout << "--- Test dla typu INT ---" << std::endl;
    int tabInt[] = { 38, 27, 43, 3, 9, 82, 10 };
    int sizeInt = sizeof(tabInt) / sizeof(tabInt[0]);

    std::cout << "Przed: ";
    printArray(tabInt, sizeInt);

    // Utworzenie instancji i sortowanie
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

    // Utworzenie instancji i sortowanie
    MergeSorter<double> sorterDouble;
    sorterDouble.sort(tabDouble, sizeDouble);

    std::cout << "Po:    ";
    printArray(tabDouble, sizeDouble);

    return 0;
}