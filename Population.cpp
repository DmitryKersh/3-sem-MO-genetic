//
// Created by dimchik on 02.11.2020.
//

#include "Population.h"

double Population::avg_fit() {
    double res = 0;
    for (const auto& e : entities){
        res += e.fit_func();
    }
    return res / entities.size();
}