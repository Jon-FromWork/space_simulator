#ifndef CELESTIAL_BODY_H
#define CELESTIAL_BODY_H

#pragma once

#include "vec2.h"
#include "raylib.h"
struct celestial_body{
    std::string name;
    vec2 position;
    vec2 net_force;
    vec2 velocity;
    float radius;
    float mass;
    Color color;
    void calc_orbit_vel(vec2 star_position, float star_mass, float G);

    celestial_body();
    celestial_body(std::string name,vec2 pos,vec2 vel, float ma,float r,Color color);
    ~celestial_body();
    void print();
    vec2 vel_update(vec2 a_vec, float time );
    vec2 pos_update(float time);
};

#endif