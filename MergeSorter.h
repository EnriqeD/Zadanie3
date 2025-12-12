/**
 * @file MergeSorter.h
 * @brief Plik nag³ówkowy zawieraj¹cy deklaracjê klasy szablonowej MergeSorter.
 * * Plik ten definiuje interfejs klasy sortuj¹cej oraz strukturê metod prywatnych.
 * Ze wzglêdu na generycznoœæ (szablony), na koñcu pliku do³¹czana jest implementacja.
 */

#pragma once
#ifndef MERGESORTER_H
#define MERGESORTER_H

 /**
  * @class MergeSorter
  * @brief Klasa szablonowa realizuj¹ca algorytm sortowania przez scalanie (Merge Sort).
  * * Algorytm ten charakteryzuje siê z³o¿onoœci¹ czasow¹ O(n log n) w ka¿dym przypadku
  * (pesymistycznym, œrednim i optymistycznym) oraz stabilnoœci¹ sortowania.
  * * @tparam T Typ danych przechowywanych w tablicy. Typ T musi wspieraæ
  * operator porównania (<=).
  */
template <typename T>
class MergeSorter {
public:
    /**
     * @brief Publiczna metoda do sortowania tablicy.
     * * Inicjuje proces sortowania dla podanej tablicy. Jest to g³ówny punkt
     * dostêpu do funkcjonalnoœci klasy.
     * * @param array WskaŸnik do pierwszego elementu tablicy.
     * @param size Liczba elementów w tablicy.
     */
    void sort(T* array, int size);

private:
    /**
     * @brief Pomocnicza metoda rekurencyjna (dziel).
     * * Dzieli zakres tablicy na mniejsze fragmenty, a¿ do uzyskania tablic
     * jednoelementowych.
     * * @param array WskaŸnik do sortowanej tablicy.
     * @param left Indeks pocz¹tkowy bie¿¹cego zakresu.
     * @param right Indeks koñcowy bie¿¹cego zakresu.
     */
    void mergeSort(T* array, int left, int right);

    /**
     * @brief Pomocnicza metoda scalaj¹ca (zwyciê¿aj).
     * * £¹czy dwie posortowane podtablice w jedn¹ wiêksz¹, zachowuj¹c
     * kolejnoœæ elementów.
     * * @param array WskaŸnik do sortowanej tablicy.
     * @param left Indeks pocz¹tku lewej podtablicy.
     * @param mid Indeks koñcz¹cy lew¹ podtablicê (œrodek).
     * @param right Indeks koñcz¹cy praw¹ podtablicê.
     */
    void merge(T* array, int left, int mid, int right);
};

// WA¯NE: W przypadku szablonów, implementacja musi byæ widoczna dla kompilatora.
// Do³¹czamy plik z implementacj¹ na koñcu pliku nag³ówkowego.
#include "MergeSorter.cpp"

#endif // MERGESORTER_H