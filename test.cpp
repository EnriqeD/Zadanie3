#include "pch.h" // Wymagane w Visual Studio (precompiled header)
#include "C:\Users\henry\Desktop\Projekty Zaawansowane\Zadanie3\Zadanie3\MergeSorter.h"
#include <vector>
#include <algorithm> // Do std::sort (jako wzorzec)
#include <random>    // Do generowania losowych liczb

// Funkcja pomocnicza do weryfikacji poprawnoœci sortowania
// Przyjmuje wektor danych wejœciowych, kopiuje go do tablicy, sortuje i sprawdza wynik
template <typename T>
void verifySort(const std::vector<T>& inputData) {
    int size = inputData.size();

    // Przygotowanie danych dla MergeSorter (kopiowanie z vector do tablicy dynamicznej)
    T* arrayToSort = nullptr;
    if (size > 0) {
        arrayToSort = new T[size];
        for (int i = 0; i < size; i++) {
            arrayToSort[i] = inputData[i];
        }
    }

    // Przygotowanie danych oczekiwanych (u¿ywamy std::sort jako wyroczni)
    std::vector<T> expectedData = inputData;
    std::sort(expectedData.begin(), expectedData.end());

    // Uruchomienie Twojego algorytmu
    MergeSorter<T> sorter;
    sorter.sort(arrayToSort, size);

    // Asercje - sprawdzamy element po elemencie
    for (int i = 0; i < size; i++) {
        // ASSERT_EQ przerywa test w przypadku b³êdu, EXPECT_EQ kontynuuje
        EXPECT_EQ(expectedData[i], arrayToSort[i])
            << "Blad na indeksie " << i << " dla wartosci oczekiwanej " << expectedData[i];
    }

    // Sprz¹tanie
    if (size > 0) {
        delete[] arrayToSort;
    }
}

// --- 1. Tablica ju¿ posortowana rosn¹co ---
TEST(MergeSortTest, AlreadySorted) {
    std::vector<int> data = { 1, 2, 3, 4, 5, 10, 20 };
    verifySort(data);
}

// --- 2. Tablica posortowana odwrotnie ---
TEST(MergeSortTest, ReverseSorted) {
    std::vector<int> data = { 20, 10, 5, 4, 3, 2, 1 };
    verifySort(data);
}

// --- 3. Losowa tablica liczb ---
TEST(MergeSortTest, RandomArray) {
    std::vector<int> data = { 15, 3, 9, 8, 1, 22, 4 };
    verifySort(data);
}

// --- 4. Tablica tylko z liczbami ujemnymi ---
TEST(MergeSortTest, OnlyNegativeNumbers) {
    std::vector<int> data = { -5, -1, -10, -3, -50 };
    verifySort(data);
}

// --- 5. Tablica z liczbami ujemnymi i dodatnimi ---
TEST(MergeSortTest, MixedPositiveAndNegative) {
    std::vector<int> data = { -5, 10, -1, 3, 0, -10, 50 };
    verifySort(data);
}

// --- 6. Pusta tablica (nie powinna rzucaæ wyj¹tku) ---
TEST(MergeSortTest, EmptyArray) {
    std::vector<int> data = {};
    // Testujemy czy nie ma crasha (segmentation fault)
    verifySort(data);
}

// --- 7. Tablica z jednym elementem ---
TEST(MergeSortTest, SingleElement) {
    std::vector<int> data = { 42 };
    verifySort(data);
}

// --- 8. Tablica z duplikatami liczb ---
TEST(MergeSortTest, DuplicatesPositive) {
    std::vector<int> data = { 5, 1, 5, 2, 1, 3 };
    verifySort(data);
}

// --- 9. Tablica ujemna z duplikatami ---
TEST(MergeSortTest, DuplicatesNegative) {
    std::vector<int> data = { -5, -1, -5, -2, -1, -3 };
    verifySort(data);
}

// --- 10. Tablica ujemna, dodatnia i duplikaty ---
TEST(MergeSortTest, MixedDuplicates) {
    std::vector<int> data = { -5, 1, -5, 2, 0, 0, -1, 3, 1 };
    verifySort(data);
}

// --- 11. Tylko dwa elementy w kolejnoœci rosn¹cej ---
TEST(MergeSortTest, TwoElementsSorted) {
    std::vector<int> data = { 10, 20 };
    verifySort(data);
}

// --- 12. Du¿a tablica (>100 elementów) ---
TEST(MergeSortTest, LargeArrayInt) {
    std::vector<int> data;
    // Generowanie 150 elementów
    for (int i = 150; i > 0; --i) {
        data.push_back(i);
    }
    verifySort(data);
}

// --- 13. Du¿a tablica (>100 elementów) z liczbami ujemnymi, dodatnimi i duplikatami ---
TEST(MergeSortTest, LargeArrayComplex) {
    std::vector<double> data; // U¿ywamy double, ¿eby sprawdziæ te¿ inny typ danych

    // Generowanie danych pseudolosowych
    // U¿ywamy sta³ego seeda, ¿eby testy by³y powtarzalne
    std::mt19937 gen(42);
    std::uniform_real_distribution<> dis(-100.0, 100.0);

    for (int i = 0; i < 200; i++) {
        data.push_back(dis(gen));
    }

    data.push_back(50.5);
    data.push_back(50.5);
    data.push_back(-20.1);
    data.push_back(-20.1);

    verifySort(data);
}
