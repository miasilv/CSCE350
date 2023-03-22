// Copright Amelia Silver (2023)

#ifndef PROGASSIGN1_INC_QUICKSORT_H_
#define PROGASSIGN1_INC_QUICKSORT_H_

#include <vector>

using std::vector;

class sorter {
 public:
    static int quickSort(vector<float> & arr, int low, int high);

 private:
    static int partition(vector<float> & arr, int low, int high);
    static void quickSortR(vector<float> & arr, int low, int high);
};

#endif  // PROGASSIGN1_INC_QUICKSORT_H_
