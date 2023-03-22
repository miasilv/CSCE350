// Copyright Amelia Silver (2023)

#include <vector>

#include "../inc/findTop.h"

using std::vector;

bool findTop::isFullyConnected(vector<vector<bool>> adjMatrix) {
    int n = adjMatrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // checking all values besides diagonal are 1
            if (i != j && adjMatrix[i][j] != true)
                return false;
            // checking all values on diagonal are 0
            if (i == j && adjMatrix[i][j] != false)
                return false;
        }
    }
    return true;
}

bool findTop::isRing(vector<vector<bool>> adjMatrix) {
    int n = adjMatrix.size();

    // scan each row to verify it has two 1's
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (adjMatrix[i][j] == true)
                count++;
            if (i == j && adjMatrix[i][j] != false)
                return false;
        }
        if (count != 2)
            return false;
    }
    return true;
}

bool findTop::isStar(vector<vector<bool>> adjMatrix) {
    int n = adjMatrix.size();
    int countFull = 0;
    int countSingle = 0;

    // counts how many rows have 1 truth value
    // and how many have 1 false value
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i == j && adjMatrix[i][j] != false)
                return false;
            if (adjMatrix[i][j] == true)
                count++;
        }
        if (count == 1)
            countSingle++;
        if (count == n - 1)
            countFull++;
    }
    // if the number of rows full is not 1 or
    // the number of rows empty besides 1 is
    // not n -1, it is not a star
    if (countSingle != n - 1 && countFull != 1)
        return false;
    return true;
}
