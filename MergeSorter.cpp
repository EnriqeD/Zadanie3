/**
 * @file MergeSorter.cpp
 * @brief Implementacja metod klasy szablonowej MergeSorter.
 * * Ten plik zawiera definicje metod odpowiedzialnych za algorytm sortowania przez scalanie.
 * Ze wzglêdu na u¿ycie szablonów, plik ten jest zazwyczaj do³¹czany na koñcu
 * pliku nag³ówkowego MergeSorter.h.
 */

#ifndef MERGESORTER_CPP
#define MERGESORTER_CPP

#include "MergeSorter.h" // Dla widocznoœci definicji klasy (dla IDE)

 /**
  * @brief Publiczna metoda rozpoczynaj¹ca proces sortowania.
  * * Jest to punkt wejœcia dla u¿ytkownika klasy. Metoda sprawdza, czy tablica
  * wymaga sortowania (rozmiar > 1), a nastêpnie wywo³uje rekurencyjn¹
  * metodê pomocnicz¹ mergeSort dla ca³ego zakresu tablicy.
  * * @tparam T Typ danych przechowywanych w tablicy (musi obs³ugiwaæ operator porównania <=).
  * @param array WskaŸnik do tablicy, która ma zostaæ posortowana.
  * @param size Liczba elementów w tablicy.
  */
template <typename T>
void MergeSorter<T>::sort(T* array, int size) {
    if (size > 1) {
        mergeSort(array, 0, size - 1);
    }
}

/**
 * @brief Rekurencyjna funkcja dziel¹ca tablicê na podproblemy.
 * * Metoda realizuje strategiê "dziel i zwyciê¿aj" (divide and conquer).
 * Dzieli zakres tablicy na dwie po³owy, wywo³uje siê rekurencyjnie dla ka¿dej z nich,
 * a nastêpnie scala posortowane po³ówki.
 * * @tparam T Typ danych w tablicy.
 * @param array WskaŸnik do sortowanej tablicy.
 * @param left Indeks pocz¹tku bie¿¹cego fragmentu tablicy.
 * @param right Indeks koñca bie¿¹cego fragmentu tablicy.
 */
template <typename T>
void MergeSorter<T>::mergeSort(T* array, int left, int right) {
    if (left < right) {
        // Obliczenie œrodka w sposób bezpieczny dla przepe³nienia (overflow)
        int mid = left + (right - left) / 2;

        // Sortowanie lewej po³owy
        mergeSort(array, left, mid);
        // Sortowanie prawej po³owy
        mergeSort(array, mid + 1, right);

        // Scalanie posortowanych po³ów
        merge(array, left, mid, right);
    }
}

/**
 * @brief Scala dwie posortowane podtablice w jedn¹.
 * * Funkcja tworzy tymczasowe tablice pomocnicze dla lewej i prawej czêœci,
 * kopiuje do nich dane, a nastêpnie nadpisuje oryginaln¹ tablicê, uk³adaj¹c
 * elementy w kolejnoœci rosn¹cej.
 * * @details
 * Z³o¿onoœæ czasowa tej operacji to O(n), gdzie n to d³ugoœæ scalanych fragmentów.
 * Funkcja alokuje pamiêæ dynamiczn¹, która jest zwalniana przed zakoñczeniem funkcji.
 * * @tparam T Typ danych w tablicy.
 * @param array WskaŸnik do g³ównej tablicy.
 * @param left Indeks pocz¹tkowy lewej podtablicy.
 * @param mid Indeks koñcowy lewej podtablicy (œrodek).
 * @param right Indeks koñcowy prawej podtablicy.
 */
template <typename T>
void MergeSorter<T>::merge(T* array, int left, int mid, int right) {
    int n1 = mid - left + 1; // Rozmiar lewej podtablicy
    int n2 = right - mid;    // Rozmiar prawej podtablicy

    // Alokacja pamiêci dla tablic pomocniczych
    T* L = new T[n1];
    T* R = new T[n2];

    // Kopiowanie danych do tablic pomocniczych L[] i R[]
    for (int i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    int i = 0; // Indeks pocz¹tkowy pierwszej podtablicy
    int j = 0; // Indeks pocz¹tkowy drugiej podtablicy
    int k = left; // Indeks pocz¹tkowy scalonej podtablicy

    // W³aœciwe scalanie: porównywanie elementów i wstawianie mniejszego
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        }
        else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Kopiowanie pozosta³ych elementów z L[], jeœli istniej¹
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Kopiowanie pozosta³ych elementów z R[], jeœli istniej¹
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    // Zwolnienie pamiêci dynamicznej
    delete[] L;
    delete[] R;
}

#endif