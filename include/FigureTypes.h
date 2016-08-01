#pragma once

#include <vector>
#include <map>
#include <string>
#include <iostream>

typedef std::vector<double> Projection;
typedef std::pair<std::vector<double>, std::vector<double>> ProjectionsXY;

std::ostream & operator<<(std::ostream &stream, const Projection &vec);
