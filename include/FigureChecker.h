#pragma once

#include "FigureTypes.h"
#include "Area.h"

class FigureChecker {
    private:
        double m_err;

        static ProjectionsXY calcProjectionsXY(const Area &area);
        static double diffProjectionsXY(const ProjectionsXY &lprojs, const ProjectionsXY &rprojs);
        static double calcSqure(const Projection &proj);

    protected:
        double m_x;
        double m_y;
        double m_S;

        virtual void calcFigureParams(const ProjectionsXY projections) = 0;
        virtual ProjectionsXY genReferenceProjs() const = 0;

        static double calcCenterMass(const Projection &vec);
        static double calcAvgSqure(const ProjectionsXY &projs);

    public:
        double check(const Area &area);
        double getErr() const {return m_err;}
        virtual std::string getName() const = 0;
        virtual std::string getFigureDescription() const = 0;

        virtual ~FigureChecker() = default;
};
