#pragma once

#include "FigureChecker.h"

class CubeChecker: public FigureChecker {
    private:
        double m_h;

    protected:
        void calcFigureParams(const ProjectionsXY projections) override;
        ProjectionsXY genReferenceProjs() const override;

    public:
        std::string getName() const override {return std::string("квадрат");}
        std::string getFigureDescription() const override;

        ~CubeChecker() override = default;
};
