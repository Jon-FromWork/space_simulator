#ifndef PHYSICS_H
#define PHYSICS_H
#include<cmath>
#include "vec2.h"
#include "celestial_body.h"
#include <vector>
#pragma once
//calculating the distance between 2 bodies 
float distance(vec2 num1, vec2 num2);
const double G = 6.67430e-11; //6.67430e-11;(real life value)
const float T = 1.0/165;
vec2 gravitational_force_calculation(const celestial_body& body1, const celestial_body& body2);
//calculating net force(all forces) on a single body
vec2 compute_net_force(const celestial_body &target_body,const std::vector <celestial_body> &other_bodies);
vec2 acceleration_vec(vec2 net_force, float mass);










#endif