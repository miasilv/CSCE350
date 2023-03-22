// Copyright Amelia Silver (2023)

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

#include "../inc/findTop.h"

using namespace std;
using namespace std::chrono;

int main() {
    fstream infile("dat/input.txt");
    if (!infile) {
        cout << "Error: Cannot find File" << endl;
        return 1;
    }

    vector<vector<bool>> adjMatrix;
    string line;
    while (getline(infile, line)) {
        vector<bool> row;
        size_t i = line.find_first_of(" ");
        while (line.size() > 0 && i != string::npos) {
            bool value = true;
            if (line.substr(0, i).compare("0") == 0)
                value = false;
            row.push_back(value);
            line.erase(0, i + 1);
            i = line.find_first_of(" ");
        }

        if (!line.empty()) {
            bool value = true;
            if (line.compare("0") == 0)
                value = false;
            row.push_back(value);
        }

        adjMatrix.push_back(row);
    }

    ofstream outfile("dat/output.txt");
    if (!outfile) {
        cout << "Error: Cannot create file" << endl;
        return 1;
    }

    auto start = high_resolution_clock::now();
    if (findTop::isFullyConnected(adjMatrix)) {
        auto stop = high_resolution_clock::now();
        int duration = duration_cast<microseconds>(stop - start).count();
        outfile << "The Adjacency Matrix is a "
                << "Fully-Completed topology." << endl;
        outfile << "The execution time was " << duration << " microseconds.";

    } else if (findTop::isStar(adjMatrix)) {
        auto stop = high_resolution_clock::now();
        int duration = duration_cast<microseconds>(stop - start).count();
        outfile << "The Adjacency Matrix is a Star topology." << endl;
        outfile << "The execution time was " << duration << " microseconds.";

    } else if (findTop::isRing(adjMatrix)) {
        auto stop = high_resolution_clock::now();
        int duration = duration_cast<microseconds>(stop - start).count();
        outfile << "The Adjacency Matrix is a Ring topology." << endl;
        outfile << "The execution time was " << duration << " microseconds.";

    } else {
        auto stop = high_resolution_clock::now();
        int duration = duration_cast<microseconds>(stop - start).count();
        outfile << "The Adjacency Matrix is not a fully-completed, "
                << "star, or ring topology." << endl;
        outfile << "The execution time was " << duration << " microseconds.";
    }

    outfile.close();
    return 0;
}
