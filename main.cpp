//
// Created by dimchik on 02.11.2020.
//

#include <cmath>
#include <ctime>
#include "Population.h"

struct Range {
    double min;
    double max;
};


// random double in range
double rdir(Range r){
    return r.min + ((r.max - r.min) * (static_cast<double>(rand()) / RAND_MAX));
}

vector<Entity> random_entities(size_t size, Range range_x, Range range_y){
    vector<Entity> res(size);

    for (auto & e : res){
        e = Entity(rdir(range_x), rdir(range_y));
    }

    return res;
}



int main() {
    srand(time(0));
    Range range_x = {0.0, 2.0};
    Range range_y = {-2.0, 2.0};


    Population p(random_entities(4, range_x, range_y));

    p.Print(std::cout);

    return 0;
}

