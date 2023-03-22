// Copyright Amelia Silver (2023)

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

#include "../inc/quickSort.h"

using namespace std;
using namespace std::chrono;

int sorter::partition(vector<float> & arr, int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    float temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void sorter::quickSortR(vector<float> & arr, int low, int high) {
    if (low >= high) {  // halting condition
        return;
    }

    int pivot = partition(arr, low, high);
    quickSortR(arr, low, pivot - 1);
    quickSortR(arr, pivot + 1, high);
}

int sorter::quickSort(vector<float> & arr, int low, int high) {
    auto start = high_resolution_clock::now();
    quickSortR(arr, low, high);
    auto stop = high_resolution_clock::now();

    if (arr.size() <= 500)
        return (duration_cast<nanoseconds>(stop - start).count());

    return (duration_cast<microseconds>(stop - start).count());
}
