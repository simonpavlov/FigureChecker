#pragma once

#include <iostream>
#include <vector>

using std::vector;
using std::istream;
using std::ostream;

class Area : public vector<vector<char>> {
    public:
        const static int WIDTH;
        const static int HEIGHT;

        Area():
            vector<vector<char>>(HEIGHT, vector<char>(WIDTH))
        {}

        friend istream & operator>>(istream &stream, Area &area);
        friend ostream & operator<<(ostream &stream, const Area &area);
};
