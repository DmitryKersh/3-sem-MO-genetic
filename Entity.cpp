//
// Created by dimchik on 02.11.2020.
//

#include "Entity.h"

double Entity::fit_func() const {
    return sin(_x) * sin(_y) / (1 + _x * _x + _y * _y);
}

double Entity::get_x() const {
    return _x;
}

double Entity::get_y() const {
    return _y;
}

void Entity::mutate() {
    _x = uint_to_range(range_to_uint(_x, {-2.0, 2.0}) ^ (1u << (rand() % 32)), {0.0, 2.0});
    _y = uint_to_range(range_to_uint(_y, {-2.0, 2.0}) ^ (1u << (rand() % 32)), {0.0, 2.0});
}

double uint_to_range(uint u, Range r){
    return r.min + (static_cast<double>(r.max - r.min) * u / UINT32_MAX);
}

uint range_to_uint(double d, Range r){
    return UINT32_MAX * (d - r.min) / (r.max - r.min);
}

bool operator< (const Entity& lhs, const Entity& rhs){
return lhs.fit_func() < rhs.fit_func();
}
