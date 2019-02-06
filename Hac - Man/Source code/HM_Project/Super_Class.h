//
// Created by kab95 on 18.10.2016.
//

#ifndef HM_PROJECT_SUPER_CLASS_H
#define HM_PROJECT_SUPER_CLASS_H
#include <SFML/Graphics.hpp>


class Super_Class {

protected:
    float x;//x kordinatene til et object i spillet
    float y;// y kordinate i spillet
public:
    float getX() ;

    void setX(float x);

    float getY() ;

    void setY(float y);
};


#endif //HM_PROJECT_SUPER_CLASS_H
