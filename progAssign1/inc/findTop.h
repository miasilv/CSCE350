// Copyright Amelia Silver (2023)

#ifndef PROGASSIGN1_INC_FINDTOP_H_
#define PROGASSIGN1_INC_FINDTOP_H_

#include <vector>

using std::vector;

class findTop {
 public:
    static bool isFullyConnected(vector<vector<bool>> adjMatrix);
    static bool isRing(vector<vector<bool>> adjMatrix);
    static bool isStar(vector<vector<bool>> adjMatrix);
};

#endif  // PROGASSIGN1_INC_FINDTOP_H_
