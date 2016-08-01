#include "Filter.h"

#include <iostream>

#define DEBUG 0

using std::max;
using std::min;

int Filter::compAround(const Area &area, int x, int y) {
    int sum = -1;
    int value = area[y][x];

    for(int j = max(y - 1, 0); j <= min(y + 1, Area::WIDTH - 1); j++) {
        for(int i = max(x - 1, 0); i <= min(x + 1, Area::HEIGHT - 1); i++) {
            if(area[j][i] == value) sum++;
        }
    }

    return sum;
}

Area Filter::filterate(const Area &area) {
    Area filtredArea = area;

    for(int y = 0; y < Area::HEIGHT; y++) {
        for(int x = 0; x < Area::WIDTH; x++) {
            int comp = compAround(filtredArea, x, y);
            DEBUG && (comp <= 1) && std::cout << "(x, y): (" << x << ", " << y << ") comp: " << comp << std::endl;
            if(comp <= 1) filtredArea[y][x] = (filtredArea[y][x] + 1) % 2;
        }
    }

    return filtredArea;
}
