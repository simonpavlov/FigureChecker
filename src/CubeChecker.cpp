#include "CubeChecker.h"

#include <cmath>
#include <sstream>

using std::sqrt;
using std::stringstream;
using std::round;
using std::move;


void CubeChecker::calcFigureParams(const ProjectionsXY projs) {
    m_S = calcAvgSqure(projs);
    m_h = round(sqrt(m_S));
    m_x = round(calcCenterMass(projs.first) - m_h / 2 + 0.5);
    m_y = round(calcCenterMass(projs.second) - m_h / 2 + 0.5);
}


ProjectionsXY CubeChecker::genReferenceProjs() const {
    Projection proj_x(Area::WIDTH);
    for(int i = m_x; i < m_x + m_h; i++) {
        proj_x[i] = m_h;
    }

    Projection proj_y(Area::HEIGHT);
    for(int i = m_y; i < m_y + m_h; i++) {
        proj_y[i] = m_h;
    }

    return make_pair(move(proj_x), move(proj_y));
}


std::string CubeChecker::getFigureDescription() const {
    stringstream descr;
    descr << "длинна стороны: " << m_h << ", "
        << "координаты левого верхнего угла: (" << m_x << ", " << m_y << ")";
    return descr.str();
}
