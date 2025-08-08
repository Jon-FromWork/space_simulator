#ifndef VEC2_H
#define VEC2_H

#pragma once

#include <cmath>
#include <iostream>

struct vec2{
    float x{};
    float y{};    
    vec2();
    vec2(float _x,float _y);
    ~vec2();
    void print()const;
    vec2 operator+(const vec2 &other);
    vec2 operator-(const vec2 &other)const;
    vec2 operator*(float multiplier);
    vec2 operator/(float divider);
    bool operator==(const vec2 &other)const;
    bool operator!=(const vec2 &other)const;
    vec2 &operator+=(const vec2 &other);
    vec2 &operator-=(const vec2 &other);
    float length() const;
    vec2 normalize();
    float dot(const vec2 &other) const;
    vec2 perpendicular()const;
};

#endif