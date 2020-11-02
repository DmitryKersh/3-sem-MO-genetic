//
// Created by dimchik on 02.11.2020.
//

#include "Entity.h"
#include <cmath>

void Entity::cross_over(Entity &other) {
    // cross over
}

double Entity::fit_func() {
    return sin(_x) * sin(_y) * (1 + _x * _x + _y * _y);
}

double Entity::get_x() {
    return _x;
}

double Entity::get_y() {
    return _y;
}