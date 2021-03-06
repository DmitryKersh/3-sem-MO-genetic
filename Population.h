//
// Created by dimchik on 02.11.2020.
//

#ifndef INC_3_SEM_MO_GENETIC_POPULATION_H
#define INC_3_SEM_MO_GENETIC_POPULATION_H

#include "Entity.h"
#include <vector>
#include <iostream>

using std::vector;
using std::endl;

class Population {
    Range range_x;
    Range range_y;
    vector<Entity> entities;
    double mutation_chance;
    Entity cross_over(size_t first, size_t second) const;
public:
    Population(const vector<Entity>& data, double mc, const Range rx, const Range& ry)
    : entities(data), mutation_chance(mc), range_x(rx), range_y(ry) {}
    double avg_fit() const;

    void next_generation();
    void Print(std::ostream& os, const std::string& desc) const;
};

#endif //INC_3_SEM_MO_GENETIC_POPULATION_H
