//
// Created by ProtoBit on 26/11/2020.
//

#ifndef PHYSIM_GRAPH_CLASS_H
#define PHYSIM_GRAPH_CLASS_H


#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
namespace physim {
    class graphclass {
        std::map<double, double> map;
        const char *_file;

        static double lerp(double start, double end, double i);

        std::pair<double, double> get_bounds(double in);

    public:
        bool load(const char *file);

        bool reload();

        double getVal(double in);

        ~graphclass();
    };
}

#endif //PHYSIM_GRAPH_CLASS_H
