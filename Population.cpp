//
// Created by dimchik on 02.11.2020.
//

#include "Population.h"
#include <algorithm>

double Population::avg_fit() const {
    double res = 0;
    for (const auto& e : entities){
        res += e.fit_func();
    }
    return res / entities.size();
}

void Population::Print(std::ostream &os, const std::string& description) const{
    os << description << endl;
    os << "AVG FIT = " << avg_fit() << endl;
    for (size_t i = 0; i < entities.size(); i++){
        os << "Entity #" << i + 1
           << ": [ X = " << entities[i].get_x()
           << " Y = " << entities[i].get_y()
           << " Fit = " << entities[i].fit_func() << " ]" << endl;
    }
    os << endl;
}

Entity Population::cross_over(size_t first, size_t second) const {
    return { entities[first].get_x(), entities[second].get_y() };
}

void Population::next_generation() {
    std::sort(entities.rbegin(), entities.rend());
    vector<Entity> new_gen;

    size_t selection_size = ceil((1.0 + sqrt(1.0 + 4.0 * entities.size())) / 2.0);
    //std::cerr << selection_size << "'";


    for (size_t i = 0; i < selection_size; i++){
        for (size_t j = i + 1; j < selection_size; j++){
            new_gen.push_back(cross_over(i, j));
            new_gen.push_back(cross_over(j, i));
        }
    }

    // mutation

    for (auto & e : new_gen){
        if (rand() < RAND_MAX * mutation_chance) {
            e.mutate(range_x, range_y);
        }
    }

    std::sort(new_gen.rbegin(), new_gen.rend());
    new_gen.resize(entities.size());
    entities = new_gen;
}
