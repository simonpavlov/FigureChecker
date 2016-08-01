#include "FigureChecker.h"

#include <iostream>
#include <cmath>

#define DEBUG 0

using std::ostream;
using std::make_pair;
using std::abs;
using std::max;


double FigureChecker::check(const Area &area) {
    DEBUG && std::cout << "IN FigureChecker::check" << std::endl;

    DEBUG && std::cout << ">>> calcProjectionsXY" << std::endl;
    auto projections = calcProjectionsXY(area);
    DEBUG && std::cout << "ORIGINAL x projection:  " << projections.first << std::endl;
    DEBUG && std::cout << "ORIGINAL y projection:  " << projections.second << std::endl;

    DEBUG && std::cout << ">>> calcFigureParams" << std::endl;
    calcFigureParams(projections);

    DEBUG && std::cout << ">>> genReferenceProjs" << std::endl;
    auto refProjectionsXY = genReferenceProjs();
    DEBUG && std::cout << "REFERENCE x projection: " << refProjectionsXY.first << std::endl;
    DEBUG && std::cout << "REFERENCE y projection: " << refProjectionsXY.second << std::endl;

    DEBUG && std::cout << ">>> diffProjectionsXY" << std::endl;
    int diff = diffProjectionsXY(projections, refProjectionsXY);

    DEBUG && std::cout << ">>> calcErr" << std::endl;
    m_err = diff / (m_S * 2.0);

    return m_err;
}


ProjectionsXY FigureChecker::calcProjectionsXY(const Area &area) {
    auto projections = make_pair(Projection(Area::WIDTH), Projection(Area::HEIGHT));

    for(int y = 0; y < Area::HEIGHT; y++) {
        for(int x = 0; x < Area::WIDTH; x++) {
            projections.first[x] += area[y][x];
            projections.second[y] += area[y][x];
        }
    }

    return projections;
}


double FigureChecker::diffProjectionsXY(const ProjectionsXY &lprojs, const ProjectionsXY &rprojs) {
    double err = 0;
    for(int x = 0; x < Area::WIDTH; x++) {
        err += abs(lprojs.first[x] - rprojs.first[x]);
    }
    for(int y = 0; y < Area::HEIGHT; y++) {
        err += abs(lprojs.second[y] - rprojs.second[y]);
    }
    return err;
}


double FigureChecker::calcCenterMass(const Projection &vec) {
    double centerMass = 0;
    int mass = 0;
    for(size_t i = 0; i < vec.size(); i++) {
        centerMass += i * vec[i];
        mass += vec[i];
    }
    centerMass /= mass;

    return centerMass;
}


double FigureChecker::calcSqure(const Projection &proj) {
    double S = 0;
    double s = 0;
    for(size_t i = 0; i < proj.size(); i++) {
        s += proj[i];
        if(proj[i] == 0) {
            S = max(S, s);
            s = 0;
        }
    }
    return max(S, s);
}


double FigureChecker::calcAvgSqure(const ProjectionsXY &projs) {
    double S = (calcSqure(projs.first) + calcSqure(projs.second)) / 2.0;
    return S;
}
