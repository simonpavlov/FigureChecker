#pragma once

#include "Area.h"

class Filter {
    private:
        int compAround(const Area &area, int x, int y);

    public:
        Area filterate(const Area &area);
};
