//
// Created by dimchik on 02.11.2020.
//

#ifndef INC_3_SEM_MO_GENETIC_ENTITY_H
#define INC_3_SEM_MO_GENETIC_ENTITY_H


class Entity {
    double _x;
    double _y;
public:
    Entity(double x, double y) : _x(x), _y(y) {}

    void cross_over(Entity& other);

    double fit_func();

    double get_x();
    double get_y();
};


#endif //INC_3_SEM_MO_GENETIC_ENTITY_H
