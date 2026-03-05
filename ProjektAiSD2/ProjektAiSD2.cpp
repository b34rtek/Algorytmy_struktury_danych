#include <iostream>
#include <cstdio>
#include "Structures.h"
#include "MinHeap.h"

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int width, height;
    Position startPos, endPos;

    if (scanf("%d %d", &width, &height) == EOF) return 0;
    scanf("%d %d", &startPos.x, &startPos.y);
    scanf("%d %d", &endPos.x, &endPos.y);

    int amount;
    scanf("%d", &amount);

    Field* map = new Field[height * width];
    Lift* lifts = new Lift[amount];

    for (int i = 0; i < amount; i++) {
        scanf("%d %d %d %d %d %d",
            &lifts[i].startPos.x, &lifts[i].startPos.y,
            &lifts[i].endPos.x, &lifts[i].endPos.y,
            &lifts[i].duration, &lifts[i].interval);

        int id = lifts[i].startPos.y * width + lifts[i].startPos.x;
        LiftNode* newNode = new LiftNode{ i, map[id].liftList };
        map[id].liftList = newNode;
    }

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int idx = row * width + col;
            scanf("%d", &map[idx].height);
            map[idx].x = col;
            map[idx].y = row;
        }
    }

    MinHeap heap;
    initHeap(heap, height * width);

    Field* startField = &map[startPos.y * width + startPos.x];
    startField->cost = 0;
    heapPush(heap, startField);

    while (heap.size > 0) {
        Field* current = heapPop(heap);
        if (current->visited) continue;
        current->visited = true;

        if (current->x == endPos.x && current->y == endPos.y) {
            printf("%d\n", current->cost);
            break;
        }

        const int dx[4] = { -1, 1, 0, 0 };
        const int dy[4] = { 0, 0, -1, 1 };

        for (int i = 0; i < 4; i++) {
            int nx = current->x + dx[i];
            int ny = current->y + dy[i];

            if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                Field* sasiad = &map[ny * width + nx];
                int travelCost = (sasiad->height > current->height) ?
                    (sasiad->height - current->height + 1) : 1;
                int newCost = current->cost + travelCost;

                if (newCost < sasiad->cost) {
                    sasiad->cost = newCost;
                    heapPush(heap, sasiad);
                }
            }
        }

        LiftNode* node = current->liftList;
        while (node != nullptr) {
            Lift& l = lifts[node->liftIndex];
            Field* dest = &map[l.endPos.y * width + l.endPos.x];

            int wait = (current->cost % l.interval == 0) ? 0 :
                (l.interval - (current->cost % l.interval));
            int arrive = current->cost + wait + l.duration;

            if (arrive < dest->cost) {
                dest->cost = arrive;
                heapPush(heap, dest);
            }
            node = node->next;
        }
    }

    cleanupHeap(heap);
    delete[] lifts;
    delete[] map;

    return 0;
}