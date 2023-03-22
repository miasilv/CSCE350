// Copyright Amelia Silver (2023)

#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "../inc/quickSort.h"

using namespace std;

int main() {
    vector<size_t> sizes = {10, 100, 1000, 10000, 100000};
    vector<float> aveDurations;
    int sizesSize = sizes.size();
    for (int i = 0; i < sizesSize; i++) {
        vector<int> durations;
        for (int j = 0; j < 100; j++) {
            random_device rand;
            mt19937 gen(rand());
            float arrSize = sizes[i];
            uniform_real_distribution dis(-arrSize, arrSize);

            vector<float> arr;
            for (int k = 0; k < arrSize; k++) {
                arr.push_back(dis(gen));
            }
            durations.push_back(sorter::quickSort(arr, 0, arr.size() - 1));
        }
        int sum = 0;
        for (auto x : durations) {
            sum += x;
        }
        aveDurations.push_back(static_cast<double>(sum)
                            / static_cast<double>(durations.size()));
    }

    ofstream outfile("./dat/output.txt");
    if (!outfile) {
        cout << "Error: Cannot create file" << endl;
        return 1;
    }
    int aveSize = aveDurations.size();
    for (int i = 0; i < aveSize && i < sizesSize; i++) {
        outfile << "The average execution time of quicksort for an array of size "
        << sizes[i] << " is " << aveDurations[i];

        if (sizes[i] <= 500)
            outfile << " nanoseconds." << endl;
        else
            outfile << " microseconds." << endl;
    }
    outfile.close();

    return 0;
}
