//
// Created by dimchik on 02.11.2020.
//

#ifndef INC_3_SEM_MO_GENETIC_ENTITY_H
#define INC_3_SEM_MO_GENETIC_ENTITY_H


class Entity {
    double _x;
    double _y;
public:
    Entity() : _x(0.0), _y(0.0) {}
    Entity(double x, double y) : _x(x), _y(y) {}

    void exchange_gens(Entity& other);

    double fit_func() const;

    double get_x() const;
    double get_y() const;
};


#endif //INC_3_SEM_MO_GENETIC_ENTITY_H
