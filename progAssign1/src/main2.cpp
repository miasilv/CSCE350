// Copyright Amelia Silver (2023)

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "../inc/quickSort.h"

using namespace std;

int main() {
    fstream infile("./dat/input.txt");
    if (!infile) {
        cout << "Error: Cannot find File" << endl;
        return 1;
    }

    string line;
    getline(infile, line);
    vector<float> arr;
    size_t i = line.find_first_of(" ");
    while (line.size() > 0 && i != string::npos) {
        arr.push_back(stof(line.substr(0, i)));
        line.erase(0, i + 1);
        i = line.find_first_of(" ");
    }
    if (!line.empty()) { arr.push_back(stof(line)); }

    int duration = sorter::quickSort(arr, 0, arr.size() - 1);

    ofstream outfile("./dat/output.txt");
    if (!outfile) {
        cout << "Error: Cannot create file" << endl;
        return 1;
    }
    for (float x : arr) { outfile << x << " "; }
    outfile << "\nExecution Time of Quicksort: " << duration;
    if (arr.size() <= 500)
        outfile << " nanoseconds." << endl;
    else
        outfile << " microseconds." << endl;
    outfile.close();

    return 0;
}
