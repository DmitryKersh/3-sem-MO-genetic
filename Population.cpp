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

void Population::Print(std::ostream &os) {
    for (size_t i = 0; i < entities.size(); i++){
        os << "Entity #" << i + 1 << endl
           << "X = " << entities[i].get_x() << endl
           << "Y = " << entities[i].get_y() << endl
           << "Fit = " << entities[i].fit_func() << endl << endl;
    }
}