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

    size_t population_size, gen_count;
    double mutation_chance;
    char config;

    std::cout << "Enter population size (positive int)" << endl;
    std::cin >> population_size;
    std::cout << "Enter mutation chance (float in [0;1])" << endl;
    std::cin >> mutation_chance;
    std::cout << "Enter number of generations (positive int)" << endl;
    std::cin >> gen_count;
    std::cout << "Enter 'y' to show all generations, else only first and last will be shown" << endl;
    std::cin >> config;

    if (population_size > 10000 || mutation_chance > 1.0 || mutation_chance < 0.0 || gen_count > 10000){
        throw std::runtime_error("Incorrect input. Entered: \nPopulation size = "
                                 + std::to_string(population_size)
                                 + "\nMutation chance = "
                                 + std::to_string(mutation_chance)
                                 + "\nNumber of generations = "
                                 + std::to_string(gen_count));
    }

    try {
        Population p(random_entities(population_size, range_x, range_y), mutation_chance);
        if (config == 'y'){ // TO SHOW ALL GENERATIONS
            for (size_t i = 0; i < gen_count; i++) {
                p.next_generation();
                p.Print(std::cout, "GEN #" + std::to_string(i));
            }
        } else {  // TO SHOW ONLY FIRST AND LAST
            p.Print(std::cout, "GEN #0");
            for (size_t i = 0; i < gen_count; i++) {
                p.next_generation();
            }
            p.Print(std::cout, "GEN #" + std::to_string(gen_count));
        }
    }
    catch (std::runtime_error& e) {
        std::cerr << e.what();
        return 1;
    }

    return 0;
}

