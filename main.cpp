//
// Created by dimchik on 02.11.2020.
//

#include <ctime>
#include "Population.h"




// random double in range
double rdir(Range r){
    // return r.min + ((r.max - r.min) * (static_cast<double>(rand()) / RAND_MAX));
    return uint_to_range(rand(), r);
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

    for (size_t i = 0; i < 100; i++){
        p.next_generation();
    }

    p.Print(std::cout);

    return 0;
}

