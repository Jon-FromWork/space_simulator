#ifndef STAR_SYSTEM_H

#define STAR_SYSTEM_H

#pragma once
#include <cmath>
#include "vec2.h"
#include "celestial_body.h"
#include "physics.h"
#include "raylib.h"
#include <vector>
#include <iostream>
class star_system
{
public:
    star_system(std::vector <celestial_body> bods,double duration);
    ~star_system();
    void orbit_vel_updater();
    void draw_simulation(float T,vec2 screen_center);

private:
    std::vector <celestial_body> bodies;
    double duration{};

};

#endif