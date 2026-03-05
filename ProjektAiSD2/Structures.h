#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <climits>

struct Position {
    int x;
    int y;
};

struct Lift {
    Position startPos, endPos;
    int duration;
    int interval;
};

struct LiftNode {
    int liftIndex;
    LiftNode* next = nullptr;
};

struct Field {
    int x, y;
    int height;
    int cost = INT_MAX;
    LiftNode* liftList = nullptr;
    bool visited = false;
};

#endif