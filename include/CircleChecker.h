#pragma once

#include "FigureChecker.h"

#include <cmath>

class CircleChecker: public FigureChecker {
    private:
        double m_r;

        static constexpr double pi() { return std::atan(1) * 4; }
        static double circleIntegral(double r, double x);
        Projection genProjection(int len, int centre) const;

    protected:
        void calcFigureParams(const ProjectionsXY projections) override;
        ProjectionsXY genReferenceProjs() const override;

    public:
        std::string getName() const override {return std::string("круг");}
        std::string getFigureDescription() const override;

        ~CircleChecker() override = default;
};
