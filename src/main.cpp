#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "Area.h"
#include "Filter.h"
#include "CircleChecker.h"
#include "CubeChecker.h"

#define DEBUG 0

using namespace std;

int main(int, char *[]) {
    Area area;
    Area filtredArea;
    Filter filter;

    vector<FigureChecker *> checkers;

    checkers.push_back(new CircleChecker);
    checkers.push_back(new CubeChecker);

    cin >> area;
    filtredArea = filter.filterate(area);
    DEBUG && cout << "Input data:" << endl << filtredArea;

    FigureChecker *checker = *min_element(checkers.begin(), checkers.end(),
            [filtredArea](FigureChecker *l, FigureChecker *r)
            {return l->check(filtredArea) < r->check(filtredArea);}
    );

    DEBUG && cout << "Find OK" << endl;
    if(checker->getErr() < 0.1) {
        cout << checker->getName() << endl;
        cout << "ошибка: " << setprecision(3) << checker->getErr() * 100 << "%" << endl;
        cout << "описание: \"" << checker->getFigureDescription() << "\"" << endl;
    }
    else {
        cout << "неизвестная фигура" << endl;
    }

    for(auto it = checkers.begin(); it != checkers.end(); delete *it++);

    return 0;
}
