//
// Created by dimchik on 02.11.2020.
//

#include "Entity.h"
#include <cmath>

void Entity::exchange_gens(Entity &other) {
    // cross over
}

double Entity::fit_func() const {
    return sin(_x) * sin(_y) * (1 + _x * _x + _y * _y);
}

double Entity::get_x() const {
    return _x;
}

double Entity::get_y() const {
    return _y;
}