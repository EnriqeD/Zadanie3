#pragma once
#ifndef MERGESORTER_H
#define MERGESORTER_H

template <typename T>
class MergeSorter {
public:
    // Deklaracja metody publicznej
    void sort(T* array, int size);

private:
    // Deklaracje metod prywatnych
    void mergeSort(T* array, int left, int right);
    void merge(T* array, int left, int mid, int right);
};

// WA¯NE: W przypadku szablonów, implementacja musi byæ widoczna dla kompilatora.
// Do³¹czamy plik z implementacj¹ na koñcu pliku nag³ówkowego.
#include "MergeSorter.cpp"

#endif