//
// Created by dimchik on 02.11.2020.
//

#ifndef INC_3_SEM_MO_GENETIC_POPULATION_H
#define INC_3_SEM_MO_GENETIC_POPULATION_H

#include "Entity.h"
#include <vector>

using std::vector;

class Population {
    vector<Entity> entities;
    void cross_over();
public:
    double avg_fit();
    void to_next_generation();
};


#endif //INC_3_SEM_MO_GENETIC_POPULATION_H
