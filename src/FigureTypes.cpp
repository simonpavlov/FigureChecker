#include "FigureTypes.h"

std::ostream & operator<<(std::ostream &stream, const Projection &vec) {
    stream << "[ ";
    for(auto i: vec) stream << i << " ";
    stream << "]";
    return stream;
}
