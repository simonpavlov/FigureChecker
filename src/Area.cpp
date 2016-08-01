#include "Area.h"

const int Area::WIDTH = 15;
const int Area::HEIGHT = 15;


istream & operator>>(istream &stream, Area &area){
    for( int y = 0; y < Area::WIDTH; y++ ) {
        for( int x = 0; x < Area::HEIGHT; x++) {
            char c;
            stream >> c;
            area[y][x] = c - '0';
        }
    }

    return stream;
}


ostream & operator<<(ostream &stream, const Area &area){
    for( int y = 0; y < Area::WIDTH; y++ ) {
        for( int x = 0; x < Area::HEIGHT; x++) {
            stream << (area[y][x]? '#' : '.') << " ";
        }
        stream << std::endl;
    }

    return stream;
}
