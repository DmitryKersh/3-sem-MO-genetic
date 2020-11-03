//
// Created by dimchik on 02.11.2020.
//

#include "Population.h"
#include <algorithm>

double Population::avg_fit() {
    double res = 0;
    for (const auto& e : entities){
        res += e.fit_func();
    }
    return res / entities.size();
}

void Population::Print(std::ostream &os) {
    os << "AVG FIT = " << avg_fit() << endl;
    for (size_t i = 0; i < entities.size(); i++){
        os << "Entity #" << i + 1 << endl
           << "X = " << entities[i].get_x() << endl
           << "Y = " << entities[i].get_y() << endl
           << "Fit = " << entities[i].fit_func() << endl << endl;
    }
}

Entity Population::cross_over(size_t first, size_t second) {
    return { entities[first].get_x(), entities[second].get_y() };
}

void Population::next_generation() {
    std::sort(entities.rbegin(), entities.rend());
    vector<Entity> new_gen(4);
    new_gen[0] = cross_over(0, 1);
    new_gen[1] = cross_over(0, 2);
    new_gen[2] = cross_over(1, 0);
    new_gen[3] = cross_over(2, 0);

    // mutation

    for (auto & e : new_gen){
        if (rand() % 8 == 0) {
            e.mutate();
        }
    }

    entities = new_gen;
}
