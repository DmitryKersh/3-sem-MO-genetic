//
// Created by dimchik on 02.11.2020.
//

#ifndef INC_3_SEM_MO_GENETIC_ENTITY_H
#define INC_3_SEM_MO_GENETIC_ENTITY_H

#include <cstdint>

typedef uint32_t uint;

#include <cmath>
#include <cstdint>

struct Range {
    double min;
    double max;
};


class Entity {
    double _x;
    double _y;
public:
    Entity() : _x(0.0), _y(0.0) {}
    Entity(double x, double y) : _x(x), _y(y) {}

    double fit_func() const;

    double get_x() const;
    double get_y() const;

    void mutate(const Range& range_x, const Range& range_y);
};

bool operator< (const Entity& lhs, const Entity& rhs);

double uint_to_range(uint u, Range r);
uint range_to_uint(double d, Range r);


#endif //INC_3_SEM_MO_GENETIC_ENTITY_H
