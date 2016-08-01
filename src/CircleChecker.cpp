#include "CircleChecker.h"

#include <algorithm>
#include <cmath>
#include <sstream>

#define DEBUG 0

using std::max_element;
using std::sqrt;
using std::atan;
using std::abs;
using std::floor;
using std::ceil;
using std::move;
using std::min;
using std::max;
using std::stringstream;


void CircleChecker::calcFigureParams(const ProjectionsXY projs) {
    m_x = round(calcCenterMass(projs.first) * 2) / 2;
    m_y = round(calcCenterMass(projs.second) * 2) / 2;
    m_S = calcAvgSqure(projs);
    m_r = sqrt(m_S / pi());
}


double CircleChecker::circleIntegral(double r, double x) {
    if(abs(x) > r) {
        if(x < 0) x = -r;
        else x = r;
    }

    double S = 0;

    double st = sqrt(r*r - x*x);
    S = x * st + r*r * atan(x / st);

    return S;
}


Projection CircleChecker::genProjection(int len, int centre) const {
    Projection proj(len);

    int begin = max(int(floor(centre - m_r)), 0);
    int end = min(int(ceil(centre + m_r)), len);
    double integr = circleIntegral(m_r, begin - 0.5 - centre);
    for(int i = begin; i < end; i++)
    {
        DEBUG && (i < 0) && std::cout << "!!! i < 0 !!!" << std::endl;
        DEBUG && (i > len) && std::cout << "!!! i > len !!!" << std::endl;
        double newIntegr = circleIntegral(m_r, i + 0.5 - centre);
        double inc = newIntegr - integr;
        proj[i] = inc;
        integr = newIntegr;
    }

    return proj;
}


ProjectionsXY CircleChecker::genReferenceProjs() const {
    DEBUG && std::cout << "IN CircleChecker::genReferenceProjs" << std::endl;

    auto projs = make_pair(
            genProjection(Area::WIDTH, m_x),
            genProjection(Area::WIDTH, m_y)
            );

    return projs;
}


std::string CircleChecker::getFigureDescription() const {
    stringstream descr;
    descr << "диаметр: " << round(m_r * 2) << ", "
        << "координаты центра: (" << m_x << ", " << m_y << ")";
    return descr.str();
}
